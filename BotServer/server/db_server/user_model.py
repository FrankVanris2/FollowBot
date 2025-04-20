from .base_model import BaseModel
from botocore.exceptions import ClientError
from boto3.dynamodb.conditions import Attr

class UserModel(BaseModel):
    def __init__(self):
        super().__init__(
            table_name = 'Users',
            key_schema=[
                {'AttributeName': 'user_id', 'KeyType': 'HASH'}
            ],
            attribute_definitions=[
                {'AttributeName': 'user_id', 'AttributeType': 'S'}
            ]
        )

    def create_user(self, user_id, username, email,
            password, phone_number=None, business_id=None, privacy_consent=False, follow_bots = None):
        try:
            response = self.table.put_item(
                Item={
                    'user_id': user_id,
                    'username': username,
                    'password': password,
                    'email': email,
                    'phone_number': phone_number,
                    'business_id': business_id,
                    'privacy_consent': privacy_consent,
                    'follow_bots': follow_bots if follow_bots else []
                }
            )
            return response
        except ClientError as e:
            print(f"Error creating user: {e}")
            return None

    def get_user(self, user_id):
        try:
            response = self.table.get_item(Key={'user_id': user_id})
            return response.get('Item', None)
        except ClientError as e:
            print(f"Error retrieving user: {e}")
            return None

    def get_user_by_email(self, email):
        try:
            response = self.table.scan(
                FilterExpression=Attr('email').eq(email)
            )
            items = response.get('Items', [])
            return items[0] if items else None
        except ClientError as e:
            print(f"Error scanning for email: {e}")
            return None

    def get_user_by_username(self, username):
        try:
            response = self.table.scan(
                FilterExpression=Attr('username').eq(username)
            )
            items = response.get('Items', [])
            return items[0] if items else None
        except ClientError as e:
            print(f"Error retrieving user: {e}")
            return None

    def delete_user(self, user_id):
        try:
            response = self.table.delete_item(Key={'user_id': user_id})
            return response
        except ClientError as e:
            print(f"Error deleting user: {e}")
            return None

    def add_bot(self, user_id, bot_id):
        try:
            response = self.table.update_item(
                Key={'user_id': user_id},
                UpdateExpression="SET follow_bots = list_append(if_not_exists(follow_bots, :empty_list), :bot_id)",
                ConditionExpression="not contains(follow_bots, :bot_id)",
                ExpressionAttributeValues={
                    ':empty_list': [],
                    ':bot_id': [bot_id]
                },
                ReturnValues="UPDATED_NEW"
            )
            return response
        except ClientError as e:
            print(f"Error appending FollowBot to User's attributes: {e}")
            return None
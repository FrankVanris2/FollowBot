from .base_model import BaseModel
from botocore.exceptions import ClientError

class FollowBotModel(BaseModel):
    def __init__(self):
        super().__init__(
            table_name='FollowBots',
            key_schema=[
                {'AttributeName': 'bot_id', 'KeyType': 'HASH'}
            ],
            attribute_definitions=[
                {'AttributeName': 'bot_id', 'AttributeType': 'S'}
            ]
        )

    def create_follow_bot(self, bot_id, functional_key, logs, business_id=None, assigned_user_id=None):
        try:
            response = self.table.put_item(
                Item={
                    'bot_id': bot_id,
                    'functional_key': functional_key,
                    'logs': logs,
                    'business_id': business_id,
                    'assigned_user_id': assigned_user_id
                }
            )
            return response
        except ClientError as e:
            print(f"Error creating the FollowBot entry: {e}")
            return None

    def get_follow_bot(self, bot_id):
        try:
            response = self.table.get_item(Key={'bot_id': bot_id})
            return response.get('Item', None)
        except ClientError as e:
            print(f"Error retrieving the FollowBot entry: {e}")
            return None

    def update_follow_bot_logs(self, bot_id, new_log):
        try:
            response = self.table.update_item(
                Key={'bot_id': bot_id},
                UpdateExpression="SET logs = list_append(if_not_exists(logs, :empty_list), :new_log)",
                ExpressionAttributeValues={
                    ':new_log': [new_log],
                    ':empty_list': []
                },
                ReturnValues="UPDATED_NEW"
            )
            return response
        except ClientError as e:
            print(f"Error updating logs: {e}")
            return None

    def assign_user_to_bot(self, bot_id, user_id):
        try:
            response = self.table.update_item(
                Key={'bot_id': bot_id},
                UpdateExpression="SET assigned_user_id =:user_id",
                ExpressionAttributeValues={
                    ':user_id': user_id
                },
                ReturnValues="UPDATED_NEW"
            )
            return response
        except ClientError as e:
            print(f"Error assigning the bot to the user: {e}")
            return None
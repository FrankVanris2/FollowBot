from .base_model import BaseModel
from botocore.exceptions import ClientError

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

    def create_user(self, user_id, username, password, email, phone_number=None, business_id=None, privacy_consent=False):
        try:
            response = self.table.put_item(
                Item={
                    'user_id': user_id,
                    'username': username,
                    'password': password,  # encrypt/hash this
                    'email': email,
                    'phone_number': phone_number,
                    'business_id': business_id,
                    'privacy_consent': privacy_consent
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

    def delete_user(self, user_id):
        try:
            response = self.table.delete_item(Key={'user_id': user_id})
            return response
        except ClientError as e:
            print(f"Error deleting user: {e}")
            return None
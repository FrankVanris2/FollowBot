from base_model import BaseModel
from botocore.exceptions import ClientError

class BusinessModel(BaseModel):
    def __init__(self):
        super().__init__('Businesses')

    def create_business(self, business_id, business_name, address, keys):
        try:
            response = self.table.put_item(
                Item={
                    'business_id': business_id,
                    'name': business_name,
                    'address': address,
                    'bot_access_keys': keys
                }
            )
            return response
        except ClientError as e:
            print(f"Error creating the business entry: {e}")
            return None
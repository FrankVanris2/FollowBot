from .db_resource import dynamodb
from botocore.exceptions import ClientError

class BaseModel:
    def __init__(self, table_name, key_schema, attribute_definitions):
        self.dynamodb = dynamodb
        self.table_name = table_name
        self.key_schema = key_schema
        self.attribute_definitions = attribute_definitions
        self.table = self.get_or_create_table()

    def get_or_create_table(self):
        try:
            table = self.dynamodb.Table(self.table_name)
            table.load()
            print(f"Table '{self.table_name}' exists.")
            return table
        except ClientError as e:
            if e.response['Error']['Code'] == 'ResourceNotFoundException':
                print(f"Table '{self.table_name} does not exist. Creating it...'")
                return self.create_table()
            else:
                print(f"Unexpect error: {e}")
                raise e

    def create_table(self):
        try:
            table = self.dynamodb.create_table(
                TableName=self.table_name,
                KeySchema=self.key_schema,
                AttributeDefinitions=self.attribute_definitions,
                ProvisionedThroughput={
                    'ReadCapacityUnits': 5,
                    'WriteCapacityUnits': 5
                }
            )
            table.wait_until_exists()
            print(f"Table '{self.table_name}' created successfully.")
            return table
        except ClientError as e:
            print(f"Error creating table '{self.table_name}': {e}")
            raise e

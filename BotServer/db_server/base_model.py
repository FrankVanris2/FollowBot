from db_resource import dynamodb

class BaseModel:
    def __init__(self, table_name):
        self.dynamodb = dynamodb
        self.table = self.dynamodb.Table(table_name)
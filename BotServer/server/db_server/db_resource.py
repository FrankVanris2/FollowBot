import boto3
from .settings import AWS_DYNAMODB

dynamodb = boto3.resource(
    'dynamodb',
    region_name=AWS_DYNAMODB['default']['AWS_REGION'],
    aws_access_key_id=AWS_DYNAMODB['default']['AWS_ACCESS_KEY_ID'],
    aws_secret_access_key=AWS_DYNAMODB['default']['AWS_SECRET_ACCESS_KEY'],
    endpoint_url="http://localhost:8000/" # local db for testing
)
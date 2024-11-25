import boto3
import settings

dynamodb = boto3.resource(
    'dynamodb',
    region_name=settings.AWS_DYNAMODB['REGION_NAME'],
    aws_access_key_id=settings.AWS_DYNAMODB['ACCESS_KEY'],
    aws_secret_access_key=settings.AWS_DYNAMODB['SECRET_KEY']
)
#TODO: set up AWS, credential file kept locally?

AWS_DYNAMODB = {
    'default': {
        'ENGINE': 'django_dynamodb_engine',
        'NAME': 'database_name',
        'AWS_ACCESS_KEY_ID': 'dummy',
        'AWS_SECRET_ACCESS_KEY': 'dummy',
        'AWS_REGION': 'us-east-2',
    }
}
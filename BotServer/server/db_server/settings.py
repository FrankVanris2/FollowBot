#TODO: set up AWS, credential file kept locally?

AWS_DYNAMODB = {
    'default': {
        'ENGINE': 'django_dynamodb_engine',
        'NAME': 'database_name',
        'AWS_ACCESS_KEY_ID': 'access_key_id',
        'AWS_SECRET_ACCESS_KEY': 'secret_access_key',
        'AWS_REGION': 'region',
    }
}
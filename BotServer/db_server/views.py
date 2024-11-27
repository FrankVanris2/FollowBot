from django.shortcuts import render
from django.http import JsonResponse
from user_model import UserModel
import uuid
import hashlib

user_model = UserModel()

def register_user(request):
    if request.method == 'POST':
        data = request.POST
        username = data['username']
        password = hashlib.sha256(data['password'].encode()).hexdigest()
        email = data['email']
        phone_number = data.get('phone_number', None)
        business_id = data.get('business_id', None)

        if not username or not password or not email:
            return JsonResponse({'error': 'Missing required fields'}, status=400)

        user_id = str(uuid.uuid4())

        response = user_model.create_user(
            user_id=user_id,
            username=username,
            password=password,
            email=email,
            phone_number=phone_number,
            business_id=business_id
        )

        if response is None:
            return JsonResponse({'error': 'Failed to register user'}, status=500)

        return JsonResponse({'message': 'User registered successfully', 'user_id': user_id})

    # TODO: Render registration form for GET requests
    return render(request, 'register.html')

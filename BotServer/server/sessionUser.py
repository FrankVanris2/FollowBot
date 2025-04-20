from flask_login import UserMixin

# TODO: session use of FollowBot
# class FollowBot:
#     def __init__(self, bot_id, name, logs, status):
#         self.bot_id = bot_id
#         self.name = name
#         self.logs = logs
#         self.status = status  # e.g., 'active', 'offline'


class SessionUser(UserMixin):
    def __init__(self, user_id, username, email,
            password, phone_number=None, business_id=None, privacy_consent=False, follow_bots=None):
        self.id = user_id
        self.username = username
        self.email = email
        self.password = password  # keep it but never return it
        self.phone_number = phone_number
        self.business_id = business_id
        self.privacy_consent = privacy_consent
        self.follow_bots = follow_bots if follow_bots else []


    def to_dict(self):
        return {
            "user_id": self.id,
            "username": self.username,
            "email": self.email,
            "phone_number": self.phone_number,
            "business_id": self.business_id,
            "privacy_consent": self.privacy_consent,
            "follow_bots": self.follow_bots
        }
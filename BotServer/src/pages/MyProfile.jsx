import React from 'react';
import { useNavigate } from 'react-router-dom';
import "../styles/MyProfile.style.css";

const MyProfilePage = () => {
  const navigate = useNavigate();

  return (
    <div>
      <h1>My Profile</h1>
      <p>Welcome to your profile page.</p>

      <div className="profile-options">
        <div onClick={() => navigate('/analytics')} className="profile-item">
          <img src="/images/analytics.png" alt="User Analytics" />
          <p>User Analytics & FollowBot Usage</p>
        </div>

        <div onClick={() => navigate('/robotic-controls')} className="profile-item">
          <img src="/images/robotic-controls.png" alt="Robotic Controls" />
          <p>Robotic Controls</p>
        </div>

        <div onClick={() => navigate('/mapping')} className="profile-item">
          <img src="/images/mapping.png" alt="Mapping/Location" />
          <p>Mapping/Location</p>
        </div>

        <div onClick={() => navigate('/account')} className="profile-item">
          <img src="/images/account.png" alt="My Account" />
          <p>My Account</p>
        </div>

        <div onClick={() => navigate('/signal')} className="profile-item">
          <img src="/images/signal.png" alt="Signal" />
          <p>Signal</p>
        </div>

        <div onClick={() => navigate('/live-feed')} className="profile-item">
          <img src="/images/live-feed.png" alt="Live Feed" />
          <p>Live Feed</p>
        </div>
      </div>
    </div>
  );
};

export default MyProfilePage;

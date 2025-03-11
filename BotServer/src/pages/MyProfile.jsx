import React from "react";
import { useNavigate } from "react-router-dom";
import "../styles/MyProfile.style.css"; 
const MyProfilePage = () => {
  const navigate = useNavigate();

  return (
    <div className="profile-container">
      <h1>My Profile</h1>
      <p>Welcome to your profile page.</p>

      <div className="profile-options">
        <div onClick={() => navigate('/user-analytics')} className="profile-item">
          <p>User Analytics & FollowBot Usage</p>
        </div>
        <div onClick={() => navigate('/my-bots')} className="profile-item">
          <p>My FollowBots</p>
        </div>
        <div onClick={() => navigate('/followbot-controls')} className="profile-item">
          <p>FollowBot Controls</p>
        </div>
        <div onClick={() => navigate('/mapping')} className="profile-item">
          <p>Mapping/Location</p>
        </div>
        <div onClick={() => navigate('/my-account')} className="profile-item">
          <p>My Account</p>
        </div>
        <div onClick={() => navigate('/signal')} className="profile-item">
          <p>Signal</p>
        </div>
        <div onClick={() => navigate('/live-feed')} className="profile-item">
          <p>Live Feed</p>
        </div>
      </div>
    </div>
  );
};

export default MyProfilePage;

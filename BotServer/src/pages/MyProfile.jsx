import React from "react";
import { useNavigate } from "react-router-dom";
import "../styles/MyProfile.style.css"; 

import FollowBotControls from '../res/FollowBot_controls.png';
import LiveFeed from '../res/Livefeed.png';
import MappingLocation from '../res/mapping&Location.png';
import MyAccount from '../res/MyAccount.png';
import signal from '../res/signal.png';
import UserAnalyticsFollowBotUsage from '../res/UserAnalytics&FollowBotUsage.png';

const MyProfilePage = () => {
  const navigate = useNavigate();

  return (
    <div className="profile-container">
      <h1>My Profile</h1>
      <p>Welcome to your profile page.</p>

      <div className="profile-options">
        <div onClick={() => navigate('/user-analytics')} className="profile-item">
          <img src={UserAnalyticsFollowBotUsage} alt="User Analytics" />
          <p>User Analytics & FollowBot Usage</p>
        </div>
        <div onClick={() => navigate('/my-bots')} className="profile-item">
          <p>My FollowBots</p>
        </div>
        <div onClick={() => navigate('/followbot-controls')} className="profile-item">
          <img src={FollowBotControls} alt="FollowBot Controls" />
          <p>FollowBot Controls</p>
        </div>
        <div onClick={() => navigate('/mapping')} className="profile-item">
          <img src={MappingLocation} alt="Mapping/Location" />
          <p>Mapping/Location</p>
        </div>
        <div onClick={() => navigate('/my-account')} className="profile-item">
          <img src={MyAccount} alt="My Account" />
          <p>My Account</p>
        </div>
        <div onClick={() => navigate('/signal')} className="profile-item">
          <img src={signal} alt="Signal" />
          <p>Signal</p>
        </div>
        <div onClick={() => navigate('/live-feed')} className="profile-item">
          <img src={LiveFeed} alt="Live Feed" />
          <p>Live Feed</p>
        </div>
      </div>
    </div>
  );
};

export default MyProfilePage;

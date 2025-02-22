import React from "react";
import "../styles/AboutAppPage.style.css"; // Import the CSS file
import mobileImage from "../res/phoneImage.png";

const AboutAppPage = () => {
  return (
    <div className="about-app-page-container">
      <main className="content">
        <div className="mobile-app-info">
          <h1 className="mobile-app-info-heading">Mobile App</h1>
          <p className="mobile-app-info-text">
            When you purchase a FollowBot, a mobile app is included. To access
            the full range of features and commands for your FollowBot,
            download the FollowBotApp from the app store.
          </p>
        </div>
        <div className="mobile-preview">
          <img className="phone-image" src={mobileImage} alt="Mobile App Preview" />
        </div>
      </main>
    </div>
  );
};

export default AboutAppPage;

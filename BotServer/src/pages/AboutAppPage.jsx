import React from "react";
import "../styles/AboutAppPage.css";

const AboutAppPage = () => {
  return (
    <div className="about-app-page">
      
      <main className="content">
        <div className="mobile-app-info">
          <h1>Mobile App</h1>
          <p>
            When you purchase a FollowBot, a mobile app is included. To access
            the full range of features and commands for your FollowBot,
            download the FollowBotApp from the app store.
          </p>
        </div>
        {/* <div className="mobile-preview">
          <img
            src="phone-placeholder.png"
            alt="FollowBot App Preview"
            className="phone-image"
          />
        </div>  */}
      </main>
    </div>
  );
};

export default AboutAppPage;

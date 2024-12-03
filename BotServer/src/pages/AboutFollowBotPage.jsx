import React from "react";
import "../styles/AboutFollowBotPage.css";

const AboutFollowBotPage = () => {
  return (
    <div className="about-follow-bot-page">
      

      <main className="content">
        <section className="follow-bot-info">
          <h1>About FollowBot</h1>
          <p>
            FollowBot is a robot designed to assist individuals by carrying and
            transporting their belongings from one location to another. It
            features capabilities like mapping, following, error correction,
            path-finding, modular modifications, and much more.
          </p>
        </section>

        <section className="mobile-app-info">
          <h2>Mobile App</h2>
          <p>
            When you purchase a FollowBot, a mobile app is included. To access
            the full range of features and commands for your FollowBot, download
            the FollowBotApp from the app store.
          </p>
        </section>

        {/* 
        <div className="image-preview">
          <img
            src="placeholder.png"
            alt="Placeholder for FollowBot Image"
            className="bot-image"
          />
        </div>
        */}
      </main>
    </div>
  );
};

export default AboutFollowBotPage;

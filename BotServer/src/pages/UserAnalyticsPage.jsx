import React from "react";
import "./style.css";

const UserAnalytics = () => {
  return (
    <div className="container">
      <h1 className="title">User Analytics & FollowBot Usage</h1>
      <div className="content">
        <div className="analytics-section">
          <img
            src="image.png"
            alt="Data Analytics"
            className="analytics-image"
          />
          <p className="label">Data Analytics</p>
        </div>

        {/* TEMPORARY SECTION: Placeholder for FollowBot Usage, expand later */}
        <div className="usage-section">
          <img
            src="followbot-usage.png"
            alt="FollowBot Usage"
            className="usage-image"
          />
          <p className="label">FollowBot Usage</p>
        </div>
        {/* END TEMPORARY SECTION */}

      </div>
      <button className="back-button">Back</button>
    </div>
  );
};

export default UserAnalytics;
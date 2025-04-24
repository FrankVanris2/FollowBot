import React from "react";
import "../styles/SettingPage.Style.css";
import { useNavigate } from "react-router-dom"; // Import useNavigate
import { FaMoon, FaSun, FaLock, FaBook } from "react-icons/fa"; // Import icons

const Settings = () => {
  const navigate = useNavigate(); // Initialize the navigate function

  return (
    <div className="settings-container">
      <h1 className="settings-title">Settings</h1>
      <div className="settings-options">
        <div className="setting-item">
          <div className="mode-toggle">
            <FaMoon className="icon moon" />
            <FaSun className="icon sun" />
          </div>
          <span>Lightmode/Darkmode</span>
        </div>
        <div className="setting-item">
          <input type="checkbox" id="email-notifications" />
          <label htmlFor="email-notifications">Email Notifications</label>
        </div>
        <div className="setting-item">
          <input type="checkbox" id="message-notifications" />
          <label htmlFor="message-notifications">Message Notifications</label>
        </div>
        <div className="setting-item">
          <FaLock className="icon" />
          <span>Privacy and data</span>
        </div>
        <div className="setting-item">
          <FaBook className="icon" />
          <span>Rules</span>
        </div>
      </div>
      {/* Back Button */}
      <button className="back-button" onClick={() => navigate("/my-profile")}>
        Back to Profile
      </button>
    </div>
  );
};

export default Settings;
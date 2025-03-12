import React from "react";
import { useNavigate } from "react-router-dom"; // Import useNavigate
import "../styles/MyAccountPage.style.css"; // Ensure this path is correct
import FollowBotsList from "../components/FollowBotsList"; // Ensure the import path is correct

const AccountPage = () => {
  const navigate = useNavigate(); // Initialize the navigate function

  const handleBackClick = () => {
    console.log("Back button clicked"); // Debugging
    navigate("/my-profile"); // Navigate to /my-profile
  };

  return (
    <div className="flex flex-col p-6 bg-gray-300 min-h-screen">
      <h1 className="text-2xl font-bold">My Account</h1>
      <div className="mt-4">
        <ul className="space-y-2">
          <li className="flex items-center space-x-2">
            <span>🔒</span>
            <span>Privacy and Data</span>
          </li>
          <li className="flex items-center space-x-2">
            <span>👤</span>
            <span>Delete Account</span>
          </li>
          <li className="flex items-center space-x-2">
            <span>⚙️</span>
            <span>Settings</span>
          </li>
        </ul>
      </div>

      <FollowBotsList />

      {/* Back Button */}
      <button className="back-button" onClick={handleBackClick}>
        Back to Profile
      </button>
    </div>
  );
};

export default AccountPage;
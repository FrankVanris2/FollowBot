import React from "react";
import { useNavigate } from "react-router-dom"; // Import useNavigate
import "../styles/RulesPage.style.css";

const Rules = () => {
  const navigate = useNavigate(); // Initialize the navigate function

  return (
    <div className="rules-container">
      <h2 className="rules-title">CarryWithMe User Guidelines and Rules</h2>
      
      <h3>1. Account Access</h3>
      <p>1.1. Users must create an account to access the features of CarryWithMe.</p>
      <p>1.2. You are solely responsible for maintaining the confidentiality of your login credentials.</p>
      <p>1.3. Sharing your account details with others is prohibited.</p>
      
      <h3>2. Robot Ownership and Authentication</h3>
      <p>2.1. To claim a robot on the platform, you must provide its unique private key.</p>
      <p>2.2. The private key is strictly confidential; never share it with anyone.</p>
      <p>2.3. Only one user may have active access to a specific robot at a time.</p>
      <p>2.4. You may not attempt to access any robot that is not tied to your private key.</p>
      
      <h3>3. Security and Data Integrity</h3>
      <p>3.1. Users must not engage in any activity that compromises the security of the website or the robots.</p>
      <p>3.2. Tampering, reverse-engineering, or unauthorized modification of software related to the robot or website is prohibited.</p>
      <p>3.3. All actions performed while signed into the platform are logged for security and auditing purposes.</p>
      
      <h3>4. Respectful Usage</h3>
      <p>4.1. Use the platform and your robots responsibly and ethically.</p>
      <p>4.2. CarryWithMe is not liable for misuse of robots, including damage, harm, or unauthorized operations.</p>
      <p>4.3. Users must adhere to all local, state, and federal laws when operating their robots.</p>
      
      <h3>5. Content and Intellectual Property</h3>
      <p>5.1. All website content, including software and documentation, is the intellectual property of CarryWithMe.</p>
      <p>5.2. Users may not copy, distribute, or create derivative works from the platform without explicit permission.</p>
      
      <h3>6. Account Termination</h3>
      <p>6.1. Violation of any of these rules may result in suspension or termination of your account.</p>
      <p>6.2. CarryWithMe reserves the right to revoke access to the platform at its discretion.</p>
      
      <h3>7. Support and Dispute Resolution</h3>
      <p>7.1. For technical issues or disputes, users can contact CarryWithMe Support via the Help Center.</p>
      <p>7.2. Decisions made by CarryWithMe Support regarding account or robot access are final.</p>
      
      <h3>8. Privacy and Data Usage</h3>
      <p>8.1. User data is handled in accordance with our Privacy Policy.</p>
      <p>8.2. Users agree to the collection and processing of necessary information for account and robot management.</p>
      
      {/* Back Button */}
      <button className="back-button" onClick={() => navigate("/my-profile")}>
        Back to Profile
      </button>
    </div>
  );
};

export default Rules;
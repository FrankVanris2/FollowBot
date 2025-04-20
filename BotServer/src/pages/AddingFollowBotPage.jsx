import { useState } from "react";
import "../styles/AddFollowBots.css"; // Import the CSS file

const AddFollowBots = () => {
  const [privateKey, setPrivateKey] = useState("");
  const [followBots, setFollowBots] = useState([]);

  const handleAddBot = () => {
    if (privateKey.trim()) {
      setFollowBots([...followBots, privateKey]);
      setPrivateKey("");
    }
  };

  return (
    <div className="container">
      <nav className="nav-bar">
        <button>FollowBot</button>
        <button>About Mobile App</button>
        <button>About Us</button>
        <button>Feedback</button>
        <button>News</button>
      </nav>

      <main className="content">
        <section className="add-section">
          <h2>Add FollowBots</h2>
          <p>If you own a FollowBot, input their private key below:</p>
          <label>
            FollowBot Private Key:
            <input
              type="text"
              value={privateKey}
              onChange={(e) => setPrivateKey(e.target.value)}
            />
          </label>
          <button onClick={handleAddBot}>Add</button>
        </section>

        <section className="list-section">
          <h3>My FollowBots:</h3>
          <ul>
            {followBots.map((bot, index) => (
              <li key={index}>{bot}</li>
            ))}
          </ul>
        </section>
      </main>
    </div>
  );
};

export default AddFollowBots;
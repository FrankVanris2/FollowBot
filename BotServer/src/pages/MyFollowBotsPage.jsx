import React from 'react';
import { useState, useEffect } from 'react';
import { useNavigate } from 'react-router-dom';
import api from '../services/api';

const AddFollowBots = () => {
    const navigate = useNavigate();
    const [botId, setBotId] = useState("");
    const [functionalKey, setFunctionalKey] = useState("");
    const [followBots, setFollowBots] = useState([]);
    const [responseMessage, setResponseMessage] = useState("");
    const [botExists, setBotExists] = useState(false);
    const [pendingBotId, setPendingBotId] = useState(null);

    useEffect(() => {
        const fetchFollowBots = async () => {
            try {
                const response = await fetch("/api/getUserBots", {
                    method: "GET",
                    headers: { "Content-Type": "application/json" }
                });

                const data = await response.json();

                if (response.ok)
                    setFollowBots(data.follow_bots || []);
                else
                    console.error("Failed to fetch FollowBots:", data.error);

            } catch (error) {
                console.error("Error fetching FollowBots:", error);
            }
        };

        fetchFollowBots();
    }, []);

    const handleAnalyzeBot = (botId) => {
        navigate(`/bot-analytics/${botId}`);
    };

    const handleCheckBot = async () => {
        if (botId.trim()) {
            try {
                const response = await fetch("/api/getBot", {
                    method: "POST",
                    headers: { "Content-Type": "application/json" },
                    body: JSON.stringify({ bot_id: botId })
                });

                const data = await response.json();

                if (response.ok) {
                    setResponseMessage(data.message);
                    setBotExists(true);
                    setPendingBotId(botId);
                } else {
                    setResponseMessage(data.error || "Error verifying FollowBot.");
                    setBotExists(false);
                    setPendingBotId(null);
                }
            } catch (error) {
                console.error("Error fetching bot:", error);
                setResponseMessage("Network error occurred.");
                setBotExists(false);
                setPendingBotId(null);
            }
            setBotId(""); // clear after processing
        }
    };

    const handleLinkBot = async () => {
        if (pendingBotId && functionalKey.trim()) {
            try {
                const response = await fetch("/api/linkBot", {
                    method: "POST",
                    headers: { "Content-Type": "application/json" },
                    body: JSON.stringify({
                        bot_id: pendingBotId,
                        functional_key: functionalKey,
                    })
                });
                const data = await response.json();
                if (response.ok) {
                    setResponseMessage(data.message || "Bot linked successfully.");
                    setFollowBots([...followBots, pendingBotId]);
                    setBotExists(false);
                    setPendingBotId(null);
                    setFunctionalKey("");
                } else {
                    setResponseMessage(data.error || "Linking failed. Please check your functional key.");
                }
            } catch (error) {
                console.error("Error linking bot:", error);
                setResponseMessage("Network error occurred during linking.");
            }
        }
    };

    return (
        <main className="content">
            <section className="add-section">
                <h2>Add FollowBots</h2>
                <p>If you own a FollowBot, input its bot ID below:</p>
                <label>
                    FollowBot General Key:
                    <input
                        type="text"
                        value={botId}
                        onChange={(e) => setBotId(e.target.value)}
                    />
                </label>
                <button onClick={handleCheckBot}>Get Bot</button>

                {botExists && (
                    <div>
                        <label>
                            Enter Functional Key:
                            <input
                                type="text"
                                value={functionalKey}
                                onChange={(e) => setFunctionalKey(e.target.value)}
                            />
                        </label>
                        <button onClick={handleLinkBot}>Link Bot</button>
                    </div>
                )}

                {responseMessage && <p>{responseMessage}</p>}
            </section>

            <section className="list-section">
                <h3>My FollowBots:</h3>
                <ul>
                    {followBots.map((botId, index) => (
                        <li key={index}>
                            {botId}
                            <button onClick={() => handleAnalyzeBot(botId)}>Analyze</button>
                        </li>
                    ))}
                </ul>
            </section>
        </main>
    )
};

export default AddFollowBots;
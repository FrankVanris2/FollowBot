import React from 'react';
import { useEffect, useState } from 'react';
import { useParams } from 'react-router-dom';

const BotAnalytics = () => {
    const { botId } = useParams();
    const [logs, setLogs] = useState([])

    useEffect(() => {
        const fetchBotLogs = async () => {
            try {
                const response = await fetch(`/api/getBotLogs?bot_id=${botId}`, {
                    method: "GET",
                    headers: { "Content-Type": "application/json" }
                });

                const data = await response.json();
                console.log("API response:", data);
                console.log("First log:", data.logs[0]);

                if (response.ok) {
                    setLogs((prevLogs) => [...data.logs]);
                } else {
                    console.error("Failed to fetch logs:", data.error);
                }
            } catch (error) {
                console.error("Error fetching logs:", error);
            }
        };

        fetchBotLogs();
    }, [botId]);

    return (
        <main className="content">
            <h2>Analytics for Bot: {botId}</h2>
            {logs.length > 0 ? (
                <ul>
                    {logs.map((log, index) => (
                        <li key={index}>
                            <p><strong>Time:</strong> {log.time}</p>
                            <p><strong>Date:</strong> {log.date}</p>
                            <p><strong>Temperature:</strong> {log.temperature}°C</p>
                            <p><strong>Battery:</strong> {log.battery}%</p>
                            <p><strong>Last Location:</strong> ({log.last_location[0]}, {log.last_location[1]})</p>
                            <hr />
                        </li>
                    ))}
                </ul>
            ) : (
                <p>No logs available for this bot.</p>
            )}
        </main>
    );
}

export default BotAnalytics;
import React, {useEffect, useState} from 'react';
import axios from 'axios';

const NewsArticlePage = () => {
    const [articles, setArticles] = useState([]);
    const [loading, setLoading] = useState(true);
    const [error, setError] = useState(null);
    const [currentTopic, setCurrentTopic] = useState("Technology")

    const topics = ["Technology", "AI", "Robotics"];


    const fetchArticlesByTopic = async (topic) => {
        try {
            const response = await axios.get("https://newsapi.org/v2/everything", {
                params: {
                    q: topic,
                    apiKey: "6e1c548a0ead49b8a35c3769df65a410" // hide this
                },
            });
            setArticles(response.data.articles);
        } catch (err) {
            console.error("Error fetching articles: ", err)
            setError(`Failed to fetch articles. Error: ${err.message}`);
        } finally {
            setLoading(false);
        }
    };

    useEffect(() => {
        fetchArticlesByTopic(currentTopic)
            .then((articles) => console.log(articles))
            .catch((error) => console.error("Error fetching articles: ", error));
    }, [currentTopic]);

    const flexStyle = {
        display: "flex",
        flexWrap: "wrap",
        gap: "20px",
        justifyContent: "center",
        padding: "20px",
    };

    const imageStyle = {
        width: "100px",
        height: "100px",
        borderRadius: "50%",
        objectFit: "cover",
        marginBottom: "10px",
    };

    const cardStyle = {
        width: "300px",
        border: "1px solid #ccc",
        borderRadius: "8px",
        boxShadow: "0 4px 8px rgba(0, 0, 0, 0.1)",
        overflow: "hidden",
        backgroundColor: "#fff",
    };

    const contentStyle = {
        padding: "15px",
        textAlign: "center",
    };

    const linkStyle = {
        textDecoration: "none",
        color: "#007BFF",
        fontWeight: "bold",
    };

    return (
        <div className="container">
            <h1>Relevant News Articles</h1>

            <div>
                {topics.map((topic, index) => (
                    <button
                        key={index}
                        onClick={() => setCurrentTopic(topic)}
                    >
                        {topic}
                    </button>
                ))}
            </div>

            {loading && <p>Loading articles...</p>}
            {error && <p>{error}</p>}

            <div style={flexStyle}>
                {!loading && !error && articles
                    .filter((article) => {
                        return (article.source.id != null);
                    })
                    .map((article, index) => (
                        <div key={index} style={cardStyle}>
                            <img
                                src={article.urlToImage}
                                alt={article.title || "Article image"}
                                style={imageStyle}
                            />
                            <div style={contentStyle}>
                                <h3>{article.title}</h3>
                                <p>{article.description || "No description available"}</p>
                                <a
                                    href={article.url}
                                    target="_blank"
                                    rel="noopener noreferrer"
                                    style={linkStyle}
                                >
                                    Read More
                                </a>
                            </div>
                        </div>
                    ))}
            </div>

        </div>

    );
};

export default NewsArticlePage;
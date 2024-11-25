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
                    apiKEY: "6e1c548a0ead49b8a35c3769df65a410" // hide this somehow
                },
            });
            setArticles(response.data.articles);
        } catch (err) {
            setError("Failed to fetch articles. Please try again.");
        } finally {
            setLoading(false);
        }
    };

    useEffect(() => {
        fetchArticlesByTopic(currentTopic)
            .then((articles) => console.log(articles))
            .catch((error) => console.error("Error fetching articles: ", error));
    }, []);

    const flexStyle = {
      display: "flex",
      flexWrap: "wrap",
      gap: "20px",
    };

    return (
        <div className="container">
            <h1>Relevant News Articles</h1>

            <div>
                {topics.map((topic, index) => (
                    <button
                        key={index}
                        onClick={() => fetchArticlesByTopic(topic)}
                    >
                        {topic}
                    </button>
                ))}
            </div>

            {loading && <p>Loading articles...</p>}
            {error && <p>{error}</p>}

            <div style={flexStyle}>
                {!loading && !error && articles.map((article, index) => (
                    <div key={index}>
                        <h3>{article.title}</h3>
                        <p>{article.description || "No description available"}</p>
                        <a
                            href={article.url}
                            target="_blank"
                            rel="noopener noreferrer"
                        >
                            Read More
                        </a>
                    </div>
                ))}
            </div>

        </div>

    );
};

export default NewsArticlePage;
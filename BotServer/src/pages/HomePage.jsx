// src/pages/HomePage.js
import React from 'react';
import { Link } from 'react-router-dom';
import '../styles/HomePage.style.css';
import prototype from '../res/FollowBotPrototype.png';
import 'bootstrap/dist/css/bootstrap.min.css';

const HomePage = () => {
    return (
        <div className="home-page-container">
            <h1 className="header">FollowBot</h1>
            <div className="main-content">
                <div className="content-box">
                    <img
                        src={prototype}
                        alt="FollowBot Prototype"
                        className="followbot-image"
                    />
                    <div className="text-content">
                        <p className="description">
                            A device that will be able to carry your belongings as well as map through
                            different locations. It is there to help the disadvantaged and is meant to be
                            used in safe public spaces.
                        </p>
                        <p className="extra-info">
                            It is there to help you when you are in need. It will always be by your side.
                        </p>
                        <Link to="/about-followbot" className="learn-more">
                            <span className="arrow">→</span> Learn More
                        </Link>
                    </div>
                </div>
                <div className="video-box-container">
                    <div className="video-box" style={{ width: '100%', position: 'relative', paddingBottom: '56.25%' }}>
                    <iframe
    style={{ position: 'absolute', top: 0, left: 0, width: '100%', height: '100%' }}
    src="https://www.youtube.com/embed/VBmE77GVLnA"
    title="YouTube video"
    allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture"
    allowFullScreen
></iframe>

                    </div>
                    <p className="video-description">
                        This is a demonstration of the FollowBot in action.
                    </p>
                </div>
            </div>
        </div>
    );
};

export default HomePage;

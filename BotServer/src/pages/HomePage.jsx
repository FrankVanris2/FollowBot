import React from 'react';
import '../styles/HomePage.style.css'; 
import prototype from '../res/FollowBotPrototype.png';
import { Link } from 'react-router-dom';

const HomePage = () => {
    return (
        <div className="home-page-container">
            <div className="content-box">
                <img 
                    src={prototype} 
                    alt="FollowBot Prototype" 
                    className="followbot-image" 
                />
                <div className="text-content">
                    <h1 className="title">FollowBot</h1>
                    <p className="description">
                        A device that will be able to carry your belongings as well as map through
                        different locations. It is there to help the disadvantaged and is meant to be
                        used in safe public spaces.
                    </p>
                    <p className="extra-info">
                        It is there to help you when you are in need. It will always be by your side.
                    </p>
                    <Link to="/AboutFollowBotPage" className="learn-more">
                        <span className="arrow">→</span> Learn More
                    </Link>
                </div>
            </div>
            <div className="video-box-container">
                <div className="video-box">
                    <div className="video-placeholder">
                        Video of FollowBot
                    </div>
                </div>
                <p className="video-description">
                    This is a demonstration of the FollowBot in action.
                </p>
            </div>
        </div>
    );
};

export default HomePage;
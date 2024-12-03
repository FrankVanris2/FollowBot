import React from 'react';
import '../styles/HomePageStyle.css'; // Import CSS file

const HomePage = () => {
    return (
        <div className="homepage-container">
            <div className="content-box">
                <div className="followbot-image-placeholder">
                    {/* Placeholder for image */}
                    <p>Image Not Available</p>
                </div>
                <div className="text-content">
                    <h1 className="title">FollowBot</h1>
                    <p className="description">
                        A device that will be able to carry your belongings as well as map through
                        different locations.
                    </p>
                    <p className="extra-info">
                        It is there to help you when you are in need. It will always be by your side.
                    </p>
                    <a href="#learn-more" className="learn-more">
                        {/* needs to add link to aboutfollowbot*/}
                        <span className="arrow">→</span> Learn More
                    </a>
                </div>
            </div>
            <div className="video-box">
                <div className="video-placeholder">
                    <p>Witness the power of FollowBot</p>
                </div>
            </div>
        </div>
    );
};

export default HomePage;

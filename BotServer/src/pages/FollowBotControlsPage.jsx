// src/pages/MoveControlsPage.js
import React from 'react';
import { BrowserRouter as Router, Route} from 'react-router-dom';
import MoveAroundButtons from '../components/MoveAroundButtons'; // Move Around Buttons component
import TemperatureDisplay from '../components/TemperatureDisplay'; // Temperature Display component
import HeatIndexDisplay from '../components/HeatIndexDisplay';     // Heat Index Display component (if applicable)
import cameradisconnected from './res/cameradisconnected.jpg';
const FollowBotControlsPage = () => {
    return (
        <div>
            <h1>Move Controls</h1>
            <div style={containerStyle}>
            <MoveAroundButtons/>
            <img style={imageStyle}
                 src={cameradisconnected}
                 alt="Camera disconnected"
                 className="camera-disconnected-img"
            />
            </div>
        </div>
    );
};

/* Styling for the image */
//magic numbers
const imageStyle = {
    marginLeft: '15px',
    width: '600px',
    height: '400px'
}
const containerStyle = {
    display: 'flex',
    alignItems: 'center',
    justifyContent: 'center',
    gap: '15px',
};
export default FollowBotControlsPage;

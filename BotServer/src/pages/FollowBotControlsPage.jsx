// src/pages/MoveControlsPage.js
import React from 'react';
import { BrowserRouter as Router, Route} from 'react-router-dom';
import Navigation from '../components/Navigation'; // Navigation component
import MoveAroundButtons from '../components/MoveAroundButtons'; // Move Around Buttons component
import TemperatureDisplay from '../components/TemperatureDisplay'; // Temperature Display component
import HeatIndexDisplay from '../components/HeatIndexDisplay';     // Heat Index Display component (if applicable)

const FollowBotControlsPage = () => {
    return (
        <Router>
            <div>
                <Navigation />
                <h1>Move Controls</h1>
                <MoveAroundButtons />
                <h2>Current Temperature</h2>
                <TemperatureDisplay />
                <h2>Heat Index</h2>
                <HeatIndexDisplay /> {/* Include the Heat Index Display if applicable */}
            </div>
        </Router>
    );
};

export default FollowBotControlsPage;

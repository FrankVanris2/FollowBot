// src/pages/MoveControlsPage.js
import React from 'react';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';
import Navigation from '../components/Navigation'; // Navigation component
import AboutPage from './AboutPage';             // Import the About Page
import ContactPage from './ContactPage';         // Import the Contact Page
import InfoPage from './InfoPage';               // Import the Info Page
import GalleryPage from './GalleryPage';         // Import the Gallery Page
import MoveAroundButtons from '../components/MoveAroundButtons'; // Move Around Buttons component
import TemperatureDisplay from '../components/TemperatureDisplay'; // Temperature Display component
import HeatIndexDisplay from '../components/HeatIndexDisplay';     // Heat Index Display component (if applicable)

const MoveControlsPage = () => {
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
                <Switch>
                    <Route path="/about" component={AboutPage} />
                    <Route path="/contact" component={ContactPage} />
                    <Route path="/gallery" component={GalleryPage} />
                    <Route path="/" exact component={InfoPage} /> {/* Default landing page */}
                </Switch>
            </div>
        </Router>
    );
};

export default MoveControlsPage;

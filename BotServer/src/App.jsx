import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';

// Component Imports
import Navbar from './components/NavBar'; // Check if the file exists

// Page Imports
import AboutAppPage from './pages/AboutAppPage';
import AboutFollowBotPage from './pages/AboutFollowBotPage';
import FeedbackPage from './pages/FeedbackPage';
import NewsArticlePage from './pages/NewsArticlePage';
import FollowBotControlsPage from './pages/FollowBotControlsPage';
import SignupPage from './pages/SignupPage';
import HomePage from './pages/HomePage';
import NotFoundPage from './pages/NotFoundPage';
import AboutUsPage from './pages/AboutUsPage';

// Newly Added Pages (Subsign in Account)
import MyProfilePage from './pages/MyProfile';
import RulesPage from './pages/RulesPage';
import SettingScreen from './pages/SettingScreen';

// Imports for Profile Menu
import UserAnalyticsPage from './pages/UserAnalyticsPage';
import MyAccountPage from './pages/MyAccountPage';
import MappingPage from './pages/MappingPage';
import SignalPage from './pages/SignalPage';
import LivefeedPage from './pages/LiveFeedPage.jsx'; // Check if the file exists
import MyFollowBotsPage from './pages/MyFollowBotsPage';
import BotAnalyticsPage from './pages/BotAnalyticsPage';

// Global Styles
import { GlobalStyle } from './App.style.jsx';

// Import SensorData from data.js
import SensorData from './data';
import data from './data'; // Check if the file exists

function App() {
  return (
    <Router>
      <GlobalStyle />
      <Navbar /> {/* Navbar is present across all pages */}
      <Routes>
        <Route path="/" element={<Layout><HomePage /></Layout>} />
        <Route path="/about-followbot" element={<Layout><AboutFollowBotPage /></Layout>} />
        <Route path="/about-app" element={<Layout><AboutAppPage /></Layout>} />
        <Route path="/about-us" element={<Layout><AboutUsPage /></Layout>} />
        <Route path="/feedback" element={<Layout><FeedbackPage /></Layout>} />
        <Route path="/news-articles" element={<Layout><NewsArticlePage /></Layout>} />
        <Route path="/signup" element={<Layout><SignupPage /></Layout>} />

        {/* Routes for Subsign-in Account */}
        <Route path="/my-profile" element={<Layout><MyProfilePage /></Layout>} />
        <Route path="/rules" element={<Layout><RulesPage /></Layout>} />
        <Route path="/settings" element={<Layout><SettingScreen /></Layout>} />

        {/* Routes for Profiles */}
        <Route path="/followbot-controls" element={<Layout><FollowBotControlsPage /></Layout>} />
        <Route path="/user-analytics" element={<Layout><UserAnalyticsPage sensorData={SensorData} /></Layout>} />
        <Route path="/my-account" element={<Layout><MyAccountPage /></Layout>} />
        <Route path="/mapping" element={<Layout><MappingPage /></Layout>} />
        <Route path="/signal" element={<Layout><SignalPage /></Layout>} />
        <Route path="/live-feed" element={<Layout><LivefeedPage /></Layout>} />
        <Route path="/my-bots" element={<Layout><MyFollowBotsPage /></Layout>} />
        <Route path="/bot-analytics/:botId" element={<Layout><BotAnalyticsPage /></Layout>} />

        {/* Wildcard Route for 404 Not Found */}
        <Route path="*" element={<Layout><NotFoundPage /></Layout>} />
      </Routes>
    </Router>
  );
}

export default App;
import React from 'react'; 
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';

// Components imports
import Navbar from './components/Navbar';
import Layout from './components/Layout';

// Page imports
import AboutAppPage from './pages/AboutAppPage';
import AboutFollowBotPage from './pages/AboutFollowBotPage';
import FeedbackPage from './pages/FeedbackPage';
import NewsArticlePage from './pages/NewsArticlePage'; 
import FollowBotControlsPage from './pages/FollowBotControlsPage';
import SignupPage from './pages/SignupPage';
import HomePage from './pages/HomePage';
import NotFoundPage from './pages/NotFoundPage';
import AboutUsPage from './pages/AboutUsPage';

// Newly added pages
import MyProfilePage from './pages/MyProfile';
import RulesPage from './pages/RulesPage';
import SettingScreen from './pages/SettingScreen';

// Global Styles
import { GlobalStyle } from './App.style.jsx';

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
       
        {/* routes for subsign in acoccount */}
        <Route path="/my-profile" element={<Layout><MyProfilePage /></Layout>} />
        <Route path="/rules" element={<Layout><RulesPage /></Layout>} />
        <Route path="/settings" element={<Layout><SettingScreen /></Layout>} />


        {/* routes for profiles */}
        <Route path="/followbot-controls" element={<Layout><FollowBotControlsPage /></Layout>} />

        
        {/* Wildcard route for 404 Not Found */}
        <Route path="*" element={<Layout><NotFoundPage /></Layout>} />
      </Routes>
    </Router>
  );
}

export default App;

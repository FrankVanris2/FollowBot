import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';

// Components imports
import Navbar from './components/NavBar';
import Layout from './components/Layout';

// Page imports (verify file names match exactly)
import AboutAppPage from './pages/AboutAppPage';
import AboutFollowBotPage from './pages/AboutFollowBotPage';
import FeedbackPage from './pages/FeedbackPage';
import NewsArticlePage from './pages/NewArticlePage'; // Fixed filename
import FollowBotControlsPage from './pages/FollowBotControlsPage';
import HomePage from './pages/HomePage';
import NotFoundPage from './pages/NotFoundPage';
import AboutUsPage from './pages/AboutUsPage';
import { GlobalStyle } from './App.style.jsx';

function App() {
  return (
    <Router>
      <GlobalStyle />
      <Navbar />
      <Routes>
        <Route path="/" element={<Layout><HomePage /></Layout>} />
        {/* Match Navbar link paths exactly */}
        <Route path="/about-followbot" element={<Layout><AboutFollowBotPage /></Layout>} />
        <Route path="/about-app" element={<Layout><AboutAppPage /></Layout>} />
        <Route path="/about-us" element={<Layout><AboutUsPage /></Layout>} />
        <Route path="/feedback" element={<Layout><FeedbackPage /></Layout>} />
        <Route path="/news-articles" element={<Layout><NewsArticlePage /></Layout>} />
        {/*<Route path="/followbot-controls" element={<Layout><FollowBotControlsPage /></Layout>} > */}
        <Route path="*" element={<Layout><NotFoundPage /></Layout>} />
      </Routes>
    </Router>
  );
}

export default App;
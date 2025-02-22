import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';

import Navbar from './NavBar';
import AboutAppPage from './pages/AboutAppPage';
import AboutFollowBotPage from './pages/AboutFollowBotPage';
import FeedbackPage from './pages/FeedbackPage';
import NewsArticlePage from './pages/NewArticlePage'; // Fix the filename case
import FollowBotControlsPage from './pages/FollowBotControlsPage';
import HomePage from './pages/HomePage';
import NotFoundPage from './pages/NotFoundPage';
import AboutUsPage from './pages/AboutUsPage'; // Add the missing import
import { GlobalStyle } from './App.style.jsx';
import Layout from './components/Layout';

function App() {
  return (
    <Router>
      <GlobalStyle />
      <Navbar />
      <div className="container">
        <Routes>
          <Route path="/" element={<Layout><HomePage /></Layout>} />
          <Route path="/AboutAppPage" element={<Layout><AboutAppPage /></Layout>} />
          <Route path="/AboutFollowBotPage" element={<Layout><AboutFollowBotPage /></Layout>} />
          <Route path="/AboutUsPage" element={<Layout><AboutUsPage /></Layout>} />
          <Route path="/FeedbackPage" element={<Layout><FeedbackPage /></Layout>} />
          <Route path="/NewsArticlePage" element={<Layout><NewsArticlePage /></Layout>} />
          <Route path="/FollowBotControlsPage" element={<Layout><FollowBotControlsPage /></Layout>} />
          <Route path="*" element={<Layout><NotFoundPage /></Layout>} />
        </Routes>
      </div>
    </Router>
  );
}

export default App;

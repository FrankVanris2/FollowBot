import React from 'react';
import { Routes, Route, BrowserRouter } from 'react-router-dom';
import Navbar from './NavBar';
import AboutAppPage from './pages/AboutAppPage';
import AboutFollowBotPage from './pages/AboutFollowBotPage';
import AboutUsPage from './pages/AboutUsPage';
import FeedbackPage from './pages/FeedbackPage';
import NewsArticlePage from './pages/NewArticlepage';
import FollowBotControlsPage from './pages/FollowBotControlsPage';
import HomePage from './pages/HomePage';
import NotFoundPage from './pages/NotFoundPage'; // Add a 404 page
import { GlobalStyle } from './App.style.jsx'; // Import the global style
import Layout from './components/Layout'; // Import the Layout component

function App() {
  return (
    <BrowserRouter>
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
          <Route path="*" element={<Layout><NotFoundPage /></Layout>} /> {/* 404 Page */}
        </Routes>
      </div>
    </BrowserRouter>
  );
}

export default App;
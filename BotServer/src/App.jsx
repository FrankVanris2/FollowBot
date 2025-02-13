
import React from 'react';
import {Routes,Route, BrowserRouter} from "react-router-dom"
//import MoveControlsPage from './pages/MoveControlsPage'; // Import the new Move Controls Page
import Navbar from './NavBar';
import AboutAppPage from './pages/AboutAppPage';
import AboutFollowBotPage from './pages/AboutFollowBotPage';
import AboutUsPage from './pages/AboutUsPage';
import FeedbackPage from './pages/FeedbackPage';
import NewsArticlePage from './pages/NewArticlePage';
import FollowBotControlsPage from './pages/FollowBotControlsPage';
import MappingPage from './pages/MappingPage'
import HomePage from './pages/HomePage';
import { GlobalStyle } from './App.style.jsx'; // Import the global style

function App(){
    return(
        <BrowserRouter>
            <GlobalStyle />
            <Navbar />
            <Routes>
                <Route path="/" element={<HomePage />} />
                <Route path="/about-app" element={<AboutAppPage />} />
                <Route path="/about-followbot" element={<AboutFollowBotPage />} />
                <Route path="/about-us" element={<AboutUsPage />} />
                <Route path="/feedback" element={<FeedbackPage />} />
                <Route path="/news-articles" element={<NewsArticlePage />} />
                <Route path="/followbot-controls" element={<FollowBotControlsPage />} />
                <Route path="/mapping" element={<MappingPage />} />
            </Routes>
        </BrowserRouter>
    )
}
export default App;

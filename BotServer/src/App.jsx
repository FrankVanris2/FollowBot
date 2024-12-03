
import React from 'react';
import {Routes,Route, BrowserRouter} from "react-router-dom"
//import MoveControlsPage from './pages/MoveControlsPage'; // Import the new Move Controls Page
import Navbar from './NavBar';
import AboutAppPage from './pages/AboutAppPage';
import AboutFollowBotPage from './pages/AboutFollowBotPage';
import AboutUsPage from './pages/AboutUsPage';
import FeedbackPage from './pages/FeedbackPage';
import NewsArticlePage from './pages/NewArticlepage';
import FollowBotControlsPage from './pages/FollowBotControlsPage';
import HomePage from './pages/HomePage';
import { GlobalStyle } from './App.style.jsx'; // Import the global style


function App(){
    return(
        <BrowserRouter>
            <GlobalStyle />
            <Navbar />
            <div className="container">
                <Routes>
                    <Route path="/" element={<HomePage />} />
                    <Route path="/AboutAppPage" element={<AboutAppPage />} />
                    <Route path="/AboutFollowBotPage" element={<AboutFollowBotPage />} />
                    <Route path="/AboutUsPage" element={<AboutUsPage />} />
                    <Route path="/FeedbackPage" element={<FeedbackPage />} />
                    <Route path="/NewsArticlePage" element={<NewsArticlePage />} />
                    <Route path="/FollowBotControlsPage" element={<FollowBotControlsPage />} />
                    <Route path="/HomePage" element={<HomePage />} />
                </Routes>
             </div>
        </BrowserRouter>
    )
}

/*const App = () => {
    return (
        <MoveControlsPage /> // Render the Move Controls Page
    );
};
*/
export default App;

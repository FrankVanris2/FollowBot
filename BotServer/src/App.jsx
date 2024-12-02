
import React from 'react';
import {Routes,Route} from "react-router-dom"
//import MoveControlsPage from './pages/MoveControlsPage'; // Import the new Move Controls Page
import Navbar from './NavBar';
import AboutAppPage from './pages/AboutAppPage';
import AboutFollowBotPage from './pages/AboutFollowBotPage';
import AboutUsPage from './pages/AboutUsPage';
import FeedbackPage from './pages/FeedbackPage';
import NewsArticlePage from './pages/NewArticlepage';
import HomePage from './pages/HomePage';
import PrivacyAndDataPage from "./pages/PrivacyAndDataPage";
//import { Home } from '@mui/icons-material';


function App(){
    return(
        <>
            <Navbar />
            <div className="container">
                <Routes>
                    <Route path="/" element={<HomePage />} />
                    <Route path="/AboutAppPage" element={<AboutAppPage />} />
                    <Route path="/AboutFollowBotPage" element={<AboutFollowBotPage />} />
                    <Route path="/AboutUsPage" element={<AboutUsPage />} />
                    <Route path="/FeedbackPage" element={<FeedbackPage />} />
                    <Route path="/NewsArticlePage" element={<NewsArticlePage />} />
                    <Route path="/HomePage" element={<HomePage />} />
                </Routes>
             </div>
        </>
    )
}

/*const App = () => {
    return (
        <MoveControlsPage /> // Render the Move Controls Page
    );
};
*/
export default App;

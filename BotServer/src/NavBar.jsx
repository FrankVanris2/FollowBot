//import { PriceChangeOutlined } from "@mui/icons-material"
import React from 'react';
import { Link, useMatch,useResolvedPath } from "react-router-dom"
import AccountMenu from './components/Login';
import {Header} from './NavBar.style';
import Logo from './pages/res/logo.png';

export default function Navbar(){
    return (
        <>  

            
            <Header style={{ display: "flex", flexDirection: "row" }}>
            <img src={Logo} alt="Logo" />
            <div style={{width:'100%', display: "flex", alignItems: "center", justifyContent: "center", fontWeight: "bolder"  }}>
                CARRY WITH ME
            </div>
            </Header>
            <nav className="nav">
                <Link to="/" className="site-title">
                    FollowBot
                </Link>
                <ul style={{display:"flex", flexDirection:"row", alignItems:"center", justifyContent:"center"}}>
                    <CustomLink to="/AboutFollowBotPage">AboutFollowBot</CustomLink>
                    <CustomLink to="/AboutAppPage">AboutApp</CustomLink>
                    <CustomLink to="/AboutUsPage">AboutUs</CustomLink>
                    <CustomLink to="/FeedbackPage">Feedback</CustomLink>
                    <CustomLink to="/NewsArticlePage">NewsArticle</CustomLink>  
                    <CustomLink to="/FollowBotControlsPage">FollowBotControls</CustomLink>
                    <CustomLink to="/HomePage">Home</CustomLink>
                    <AccountMenu/>
                </ul>
            </nav>
        </>
    );
}

function CustomLink({to,children, ...props}){
    const resolvedPath = useResolvedPath(to)
    const isActive = useMatch({path: resolvedPath.pathname, end:true})
    return(
        <li className={isActive? "active" : ""}>
            <Link to={to} {...props}>
                {children}
            </Link> 
        </li>
    );

}


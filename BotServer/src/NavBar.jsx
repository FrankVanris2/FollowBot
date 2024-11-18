//import { PriceChangeOutlined } from "@mui/icons-material"
import React from 'react';
import { Link, useMatch,useResolvedPath } from "react-router-dom"

export default function Navbar(){
    const path = window.location.pathname
    return (
        <nav className="nav">
            <Link to="/" className="site-title">
                FollowBot
            </Link>
            <ul>
                <CustomLink to="/AboutFollowBotPage">AboutFollowBot</CustomLink>
                <CustomLink to="/AboutAppPage">AboutApp</CustomLink>
                <CustomLink to="/AboutUsPage">AboutUs</CustomLink>
                <CustomLink to="/FeedbackPage">Feedback</CustomLink>
                <CustomLink to="/NewsArticlePage">NewsArticle</CustomLink>  
                <CustomLink to="/HomePage">Home</CustomLink>  
            </ul>
    
        </nav>
    )
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


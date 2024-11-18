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
                <CustomLink to="/AboutFollowBot">AboutFollowBot</CustomLink>
                <CustomLink to="/AboutAppPage">AboutAppPage</CustomLink>
                <CustomLink to="/AboutUsPage">AboutUsPage</CustomLink>
                <CustomLink to="/FeedbackPage">FeedbackPage</CustomLink>
                <CustomLink to="/NewsArticlePage">NewsArticlePage</CustomLink>  
                <CustomLink to="/HomePage">HomePage</CustomLink>  
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


//import { PriceChangeOutlined } from "@mui/icons-material"
import React from 'react';
import { Link, useMatch,useResolvedPath } from "react-router-dom"
import AccountMenu from './AccountMenu.jsx';
import {Header, LinkItem} from '../styles/NavBar.style';

import Logo from '../res/logo.png';

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
                    <CustomLink to="/about-followbot">About FollowBot</CustomLink>
                    <CustomLink to="/about-app">About App</CustomLink>
                    <CustomLink to="/about-us">About Us</CustomLink>
                    <CustomLink to="/feedback">Feedback</CustomLink>
                    <CustomLink to="/news-articles">News Article</CustomLink>
                    {/* <CustomLink to="/followbot-controls">FollowBot Controls</CustomLink> */}
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
        <LinkItem className={isActive? "active" : ""}>
            <Link to={to} {...props}>
                {children}
            </Link> 
        </LinkItem>
    );

}


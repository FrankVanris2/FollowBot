import React from 'react';
import { Link, useMatch, useResolvedPath } from 'react-router-dom';
import AccountMenu from './AccountMenu.jsx';
import { Header, LinkItem, Nav, NavList } from '../styles/NavBar.style';
import Logo from '../res/logo.png';

export default function NavBar() {
  return (
    <>
      {/* Header Section */}
      <Header>
        <img src={Logo} alt="Logo" />
        <div className="title">CARRY WITH ME</div>
      </Header>

      {/* Navigation Bar */}
      <Nav>
        <Link to="/" className="site-title">
          FollowBot
        </Link>
        <NavList>
          <CustomLink to="/about-followbot">About FollowBot</CustomLink>
          <CustomLink to="/about-app">About App</CustomLink>
          <CustomLink to="/about-us">About Us</CustomLink>
          <CustomLink to="/feedback">Feedback</CustomLink>
          <CustomLink to="/news-articles">News Article</CustomLink>
          <AccountMenu />
        </NavList>
      </Nav>
    </>
  );
}

function CustomLink({ to, children, ...props }) {
  const resolvedPath = useResolvedPath(to);
  const isActive = useMatch({ path: resolvedPath.pathname, end: true });
  return (
    <LinkItem className={isActive ? 'active' : ''}>
      <Link to={to} {...props}>
        {children}
      </Link>
    </LinkItem>
  );
}

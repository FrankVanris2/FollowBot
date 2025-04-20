import React from "react";
import '../styles/Layout.style.css'; 

const Layout = ({ children }) => {
  return (
    <div className="layout">
      {/* Skip to main content link */}
      <a className="skip-link" href="#main-content">
        Skip to main content
      </a>

      {/* Main content */}
      <main id="main-content" className="content">
        {children}
      </main>
    </div>
  );
};

export default Layout; 

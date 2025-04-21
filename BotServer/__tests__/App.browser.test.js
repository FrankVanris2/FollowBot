import React from 'react';
import { render, screen } from '@testing-library/react';
import { BrowserRouter } from 'react-router-dom';
import App from '../src/App'; // Adjust the path if necessary

describe('App Component', () => {
  it('should render the HomePage by default', () => {
    render(
      <BrowserRouter>
        <App />
      </BrowserRouter>
    );

    // Check if the HomePage content is rendered
    expect(screen.getByText('Home')).toBeInTheDocument(); // Replace 'Home' with actual text from your HomePage
  });

  it('should render the AboutUsPage when navigating to /about-us', () => {
    window.history.pushState({}, 'About Us Page', '/about-us');

    render(
      <BrowserRouter>
        <App />
      </BrowserRouter>
    );

    // Check if the AboutUsPage content is rendered
    expect(screen.getByText('About Us')).toBeInTheDocument(); // Replace 'About Us' with actual text from your AboutUsPage
  });

  it('should render the NotFoundPage for an unknown route', () => {
    window.history.pushState({}, 'Unknown Page', '/unknown-route');

    render(
      <BrowserRouter>
        <App />
      </BrowserRouter>
    );

    // Check if the NotFoundPage content is rendered
    expect(screen.getByText('Page Not Found')).toBeInTheDocument(); // Replace 'Page Not Found' with actual text from your NotFoundPage
  });
});
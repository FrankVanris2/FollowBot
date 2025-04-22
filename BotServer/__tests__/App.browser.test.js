import React from 'react';
import { render, screen } from '@testing-library/react';
import { BrowserRouter } from 'react-router-dom';
import App from '../src/App';

describe('App Component', () => {
  it('should render the HomePage by default', () => {
    render(
      <BrowserRouter>
        <App />
      </BrowserRouter>
    );

    // Adjust this to match actual content in your HomePage component
    expect(screen.getByText(/home/i)).toBeInTheDocument();
  });

  it('should render the AboutUsPage when navigating to /about-us', () => {
    window.history.pushState({}, 'About Us Page', '/about-us');

    render(
      <BrowserRouter>
        <App />
      </BrowserRouter>
    );

    // Adjust this to match actual content in your AboutUsPage component
    expect(screen.getByText(/about us/i)).toBeInTheDocument();
  });

  it('should render the NotFoundPage for an unknown route', () => {
    window.history.pushState({}, 'Unknown Page', '/unknown-route');

    render(
      <BrowserRouter>
        <App />
      </BrowserRouter>
    );

    // Adjust this to match actual content in your NotFoundPage component
    expect(screen.getByText(/page not found/i)).toBeInTheDocument();
  });
});
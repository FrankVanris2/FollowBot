import React from 'react';
import { render, screen } from '@testing-library/react';
import { BrowserRouter } from 'react-router-dom';
import Navbar from '../src/components/NavBar';

describe('Navbar Component', () => {
  it('should render the Navbar with links', () => {
    render(
      <BrowserRouter>
        <Navbar />
      </BrowserRouter>
    );

    // Check if specific links or elements are present
    expect(screen.getByText('FollowBot')).toBeInTheDocument(); // Updated to match the actual site title
    expect(screen.getByText('About FollowBot')).toBeInTheDocument();
    expect(screen.getByText('About App')).toBeInTheDocument();
    expect(screen.getByText('About Us')).toBeInTheDocument();
    expect(screen.getByText('Feedback')).toBeInTheDocument();
    expect(screen.getByText('News Article')).toBeInTheDocument();
  });

  it('should have a logo', () => {
    render(
      <BrowserRouter>
        <Navbar />
      </BrowserRouter>
    );

    // Check if the logo is present
    const logo = screen.getByAltText('Logo'); // Ensure the alt text matches the actual logo
    expect(logo).toBeInTheDocument();
  });
});
import React from 'react';
import { render, screen } from '@testing-library/react';
import { BrowserRouter } from 'react-router-dom';
import Navbar from '../src/components/Navbar'; // Adjust the path if necessary

describe('Navbar Component', () => {
  it('should render the Navbar with links', () => {
    render(
      <BrowserRouter>
        <Navbar />
      </BrowserRouter>
    );

    // Check if specific links or elements are present
    expect(screen.getByText('Home')).toBeInTheDocument();
    expect(screen.getByText('About')).toBeInTheDocument();
    expect(screen.getByText('Contact')).toBeInTheDocument();
  });

  it('should have a logo', () => {
    render(
      <BrowserRouter>
        <Navbar />
      </BrowserRouter>
    );

    // Check if the logo is present
    const logo = screen.getByAltText('Logo'); // Replace 'Logo' with the actual alt text of your logo
    expect(logo).toBeInTheDocument();
  });
});
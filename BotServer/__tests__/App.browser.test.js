import React from 'react';
import { render, screen } from '@testing-library/react';
import App from '../src/App';

describe('App Component', () => {
    beforeEach(() => {
        // Reset the history state before each test
        window.history.pushState({}, '', '/');
    });

    it('should render the HomePage by default', () => {
        render(<App />);
        expect(screen.getByRole('heading', { name: /FollowBot/i })).toBeInTheDocument();
    });

    it('should render the AboutUsPage when navigating to /about-us', () => {
        window.history.pushState({}, 'About Us Page', '/about-us');
        render(<App />);
        expect(screen.getByRole('heading', { name: /We are the CarryWithMe Team!/i })).toBeInTheDocument();
    });

    it('should render the NotFoundPage for an unknown route', () => {
        window.history.pushState({}, 'Unknown Page', '/unknown-route');
        render(<App />);
        expect(screen.getByRole('heading', { name: /404 - Page Not Found/i })).toBeInTheDocument();
    });

    it('should render the ContactPage when navigating to /contact', () => {
        window.history.pushState({}, 'Contact Page', '/contact');
        render(<App />);
        expect(screen.getByRole('heading', { name: /Contact Us/i })).toBeInTheDocument();
    });

    it('should render the ServicesPage when navigating to /services', () => {
        window.history.pushState({}, 'Services Page', '/services');
        render(<App />);
        expect(screen.getByRole('heading', { name: /Our Services/i })).toBeInTheDocument();
    });

    it('should maintain the correct page when navigating back and forth', () => {
        window.history.pushState({}, 'About Us Page', '/about-us');
        render(<App />);
        expect(screen.getByRole('heading', { name: /We are the CarryWithMe Team!/i })).toBeInTheDocument();

        window.history.pushState({}, 'Home Page', '/');
        render(<App />);
        expect(screen.getByRole('heading', { name: /FollowBot/i })).toBeInTheDocument();

        window.history.back();
        render(<App />);
        expect(screen.getByRole('heading', { name: /We are the CarryWithMe Team!/i })).toBeInTheDocument();
    });
});
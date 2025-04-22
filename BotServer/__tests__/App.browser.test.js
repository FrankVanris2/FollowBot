import React from 'react';
import { render, screen } from '@testing-library/react';
import App from '../src/App'; // No need to wrap App with BrowserRouter here

describe('App Component', () => {
    beforeEach(() => {
        // Ensure the history state is reset before each test
        window.history.pushState({}, '', '/');
    });

    it('should render the HomePage by default', () => {
        render(<App />); // Removed BrowserRouter wrapper

        expect(screen.getByText(/home/i)).toBeInTheDocument();
    });

    it('should render the AboutUsPage when navigating to /about-us', () => {
        window.history.pushState({}, 'About Us Page', '/about-us');

        render(<App />); // Removed BrowserRouter wrapper

        expect(screen.getByText(/about us/i)).toBeInTheDocument();
    });

    it('should render the NotFoundPage for an unknown route', () => {
        window.history.pushState({}, 'Unknown Page', '/unknown-route');

        render(<App />); // Removed BrowserRouter wrapper

        expect(screen.getByText(/page not found/i)).toBeInTheDocument();
    });

    it('should render the ContactPage when navigating to /contact', () => {
        window.history.pushState({}, 'Contact Page', '/contact');

        render(<App />); // Removed BrowserRouter wrapper

        expect(screen.getByText(/contact us/i)).toBeInTheDocument();
    });

    it('should render the ServicesPage when navigating to /services', () => {
        window.history.pushState({}, 'Services Page', '/services');

        render(<App />); // Removed BrowserRouter wrapper

        expect(screen.getByText(/our services/i)).toBeInTheDocument();
    });

    it('should maintain the correct page when navigating back and forth', () => {
        window.history.pushState({}, 'About Us Page', '/about-us');
        render(<App />);
        expect(screen.getByText(/about us/i)).toBeInTheDocument();

        window.history.pushState({}, 'Home Page', '/');
        render(<App />);
        expect(screen.getByText(/home/i)).toBeInTheDocument();

        window.history.back();
        render(<App />);
        expect(screen.getByText(/about us/i)).toBeInTheDocument();
    });

    it('should render the RulesPage when navigating to /rules', () => {
        window.history.pushState({}, 'Rules Page', '/rules');

        render(<App />); // Removed BrowserRouter wrapper

        expect(screen.getByText(/user guidelines and rules/i)).toBeInTheDocument();
    });

    it('should render the SettingsPage when navigating to /settings', () => {
        window.history.pushState({}, 'Settings Page', '/settings');

        render(<App />); // Removed BrowserRouter wrapper

        expect(screen.getByText(/settings/i)).toBeInTheDocument();
    });
});
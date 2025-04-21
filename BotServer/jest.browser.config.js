module.exports = {
  testEnvironment: 'jsdom', // Use jsdom for browser-like testing
  testMatch: ['**/__tests__/**/*.browser.test.js'], // Match browser-specific test files
  setupFilesAfterEnv: ['<rootDir>/jest.setup.js'], // Optional: Add setup file for additional configurations
};
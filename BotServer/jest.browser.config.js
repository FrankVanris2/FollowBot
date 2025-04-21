module.exports = {
  testEnvironment: 'jsdom', // Use jsdom for browser-like testing
  testMatch: ['**/__tests__/**/*.browser.test.js'], // Match browser-specific test files
  setupFilesAfterEnv: ['<rootDir>/jest.setup.js'], // Reference the setup file
  moduleNameMapper: {
    '\\.(css|less|scss|sass)$': 'identity-obj-proxy', // Mock CSS imports
    '\\.(png|jpg|jpeg|gif|svg)$': '<rootDir>/__mocks__/fileMock.js', // Mock image imports
  },
};
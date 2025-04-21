module.exports = {
  testEnvironment: 'jsdom', // Use jsdom for browser-like testing
  testMatch: ['**/__tests__/**/*.browser.test.js'], // Match browser-specific test files
  setupFilesAfterEnv: ['<rootDir>/jest.setup.js'], // Reference the setup file
  moduleNameMapper: {
    '\\.(css|less|scss|sass)$': 'identity-obj-proxy', // Mock CSS imports
    '\\.(png|jpg|jpeg|gif|svg)$': '<rootDir>/__mocks__/fileMock.js', // Mock image imports
  },
  transformIgnorePatterns: [
    'node_modules/(?!(react-leaflet|@react-leaflet|leaflet)/)', // Transform react-leaflet and its dependencies
  ],
  transform: {
    '^.+\\.(js|jsx|ts|tsx)$': 'babel-jest', // Use Babel to transform JavaScript files
  },
};
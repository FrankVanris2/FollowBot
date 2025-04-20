# Jest Documentation for React Environment

## Introduction
Jest is a delightful JavaScript testing framework with a focus on simplicity. It works seamlessly with projects using React.

## Installation
We've already installed Jest into our project, but JUST in case...To start using Jest in FollowBot, you need to install it along with Babel for transpiling your tests. If you are using Create React App, Jest is already included.

### Install Jest and Babel
Run the following command to install Jest and Babel:

```bash
npm install --save-dev jest babel-jest @babel/preset-env @babel/preset-react react-test-renderer @testing-library/react @testing-library/jest-dom
```
## Configuration

### .babelrc

Create or update your `.babelrc` file to include the following presets:

```json
{
    "presets": ["@babel/preset-env", "@babel/preset-react"]
}
```

### package.json

Add a test script to your `package.json` file to run Jest:

```json
{
  "scripts": {
    "test": "jest"
  }
}
```

### Example Component

Here is an example of a simple React component:

```jsx
// SumComponent.jsx
import React from 'react';

function SumComponent({ a, b }) {
    return <div className='sum'>{a + b}</div>;
}

export default SumComponent;
```

### Example Test File

Now let's create a test file for `SumComponent` using Jest and React Testing Library

```jsx
// SumComponent.test.jsx
import React from 'react';
import { render } from '@testing-library/react';
import SumComponent from '../src/SumComponent';

describe('SumComponent', () => {
    it('renders the sum of 1 and 2', () => {
        render(<SumComponent a={1} b={2} />);
        const sums = document.getElementsByClassName('sum');
        expect(sums).toHaveLength(1);
        const sum = sums.item(0);
        const text = sum.innerHTML;
        expect(text).toBe('3');
    });
});
```

### Running Tests

To run your tests, use the following command:

```bash
npm test
```

This command will start Jest and run all test files that match the `.test.jsx` or `.spec.jsx` pattern.

### Mocking

Jest also allows you to mock modules easily. Here is an example of how to mock a module:

```jsx
jest.mock('path/to/module', () => ({
  functionName: jest.fn(() => 'mocked value')
}));
```

### Assertions

Jest includes many built-in assertions, but you can extend it with additional matchers from libraries like `@testing-library/jest-dom`.

```jsx
import '@testing-library/jest-dom/extend-expect';

// Example assertion
expect(element).toHaveTextContent('Hello, World!');
```

### Conclusion

Jest is a powerful testing framework that integrates seamlessly with React. With the integration of Jest in this project you as a developer will be able to apply feature tests before full implementation. 

And with the above examples that were mentioned you should be able to start testing.

For more information, refer to the [Jest documentation](https://jestjs.io/docs/getting-started?form=MG0AV3) and [React Testing Library documentation](https://testing-library.com/docs/react-testing-library/intro/?form=MG0AV3)

*Feel free to customize this documentation for any particular Jest updates in this project.*

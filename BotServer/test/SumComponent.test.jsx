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


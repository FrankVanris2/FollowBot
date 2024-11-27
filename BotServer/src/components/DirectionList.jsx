import React from 'react';

const DirectionList = ({ presses }) => (
  <div>
    <h3>Button Presses:</h3>
    <ul>
      {presses.map((press, index) => (
        <li key={index}>{press}</li>
      ))}
    </ul>
  </div>
);

export default DirectionList;

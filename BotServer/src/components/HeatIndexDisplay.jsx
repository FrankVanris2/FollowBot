import React from 'react';

const HeatIndexDisplay = ({ heatIndex }) => (
  <div>
    <h3>Heat Index:</h3>
    {heatIndex !== null ? <p>{heatIndex}°C</p> : <p>Loading...</p>}
  </div>
);

export default HeatIndexDisplay;

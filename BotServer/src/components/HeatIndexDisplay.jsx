import React from 'react';

const HeatIndexDisplay = ({ heatIndex }) => (
  <div>
    {heatIndex !== null ? <p>{heatIndex}°C</p> : <p>Loading...</p>}
  </div>
);

export default HeatIndexDisplay;

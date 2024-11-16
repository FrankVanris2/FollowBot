import React from 'react';

const TemperatureDisplay = ({ temperature }) => (
  <div>
    <h3>Temperature:</h3>
    {temperature !== null ? <p>{temperature}°C</p> : <p>Loading...</p>}
  </div>
);

export default TemperatureDisplay;

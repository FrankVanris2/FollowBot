import React from 'react';

const TemperatureDisplay = ({ temperature }) => (
  <div>
    {temperature !== null ? <p>{temperature}°C</p> : <p>Loading...</p>}
  </div>
);

export default TemperatureDisplay;

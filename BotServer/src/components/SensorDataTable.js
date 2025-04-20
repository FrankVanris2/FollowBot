import React, { useEffect } from 'react';

const SensorDataTable = ({ data }) => {
  useEffect(() => {
    console.log("SensorDataTable received data:", data);
  }, [data]);

  return (
    <div className="sensor-data-table">
      <h2>Sensor Data</h2>
      {data.length === 0 ? <p>No Data Available</p> : (
        <table>
          <thead>
            <tr>
              <th>Date</th>
              <th>Time</th>
              <th>Temperature (°C)</th>
              <th>Battery (%)</th>
              <th>Latitude</th>
              <th>Longitude</th>
            </tr>
          </thead>
          <tbody>
            {data.map((entry, index) => (
              <tr key={index}>
                <td>{entry.date}</td>
                <td>{entry.time}</td>
                <td>{entry.temperature}</td>
                <td>{entry.battery ?? "N/A"}</td>
                <td>{entry.lastKnownLocation.latitude ?? "N/A"}</td>
                <td>{entry.lastKnownLocation.longitude ?? "N/A"}</td>
              </tr>
            ))}
          </tbody>
        </table>
      )}
    </div>
  );
};

export default SensorDataTable;
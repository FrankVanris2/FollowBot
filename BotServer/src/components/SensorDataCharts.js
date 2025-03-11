import React from 'react';
import { Bar } from 'react-chartjs-2';
import { Chart as ChartJS, CategoryScale, LinearScale, BarElement, Title, Tooltip, Legend } from 'chart.js';

ChartJS.register(CategoryScale, LinearScale, BarElement, Title, Tooltip, Legend);

const SensorDataCharts = ({ data }) => {
  const chartData = {
    labels: data.map((entry) => entry.time), // Use time as labels
    datasets: [
      {
        label: "Temperature (°C)",
        data: data.map((entry) => entry.temperature),
        backgroundColor: "rgba(75, 192, 192, 0.6)",
        borderColor: "rgba(75, 192, 192, 1)",
        borderWidth: 2,
      },
      {
        label: "Battery (%)",
        data: data.map((entry) => entry.battery),
        backgroundColor: "rgba(255, 99, 132, 0.6)",
        borderColor: "rgba(255, 99, 132, 1)",
        borderWidth: 2,
      },
    ],
  };

  return (
    <div className="sensor-data-charts">
      <h2>Sensor Data Visualization</h2>
      <div style={{ width: "700px" }}>
        <Bar data={chartData} />
      </div>
    </div>
  );
};

export default SensorDataCharts;
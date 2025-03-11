import React from "react";
import BarChart from "../components/Bar"; // Adjust the path to Bar.jsx
import LineGraph from "../components/Line"; // Adjust the path to Line.jsx
import PieChart from "../components/Pie"; // Adjust the path to Pie.jsx

const UserAnalytics = () => {
  // Sample data for the charts
  const barData = {
    labels: ["January", "February", "March", "April", "May", "June", "July"],
    datasets: [
      {
        label: "My First dataset",
        backgroundColor: "rgba(75,192,192,0.6)",
        borderColor: "rgba(75,192,192,1)",
        borderWidth: 1,
        data: [65, 59, 80, 81, 56, 55, 40],
      },
    ],
  };

  const lineData = {
    labels: ["08:51", "09:51", "10:51", "11:51", "12:51", "13:51", "14:51", "15:51", "16:51", "17:51"],
    datasets: [
      {
        label: "Temperature (°C)",
        data: [23.5, 24, 22.3, 24.3, 25.5, 24.3, 24.3, 22.5, 21.4, 20.6],
        borderColor: "rgba(54, 162, 235, 1)",
        backgroundColor: "rgba(54, 162, 235, 0.2)",
        pointRadius: 5,
        pointBackgroundColor: "rgba(54, 162, 235, 1)",
        fill: true,
        tension: 0.4,
      },
    ],
  };

  const pieData = {
    labels: ["Red", "Blue", "Yellow"],
    datasets: [
      {
        data: [300, 50, 100],
        backgroundColor: ["#FF6384", "#36A2EB", "#FFCE56"],
        hoverBackgroundColor: ["#FF6384", "#36A2EB", "#FFCE56"],
      },
    ],
  };

  return (
    <div className="container">
      <h1 className="title">User Analytics & FollowBot Usage</h1>
      <div className="content">
        {/* Bar Chart */}
        <div className="chart-section">
          <h2 className="chart-title">Bar Chart</h2>
          <BarChart chartData={barData} />
        </div>

        {/* Line Chart */}
        <div className="chart-section">
          <h2 className="chart-title">Line Chart</h2>
          <LineGraph data={lineData} />
        </div>

        {/* Pie Chart */}
        <div className="chart-section">
          <h2 className="chart-title">Pie Chart</h2>
          <PieChart chartData={pieData} />
        </div>
      </div>
      <button className="back-button">Back</button>
    </div>
  );
};

export default UserAnalytics;
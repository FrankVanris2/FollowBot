import React from "react";
import { useNavigate } from "react-router-dom"; // Import useNavigate
import BarChart from "../components/Bar"; // Adjust the path to Bar.jsx
import LineGraph from "../components/Line"; // Adjust the path to Line.jsx
import PieChart from "../components/Pie"; // Adjust the path to Pie.jsx
//import "../styles/UserAnalyticsPage.style.css"; this breaks it need to fix style 




const UserAnalytics = () => {
  const navigate = useNavigate(); // Initialize the navigate function

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
      {/* Back Button */}
      <button className="back-button" onClick={() => navigate("/my-profile")}>
        Back to Profile
      </button>
    </div>
  );
};

export default UserAnalytics;
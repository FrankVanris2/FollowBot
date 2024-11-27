// services/api.js
const getTemperature = async () => {
    const response = await fetch('/api/getTempInfo');
    return response.json();
  };
  
  const getHeatIndex = async () => {
    const response = await fetch('/api/getHeatIdxInfo');
    return response.json();
  };
  
  const postMovement = async (direction) => {
    await fetch('/api/postmovement', {
      method: 'POST',
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({ direction }),
    });
  };
  
  export default {
    getTemperature,
    getHeatIndex,
    postMovement,
  };
  
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
    const response = await fetch('/api/postmovement', {
      method: 'POST',
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({ direction }),
    });
    return response.json()
  };

  const getUser = async() => {

  }

  const postSignUp = async (formData) => {
    const response = await fetch('/api/signup', {
      method: 'POST',
      headers: {
        "Content-Type": "application/json"
      },
      body: JSON.stringify(formData)
    });
    return response.json()
  }
  
  export default {
    getTemperature,
    getHeatIndex,
    postMovement,
    postSignUp
  };
  
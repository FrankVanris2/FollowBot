const API_BASE_URL = '/api';

const handleResponse = async (response) => {
  const data = await response.json();
  if (!response.ok) {
    throw new Error(data.message || 'API request failed');
  }
  return data;
};

const api = {
  getTemperature: async () => {
    const response = await fetch(`${API_BASE_URL}/getTempInfo`);
    return handleResponse(response);
  },
  
  getHeatIndex: async () => {
    const response = await fetch(`${API_BASE_URL}/getHeatIdxInfo`);
    return handleResponse(response);
  },
  
  getBot: async (bot_id) => {
    const response = await fetch(`${API_BASE_URL}/getBot`, {
      method: 'POST',
      headers: {
        "Content-Type": "application/json"
      },
      body: JSON.stringify({ bot_id })
    });
    return handleResponse(response);
  },

  linkBot: async () => {
    const response = await fetch(`${API_BASE_URL}/linkBot`, {
      method: 'POST',
      headers: {
        "Content-Type": "application/json"
      },
      body: JSON.stringify({})  // Changed from 'holder' to empty object
    });
    return handleResponse(response);
  },

  postLogin: async (credentials) => {
    const response = await fetch(`${API_BASE_URL}/login`, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json'
      },
      credentials: 'include',
      body: JSON.stringify(credentials)
    });
    const data = await handleResponse(response);
    return { ...data, success: true };  // Only reaches here if no error thrown
  },

  postLogout: async () => {
    const response = await fetch(`${API_BASE_URL}/logout`, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json'
      },
      credentials: 'include'
    });
    return handleResponse(response);
  },

  postSignUp: async (formData) => {
    const response = await fetch(`${API_BASE_URL}/signup`, {
      method: 'POST',
      headers: {
        "Content-Type": "application/json"
      },
      body: JSON.stringify(formData)
    });
    return handleResponse(response);
  },


  postCoordinates: async (latitude, longitude) => {
    const dataString = `MAPPING,${latitude},${longitude}`;
    const response = await fetch(`${API_BASE_URL}/postActionData`, {
      method: 'POST',
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({ dataString }),  
    });
    return handleResponse(response);
  },

  postMovement: async (direction) => {
    const dataString = `MANUAL,${direction}`;
    const response = await fetch(`${API_BASE_URL}/postActionData`, {
      method: 'POST',
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({ dataString }),  
    });
    return handleResponse(response);
  },

  postModeChange: async (mode) => {
    const dataString = `FOLLOWING`;
    const response = await fetch(`${API_BASE_URL}/postActionData`, {
      method: 'POST',
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({ dataString }),  
    });
    return handleResponse(response);
  }

  
};

export default api;
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

const getBot = async(bot_id) => {
  const response = await fetch('api/getBot', {
    method: 'POST',
    headers: {
      "Content-Type": "application/json"
    },
    body: JSON.stringify({bot_id})
  });
  return response.json()
};

const linkBot = async() => {
  const response = await fetch('api/linkBot', {
    method: 'POST',
    headers: {
      "Content-Type": "application/json"
    },
    body: JSON.stringify('holder')
  });
  return response.json()
};

const postLogin = async (credentials) => {
  const response = await fetch('/api/login', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify(credentials)
  });

  const data = await response.json();
  return { ...data, success: response.ok };
};

const postLogout = async () => {
  const response = await fetch('/api/logout', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    },
    credentials: 'include' // Include cookies
  });
  const data = await response.json();
  return { ...data, success: response.ok };
};

const postSignUp = async (formData) => {
  const response = await fetch('/api/signup', {
    method: 'POST',
    headers: {
      "Content-Type": "application/json"
    },
    body: JSON.stringify(formData)
  });
  return response.json()
};
  
export default {
  getTemperature,
  getHeatIndex,
  postMovement,
  postLogout,
  postSignUp,
  postLogin,
  getBot
};
  
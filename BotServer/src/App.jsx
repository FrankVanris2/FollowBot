import React, { useState, useRef, useEffect } from 'react';
import Button from '@mui/material/Button';
import Stack from '@mui/material/Stack';

import ArrowBackIcon from '@mui/icons-material/ArrowBack';
import ArrowDownwardIcon from '@mui/icons-material/ArrowDownward';
import ArrowUpwardIcon from '@mui/icons-material/ArrowUpward';
import ArrowForwardIcon from '@mui/icons-material/ArrowForward';
import StopIcon from '@mui/icons-material/Stop';

const App = () => {
  const [presses, setPresses] = useState([]);
  const [temperature, setTemperature] = useState(null);
  const [heatIndex, setHeatIndex] = useState(null);
  const holdThreshold = 5000; // 5 seconds
  const holdTimer = useRef(null);

  useEffect(() => {
    const fetchTemperature = async () => {
      try {
        const response = await fetch('/api/getTempInfo');
        const data = await response.json();
        console.log(data);
        if (data.temperature) {
          setTemperature(data.temperature);
        }
      } catch (error) {
        console.error('Error fetching temperature data:', error);
      }
    };

    fetchTemperature();
  }, []);

  useEffect(() => {
    const fetchHeatIndex = async () => {
      try {
        const response = await fetch('/api/getHeatIdxInfo');
        const data = await response.json();
        console.log(data);
        if (data.heatIndex) {
          setHeatIndex(data.heatIndex);
        }
      } catch (error) {
        console.error('Error fetching heat index data:', error);
      }
    };

    fetchHeatIndex();
  }, []);

  const handleMouseDown = (direction) => {
    holdTimer.current = setTimeout(() => {
      handleButtonClick(direction);
    }, holdThreshold);
  };

  const handleMouseUp = (direction) => {
    clearTimeout(holdTimer.current);
    handleButtonClick(direction);
  };

  const handleButtonClick = async (direction) => {
    setPresses(prevPresses => [...prevPresses, direction]);
    // debugging feature, remove when we are pushing final product    o
    console.log(`Button pressed: ${direction}`);
    try {
      await fetch('/api/postmovement', {
        method: 'POST',
        headers: {
          "Content-Type": "application/json",
          },
        body: JSON.stringify({direction}),
        })
      }
    catch (exc) {
      console.error('Exception:', exc);
      }
  };

  return (
    <>
      <MoveAroundButtons 
        handleMouseDown={handleMouseDown}
        handleMouseUp={handleMouseUp}
        handleButtonClick={handleButtonClick}
      />
      <DirectionList presses={presses} />
      <TemperatureDisplay temperature={temperature} />
      <HeatIndexDisplay heatIndex={heatIndex} />
    </>
  );
};


const MoveAroundButtons = ({ handleMouseDown, handleMouseUp, handleButtonClick }) => (
  <Stack direction="column" alignItems="center" spacing={2}>
    <Button 
      variant="contained" 
      color="primary" 
      onMouseDown={() => handleMouseDown('Forward')}
      onMouseUp={() => handleMouseUp('Forward')}
    >
      <ArrowUpwardIcon fontSize="large" />
    </Button>

    <Stack direction="row" spacing={2} justifyContent="center">
      <Button 
        variant="contained" 
        color="primary" 
        onMouseDown={() => handleMouseDown('Left')}
        onMouseUp={() => handleMouseUp('Left')}
      >
        <ArrowBackIcon fontSize="large" />
      </Button>
      <Button 
        variant="contained" 
        color="primary" 
        onMouseDown={() => handleMouseDown('Backward')}
        onMouseUp={() => handleMouseUp('Backward')}
      >
        <ArrowDownwardIcon fontSize="large" />
      </Button>
      <Button 
        variant="contained" 
        color="primary" 
        onMouseDown={() => handleMouseDown('Right')}
        onMouseUp={() => handleMouseUp('Right')}
      >
        <ArrowForwardIcon fontSize="large" />
      </Button>
    </Stack>

    <Button 
      variant="contained" 
      color="secondary" 
      onClick={() => handleButtonClick('Stop')}
    >
      <StopIcon fontSize="large" />
    </Button>
    <span>Stop the machine</span>
  </Stack>
);

const DirectionList = ({ presses }) => (
  <div>
    <h3>Button Presses:</h3>
    <ul>
      {presses.map((press, index) => (
        <li key={index}>{press}</li>
      ))}
    </ul>
  </div>
);

const TemperatureDisplay = ({ temperature}) => (
  <div>
    <h3>Temperature:</h3>
    {temperature !== null ? <p>{temperature}°C</p> : <p>Loading...</p>}
  </div>
);

const HeatIndexDisplay = ({heatIndex}) => (
  <div>
    <h3>Heat Index:</h3>
    {heatIndex !== null ? <p>{heatIndex}°C</p> : <p>Loading...</p>}
  </div>
);

export default App;

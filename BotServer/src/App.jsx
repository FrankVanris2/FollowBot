import React, { useState, useRef } from 'react';
import Button from '@mui/material/Button';
import Stack from '@mui/material/Stack';

import ArrowBackIcon from '@mui/icons-material/ArrowBack';
import ArrowDownwardIcon from '@mui/icons-material/ArrowDownward';
import ArrowUpwardIcon from '@mui/icons-material/ArrowUpward';
import ArrowForwardIcon from '@mui/icons-material/ArrowForward';
import StopIcon from '@mui/icons-material/Stop';

const App = () => {
  const [presses, setPresses] = useState([]);
  const holdThreshold = 5000; // 5 seconds
  const holdTimer = useRef(null);

  const handleMouseDown = (direction) => {
    holdTimer.current = setTimeout(() => {
      handleButtonClick(direction);
    }, holdThreshold);
  };

  const handleMouseUp = (direction) => {
    clearTimeout(holdTimer.current);
    handleButtonClick(direction);
  };

  const handleButtonClick = (direction) => {
    setPresses(prevPresses => [...prevPresses, direction]);
    // debugging feature, remove when we are pushing final product    o
    console.log(`Button pressed: ${direction}`);
  };

  return (
    <>
      <MoveAroundButtons 
        handleMouseDown={handleMouseDown}
        handleMouseUp={handleMouseUp}
        handleButtonClick={handleButtonClick}
      />
      <DirectionList presses={presses} />
    </>
  );
};


const MoveAroundButtons = ({ handleMouseDown, handleMouseUp, handleButtonClick }) => (
  <Stack direction="column" alignItems="center" spacing={2}>
    <Button 
      variant="contained" 
      color="primary" 
      onMouseDown={() => handleMouseDown('up')}
      onMouseUp={() => handleMouseUp('up')}
    >
      <ArrowUpwardIcon fontSize="large" />
    </Button>

    <Stack direction="row" spacing={2} justifyContent="center">
      <Button 
        variant="contained" 
        color="primary" 
        onMouseDown={() => handleMouseDown('left')}
        onMouseUp={() => handleMouseUp('left')}
      >
        <ArrowBackIcon fontSize="large" />
      </Button>
      <Button 
        variant="contained" 
        color="primary" 
        onMouseDown={() => handleMouseDown('down')}
        onMouseUp={() => handleMouseUp('down')}
      >
        <ArrowDownwardIcon fontSize="large" />
      </Button>
      <Button 
        variant="contained" 
        color="primary" 
        onMouseDown={() => handleMouseDown('right')}
        onMouseUp={() => handleMouseUp('right')}
      >
        <ArrowForwardIcon fontSize="large" />
      </Button>
    </Stack>

    <Button 
      variant="contained" 
      color="secondary" 
      onClick={() => handleButtonClick('stop')}
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


export default App;

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
    <div>
      <Stack direction="column" alignItems="center" spacing={2}>
  {/* Arrow buttons */}
  <Stack direction="row" spacing={2} alignItems="center">
    <Stack direction="column" alignItems="center" spacing={2}>
      <Button 
        variant="contained" 
        color="primary" 
        onMouseDown={() => handleMouseDown('up')}
        onMouseUp={() => handleMouseUp('up')}
      >
        <ArrowUpwardIcon fontSize="large" />
      </Button>
      <Stack direction="row" spacing={2}>
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
    </Stack>

    {/* Stop button placed to the right */}
    <Stack direction="row" spacing={2} alignItems="center">
      <Button 
        variant="contained" 
        color="secondary" 
        onClick={() => handleButtonClick('stop')}
      >
        <StopIcon fontSize="large" />
      </Button>
      <span>Stop the machine</span>
    </Stack>
  </Stack>
</Stack>

      
      <div>
        <h3>Button Presses:</h3>
        <ul>
          {presses.map((press, index) => (
            <li key={index}>{press}</li>
          ))}
        </ul>
      </div>
    </div>
  );
};

export default App;

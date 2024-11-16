import React from 'react';
import Button from '@mui/material/Button';
import Stack from '@mui/material/Stack';
import ArrowBackIcon from '@mui/icons-material/ArrowBack';
import ArrowDownwardIcon from '@mui/icons-material/ArrowDownward';
import ArrowUpwardIcon from '@mui/icons-material/ArrowUpward';
import ArrowForwardIcon from '@mui/icons-material/ArrowForward';
import StopIcon from '@mui/icons-material/Stop';

const MoveAroundButtons = ({ handleMouseDown, handleMouseUp, handleButtonClick }) => (
  <Stack direction="column" alignItems="center" spacing={2}>
    <Button variant="contained" color="primary" onMouseDown={() => handleMouseDown('Forward')} onMouseUp={() => handleMouseUp('Forward')}>
      <ArrowUpwardIcon fontSize="large" />
    </Button>
    <Stack direction="row" spacing={2} justifyContent="center">
      <Button variant="contained" color="primary" onMouseDown={() => handleMouseDown('Left')} onMouseUp={() => handleMouseUp('Left')}>
        <ArrowBackIcon fontSize="large" />
      </Button>
      <Button variant="contained" color="primary" onMouseDown={() => handleMouseDown('Backward')} onMouseUp={() => handleMouseUp('Backward')}>
        <ArrowDownwardIcon fontSize="large" />
      </Button>
      <Button variant="contained" color="primary" onMouseDown={() => handleMouseDown('Right')} onMouseUp={() => handleMouseUp('Right')}>
        <ArrowForwardIcon fontSize="large" />
      </Button>
    </Stack>
    <Button variant="contained" color="secondary" onClick={() => handleButtonClick('Stop')}>
      <StopIcon fontSize="large" />
    </Button>
    <span>Stop the machine</span>
  </Stack>
);

export default MoveAroundButtons;

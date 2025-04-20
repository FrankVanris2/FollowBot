import React from 'react';
import Button from '@mui/material/Button';
import Stack from '@mui/material/Stack';
import ArrowBackIcon from '@mui/icons-material/ArrowBack';
import ArrowDownwardIcon from '@mui/icons-material/ArrowDownward';
import ArrowUpwardIcon from '@mui/icons-material/ArrowUpward';
import ArrowForwardIcon from '@mui/icons-material/ArrowForward';
import StopIcon from '@mui/icons-material/Stop';

const MoveAroundButtons = ({ handleMouseDown, handleMouseUp, handleButtonClick, disabled }) => (
  <Stack direction="column" alignItems="center" spacing={2}>
    <Button variant="contained" color="primary" onMouseDown={() => handleMouseDown('Forward')} onMouseUp={() => handleMouseUp('Forward')} disabled={disabled}>
      <ArrowUpwardIcon fontSize="large" />
    </Button>
    <Stack direction="row" spacing={2} justifyContent="center">
      <Button variant="contained" color="primary" onMouseDown={() => handleMouseDown('Left')} onMouseUp={() => handleMouseUp('Left')} disabled={disabled}>
        <ArrowBackIcon fontSize="large" />
      </Button>
      <Button variant="contained" color="primary" onMouseDown={() => handleMouseDown('Backward')} onMouseUp={() => handleMouseUp('Backward')} disabled={disabled}>
        <ArrowDownwardIcon fontSize="large" />
      </Button>
      <Button variant="contained" color="primary" onMouseDown={() => handleMouseDown('Right')} onMouseUp={() => handleMouseUp('Right')} disabled={disabled}>
        <ArrowForwardIcon fontSize="large" />
      </Button>
    </Stack>
    <Button variant="contained" color="secondary" onClick={() => handleButtonClick('Stop')} disabled={disabled}>
      <StopIcon fontSize="large" />
    </Button>
  </Stack>
);

export default MoveAroundButtons;

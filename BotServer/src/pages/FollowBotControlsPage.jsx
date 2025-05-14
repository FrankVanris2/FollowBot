import React, { useState, useEffect, useRef } from 'react';
import Button from '@mui/material/Button';
import Box from '@mui/material/Box';
import MoveAroundButtons from '../components/MoveAroundButtons';
import TemperatureDisplay from '../components/TemperatureDisplay';
import HeatIndexDisplay from '../components/HeatIndexDisplay';
import DirectionList from '../components/DirectionList';
import api from '../services/api';
import cameradisconnected from '../res/cameradisconnected.jpg';
import '../styles/FollowBotControlsPage.style.css'; // Import the CSS file

const MANUAL = 'MANUAL';
const FOLLOWING = 'FOLLOWING';

const FollowBotControlsPage = () => {
    const [presses, setPresses] = useState([]);
    const [temperature, setTemperature] = useState(null);
    const [heatIndex, setHeatIndex] = useState(null);
    const [controlMode, setControlMode] = useState('FOLLOWING');
    const holdThreshold = 5000; // 5 seconds
    const holdTimer = useRef(null);


    useEffect(() => {
        const fetchTemperature = async () => {
            try {
                const data = await api.getTemperature();
                if (data.temperature) {
                    setTemperature(data.temperature);
                }
            } catch (error) {
                console.error('Error fetching temperature data:', error);
            }
        };

        const fetchHeatIndex = async () => {
            try {
                const data = await api.getHeatIndex();
                if (data.heatIndex) {
                    setHeatIndex(data.heatIndex);
                }
            } catch (error) {
                console.error('Error fetching heat index data:', error);
            }
        };

        fetchTemperature();
        fetchHeatIndex();
    }, []);

    const toggleControlMode = async () => {
        setControlMode(controlMode === FOLLOWING ? MANUAL : FOLLOWING);
        handleButtonClick(controlMode === FOLLOWING ? MANUAL : FOLLOWING);

        try {
            await api.postModeChange(controlMode);
        } catch (e) {
            console.error();
        }
    }

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
        setPresses(prevPresses => [direction]);
        try {
            await api.postMovement(direction);
        } catch (exc) {
            console.error('Exception:', exc);
        }
    };

    return (
        <div>
            <h1 className="header">FollowBot Controls (Demo)</h1>
            <div className="container">
                <div className="button-wrapper">
                    <Box mb={10}>
                        <Button variant="contained" onClick={toggleControlMode}>
                            {controlMode === FOLLOWING ? 'User Control' : 'Robot Control'}
                        </Button>
                    </Box>  

                    <MoveAroundButtons 
                        handleMouseDown={handleMouseDown}
                        handleMouseUp={handleMouseUp}
                        handleButtonClick={handleButtonClick}
                        disabled={controlMode === FOLLOWING}
                    />
                    <DirectionList presses={presses} />
                </div>

                {/* <div className="image-wrapper">
                    <span className="live-feed-text">Live Feed</span>
                    <img 
                        src={cameradisconnected}
                        alt="Camera disconnected"
                        style={{ width: '600px', height: '400px' }}
                    />
                </div> */}

                {/* <div className="temperature-wrapper">
                    <div className="info-wrapper">
                        <h2>Current Temperature</h2>
                        <TemperatureDisplay temperature={temperature} />
                        <h2>Heat Index</h2>
                        <HeatIndexDisplay heatIndex={heatIndex} />
                    </div>
                </div> */}
            </div>
        </div>
    );
};

export default FollowBotControlsPage;

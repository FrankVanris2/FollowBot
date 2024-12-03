// src/pages/MoveControlsPage.js
import React, { useState, useEffect, useRef } from 'react';
import MoveAroundButtons from '../components/MoveAroundButtons'; // Move Around Buttons component
import TemperatureDisplay from '../components/TemperatureDisplay'; // Temperature Display component
import HeatIndexDisplay from '../components/HeatIndexDisplay'; // Heat Index Display component
import DirectionList from '../components/DirectionList'; // List of directions
import api from '../services/api'; // API service
import cameradisconnected from './res/cameradisconnected.jpg'; // Ensure the correct path to the image
import { Header, Container, ImageWrapper, Image, LiveFeedText, ButtonWrapper, InfoWrapper, TemperatureWrapper } from './FollowBotControlsPage.style';

const FollowBotControlsPage = () => {
    const [presses, setPresses] = useState([]);
    const [temperature, setTemperature] = useState(null);
    const [heatIndex, setHeatIndex] = useState(null);
    const holdThreshold = 5000; // 5 seconds
    const holdTimer = useRef(null);

    useEffect(() => {
        const fetchTemperature = async () => {
            try {
                const data = await api.getTemperature();
                console.log(data);
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
                console.log(data);
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
        console.log(`Button pressed: ${direction}`);
        try {
            await api.postMovement(direction);
        } catch (exc) {
            console.error('Exception:', exc);
        }
    };

    return (
        <div>
            <Header>FollowBot Controls (Demo)</Header>
            <Container>
                <ButtonWrapper>
                    <MoveAroundButtons 
                        handleMouseDown={handleMouseDown}
                        handleMouseUp={handleMouseUp}
                        handleButtonClick={handleButtonClick}
                    />
                    <DirectionList presses={presses} />
                </ButtonWrapper>
                <ImageWrapper>
                    <LiveFeedText>Live Feed</LiveFeedText>
                    <Image 
                        src={cameradisconnected}
                        alt="Camera disconnected"
                    />
                </ImageWrapper>
                <TemperatureWrapper>
                    <h2>Current Temperature</h2>
                    <TemperatureDisplay temperature={temperature} />
                    <h2>Heat Index</h2>
                    <HeatIndexDisplay heatIndex={heatIndex} />
                </TemperatureWrapper>
            </Container>
        </div>
    );
};

export default FollowBotControlsPage;





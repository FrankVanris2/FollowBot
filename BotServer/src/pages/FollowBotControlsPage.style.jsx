import styled from 'styled-components';

export const Header = styled.h2`
    display: flex;
    justify-content: flex-start;
`;

export const Container = styled.div`
    display: flex;
    align-items: flex-start; /* Align items to the start (top) */
    justify-content: center; /* Center items horizontally */
    gap: 15px;
    padding: 20px;
`;

export const ImageWrapper = styled.div`
    position: relative;
    border: 2px solid black;
    background-color: lightgray;
    padding: 20px 10px 10px 10px; /* Increase the padding at the top to make space for "Live Feed" */
    border-radius: 10px;
    display: inline-block;
`;

export const Image = styled.img`
    width: 600px;
    height: 400px;
`;

export const LiveFeedText = styled.div`
    position: absolute;
    top: 4px; /* Adjust the top position to be within the increased padding */
    left: 10px;
    font-weight: bold;
    color: black;
`;

export const ButtonWrapper = styled.div`
    border: 2px solid black;
    background-color: lightgray;
    padding: 10px;
    border-radius: 10px;
    display: inline-block;
    margin-right: 20px; /* Add some space between the buttons and the other information */
`;

export const InfoWrapper = styled.div`
    display: flex;
    flex-direction: column;
    gap: 10px;
`;

export const TemperatureWrapper = styled.div`
    border: 2px solid black;
    background-color: lightgray;
    padding: 10px;
    border-radius: 10px;
    display: flex;
    flex-direction: column;
    align-items: center; /* Center content horizontally */
    justify-content: center; /* Center content vertically */
    width: 200px; /* Adjust the width as needed */
    margin-left: auto; /* Push to the far right */
`;



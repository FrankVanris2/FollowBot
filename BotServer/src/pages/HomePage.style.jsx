import styled from 'styled-components';

export const HomePageContainer = styled.div`
    display: flex;
    justify-content: space-between;
    align-items: flex-start;
    padding: 20px;
    background-color: #d3d3d3;
    font-family: 'Arial', sans-serif;
`;

export const ContentBox = styled.div`
    display: flex;
    gap: 20px;
    align-items: flex-start;
    max-width: 70%;
`;

export const FollowbotImage = styled.img`
    max-width: 300px;
    border: 2px solid #000;
    border-radius: 10px;
`;

export const TextContent = styled.div`
    max-width: 400px;
    color: #000;
`;

export const Title = styled.h1`
    font-size: 2rem;
    font-weight: bold;
    margin-bottom: 10px;
`;

export const Description = styled.p`
    font-size: 1rem;
    margin-bottom: 15px;
`;

export const ExtraInfo = styled.p`
    font-size: 1rem;
    margin-bottom: 20px;
`;

export const LearnMore = styled.a`
    display: flex;
    align-items: center;
    text-decoration: none;
    color: #000;
    font-weight: bold;
    font-size: 1rem;
    gap: 5px;
`;

export const Arrow = styled.span`
    font-size: 1.5rem;
`;


export const VideoBoxContainer = styled.div`
    width: 600px; /* Fixed width */
    height: 300px;
    display: flex;
    flex-direction: column;
    aligh-items: center; /* Center align text underneath */
`
export const VideoBox = styled.div`
    width: 100% /* Ensure the width is 500px */
    height: 100%;
    background-color: #000;
    color: #fff;
    text-align: center;
    border-radius: 10px;
    padding: 150px;
    display: flex;
    justify-content: center;
    align-items: center; 
`;

export const VideoPlaceholder = styled.div`
    width: 100%;
    height: 100%;
    font-size: 1.5rem;
    font-weight: bold;
    justify-content: center;
    align-items: center;
`;

export const VideoDescription = styled.p`
    color: #000;
    font-size: 1rem;
    text-align: center;
    margin-top: 10px;
    width: 100%;
`;


import styled from 'styled-components';

export const Container = styled.div`
    width: 90%;
    margin: 0 auto;
    text-align: center;
    font-family: 'Arial', sans-serif;
    background-color: #f4f4f4;
    padding: 20px;
    border-radius: 10px;
`;

export const Heading = styled.h1`
    font-size: 2em;
    font-weight: bold;
    margin-bottom: 10px;
`;

export const Subheading = styled.p`
    font-size: 1.2em;
    color: #555;
    margin-bottom: 30px;
`;

export const Grid = styled.div`
    display: flex;
    justify-content: space-around;
    align-items: center;
    flex-wrap: wrap;
    gap: 20px;
`;

export const Profile = styled.div`
    text-align: center;
    background-color: #fff;
    padding: 15px;
    border-radius: 10px;
    box-shadow: 0px 2px 5px rgba(0, 0, 0, 0.1);
    width: 200px;
`;

export const ProfileImage = styled.img`
    width: 100%;
    height: auto;
    border-radius: 50%;
    margin-bottom: 10px;
`;

export const ProfileName = styled.div`
    font-size: 1.2em;
    font-weight: bold;
    margin-bottom: 5px;
`;

export const ProfileDescription = styled.div`
    font-size: 1em;
    color: #777;
    margin-bottom: 10px;
`;

export const ProfileLinkedIn = styled.a`
    font-size: 0.9em;
    color: #0073b1;
    text-decoration: none;
`;

import React from 'react';
import {
    HomePageContainer,
    ContentBox,
    FollowbotImage,
    TextContent,
    Title,
    Description,
    ExtraInfo,
    LearnMore,
    Arrow,
    VideoBoxContainer,
    VideoBox,
    VideoPlaceholder,
    VideoDescription
} from './HomePage.style'; // Import styled-components

import prototype from '../res/FollowBotPrototype.png';

import { Link } from 'react-router-dom';

const HomePage = () => {
    return (
        <HomePageContainer>
            <ContentBox>
                <FollowbotImage src={prototype} alt="FollowBot Prototype" />
                <TextContent>
                    <Title>FollowBot</Title>
                    <Description>
                        A device that will be able to carry your belongings as well as map through
                        different locations. It is there to help the disadvantaged and is meant to be
                        used in safe public spaces.
                    </Description>
                    <ExtraInfo>
                        It is there to help you when you are in need. It will always be by your side.
                    </ExtraInfo>
                    <LearnMore as={Link} to="/AboutFollowBotPage">
                        <Arrow>→</Arrow> Learn More
                    </LearnMore>
                </TextContent>
            </ContentBox>
            <VideoBoxContainer>
                <VideoBox>
                    <VideoPlaceholder>
                        Video of FollowBot
                    </VideoPlaceholder>
                </VideoBox>
                <VideoDescription>
                    This is a demonstration of the FollowBot in action.
                </VideoDescription>
            </VideoBoxContainer>
            
        </HomePageContainer>
    );
};

export default HomePage;



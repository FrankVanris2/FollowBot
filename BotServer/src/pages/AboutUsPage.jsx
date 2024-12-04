import React from 'react';
import Joseph from "./res/placeholder1.png";
import Igor from "./res/IgorJanotti.png";
import Frank from "./res/FrankVanris.png";
import Trong from "./res/TrongDuong.png";
import { Container, Heading, Subheading, Grid, Profile, ProfileImage, ProfileName, ProfileDescription, ProfileLinkedIn } from './AboutUsPage.style';

const AboutUsPage = () => {
    const teamMembers = [
        {
            name: "Igor",
            photo: Igor,
            description: "Warhammer Annihilator",
            LinkedIn: "https://www.linkedin.com/in/igor-janotti-1613ba193/"
        },
        {
            name: "Frank",
            photo: Frank,
            description: "He's Embedded in the System",
            LinkedIn: "http://linkedin.com/in/frankcvanris"
        },
        {
            name: "Trong",
            photo: Trong,
            description: "Vim Enthusiast",
            LinkedIn: "http://linkedin.com/in/frankcvanris"
        },
        {
            name: "Joseph",
            photo: Joseph,
            description: "Hopelessly in love with FollowBot",
            LinkedIn: "http://linkedin.com/in/frankcvanris"
        },
    ];

    return (
        <Container>
            <Heading>We are the CarryWithMe Team!</Heading>
            <Subheading>
                We are a dedicated group of students aiming to bring robotics to the forefront, 
                especially for those in need. As members of the CarryWithMe team, we strive to ensure 
                that the robotics we provide are both beneficial and affordable for all consumers.
            </Subheading>
            <h2>Meet our team members!</h2>
            <Grid>
                {teamMembers.map((member) => (
                    <Profile key={member.name}>
                        <ProfileImage
                            src={member.photo}
                            alt={`${member.name}'s photo`}
                        />
                        <ProfileName>{member.name}</ProfileName>
                        <ProfileDescription>{member.description}</ProfileDescription>
                        <ProfileLinkedIn
                            href={member.LinkedIn}
                            target="_blank"
                            rel="noopener noreferrer"
                        >
                            LinkedIn Profile
                        </ProfileLinkedIn>
                    </Profile>
                ))}
            </Grid>
        </Container>
    );
};

export default AboutUsPage;

import React from 'react';
import Joseph from "../res/Norman.png";
import Igor from "../res/IgorJanotti.png";
import Frank from "../res/FrankVanris.png";
import Trong from "../res/TrongDuong.png";
import '../styles/FeedbackPage.css';

const AboutUsPage = () => {
    const teamMembers = [
        {
            name: "Trong Duong",
            photo: Trong,
            description: "Vim Enthusiast\nLoves vim too much...",
            LinkedIn: "#"
        },
        {
            name: "Igor Janotti",
            photo: Igor,
            description: "Warhammer Annihilator\nLoves to program, but will destroy every faction for the emperor.",
            LinkedIn: "https://www.linkedin.com/in/igor-janotti-1613ba193/"
        },
        {
            name: "Joseph Hoang",
            photo: Joseph,
            description: "Hopelessly in love with FollowBot\nLoves FollowBot so much, we couldn’t stop him from staying away from it!",
            LinkedIn: "#"
        },
        {
            name: "Frank Vanris",
            photo: Frank,
            description: "Frank is embedded in the System.\nWhen an expedition occurs I am gone for a day.",
            LinkedIn: "http://linkedin.com/in/frankcvanris"
        },
    ];

    return (
        <div className="about-container">
            <h1 className="about-heading">We are the CarryWithMe Team!</h1>
            <p className="about-subheading">
                We are a dedicated group of students aiming to bring robotics to the forefront, especially for those in need.
                As members of the Carry With Me team, we strive to ensure that the robotics we provide are both beneficial and affordable
                for all consumers. This means utilizing technology that is efficient, reliable, and accessible to everyone.
                We are committed to continuous learning and expanding our knowledge within the robotics and technology fields.
            </p>
            <h2 className="about-team-title">Meet our team members!</h2>
            <div className="team-grid">
                {teamMembers.map((member) => (
                    <div key={member.name} className="team-profile">
                        <img className="team-photo" src={member.photo} alt={`${member.name}'s photo`} />
                        <h3 className="team-name">{member.name}</h3>
                        <p className="team-description">{member.description}</p>
                        {member.LinkedIn !== "#" && (
                            <a className="team-linkedin" href={member.LinkedIn} target="_blank" rel="noopener noreferrer">
                                LinkedIn Profile
                            </a>
                        )}
                    </div>
                ))}
            </div>
        </div>
    );
};

export default AboutUsPage;

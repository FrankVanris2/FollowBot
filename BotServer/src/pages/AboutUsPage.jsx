import React from 'react';

// import image folders 
import Joseph from "./res/placeholder1.png";
import Igor from "./res/IgorJanotti.png";
import Frank from "./res/FrankVanris.png";
import Trong from "./res/TrongDuong.png";
import '../styles/AboutUsStyle.css';


const AboutUsPage = () => {
    const teamMembers = [
        {
            name: "Igor",
            photo: Igor,
            description: "Warhammer Annihilator",
            LinkedIn:  "https://www.linkedin.com/in/igor-janotti-1613ba193/"
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
        <div className="container">
            <h1 className="heading">We are the CarryWithMe Team!</h1>
            <p className="subheading">
                We are a dedicated group of students aiming to bring robotics to the forefront, 
                especially for those in need. As members of the CarryWithMe team, we strive to ensure 
                that the robotics we provide are both beneficial and affordable for all consumers.
            </p>
            <h2>Meet our team members!</h2>
            <div className="grid">
                {teamMembers.map((member) => (
                    <div key={member.name} className="profile">
                        <img
                            src={member.photo}
                            alt={`${member.name}'s photo`}
                            className="profile-image"
                        />
                        <div className="profile-name">{member.name}</div>
                        <div className="profile-description">{member.description}</div>
                        <a
                            href={member.LinkedIn}
                            className="profile-linkedin"
                            target="_blank"
                            rel="noopener noreferrer"
                        >
                            LinkedIn Profile
                        </a>
                    </div>
                ))}
            </div>
        </div>
    );
};

export default AboutUsPage;

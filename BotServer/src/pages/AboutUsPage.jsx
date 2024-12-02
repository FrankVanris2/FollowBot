import React from 'react';
// import image folders 
import placeholder1 from "./res/placeholder1.png" ;
import "../styles/AboutUsStyle.css";

const AboutUsPage = () => {
    const teamMembers = [
        {
            name: "Igor",
            photo: placeholder1,
            description: "placeholder",
            LinkedIn:  "https://www.linkedin.com/in/igor-janotti-1613ba193/"
        },
        {
            name: "Frank",
            photo: placeholder1,
            description: "placeholder",
            LinkedIn: "http://linkedin.com/in/frankcvanris"
        },
        {
            name: "Trong",
            photo: placeholder1,
            description: "placeholder",
            LinkedIn: "http://linkedin.com/in/frankcvanris"
        },
        {
            name: "Joseph",
            photo: placeholder1,
            description: "placeholder",
            LinkedIn: "http://linkedin.com/in/frankcvanris"
        }
    ];


    return (
        <div style={containerStyle}>
            <h1 style={headingStyle}>We are the CarryWithMe Team!</h1>
            <p style={subheadingStyle}>
                We are a dedicated group of students aiming to bring robotics to the forefront, 
                especially for those in need. As members of the CarryWithMe team, we strive to ensure 
                that the robotics we provide are both beneficial and affordable for all consumers.
            </p>
            <h2>Meet our team members!</h2>
            <div style={gridStyle}>
                {teamMembers.map((member) => (
                    <div key={member.name} style={profileStyle}>
                        <img
                            src={member.photo}
                            alt={`${member.name}'s photo`}
                            style={imageStyle}
                        />
                        <div style={nameStyle}>{member.name}</div>
                        <div style={titleStyle}>{member.title}</div>
                        <div style={descriptionStyle}>{member.description}</div>
                        <a
                            href={member.LinkedIn}
                            style={linkedInStyle}
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

import React from 'react';
// import image folders 
import Joseph from "./res/placeholder1.png";
import Igor from "./res/IgorJanotti.png";
import Frank from "./res/FrankVanris.png";
import Trong from "./res/TrongDuong.png";

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
        }
    ];

    const containerStyle = {
        width: "90%",
        margin: "0 auto",
        textAlign: "center",
        fontFamily: "'Arial', sans-serif",
        backgroundColor: "#f4f4f4",
        padding: "20px",
        borderRadius: "10px",
    };

    const headingStyle = {
        fontSize: "2em",
        fontWeight: "bold",
        marginBottom: "10px",
    };

    const subheadingStyle = {
        fontSize: "1.2em",
        color: "#555",
        marginBottom: "30px",
    };

    const gridStyle = {
        display: "flex",
        justifyContent: "space-around",
        alignItems: "center",
        flexWrap: "wrap",
        gap: "20px",
    };

    const profileStyle = {
        width: "220px",
        textAlign: "center",
        backgroundColor: "#fff",
        padding: "15px",
        borderRadius: "8px",
        boxShadow: "0 4px 8px rgba(0, 0, 0, 0.1)",
    };

    const imageStyle = {
        width: "100px",
        height: "100px",
        borderRadius: "50%",
        objectFit: "cover",
        marginBottom: "10px",
    };

    const nameStyle = {
        fontSize: "1.2em",
        fontWeight: "bold",
        marginBottom: "5px",
    };

    const titleStyle = {
        fontSize: "1em",
        color: "#666",
        fontStyle: "italic",
        marginBottom: "10px",
    };

    const descriptionStyle = {
        fontSize: "0.9em",
        color: "#333",
        marginBottom: "10px",
    };

    const linkedInStyle = {
        display: "inline-block",
        textDecoration: "none",
        color: "#0077B5",
        fontWeight: "bold",
        fontSize: "0.9em",
        marginTop: "10px",
    };

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

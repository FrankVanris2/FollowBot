import React from 'react';
import placeholder1 from "./res/placeholder1.png" ;

const AboutUsPage = () => {
    const teamMembers = [
        {
            name: "Igor",
            photo: placeholder1,
            description: "ABC"
        },
        {
            name: "Drank",
            photo: placeholder1,
            description: "DEF"
        },
        {
            name: "Trong",
            photo: placeholder1,
            description: "GHI"
        },
        {
            name: "Norman",
            photo: placeholder1,
            description: "JKL"
        }
    ];

    const gridStyle = {
        display: "grid",
        gridTemplateColumns: "1fr 1fr",
        gap: "20px",
    };

    const imageStyle = {
        width: "150px",
        height: "150px",
        borderRadius: "8px",
    };

    const descriptionStyle = {
        fontSize: "14px",
    };

    return (
        <div className="container">
            <h1>AboutUs</h1>
            <div style={gridStyle}>
                {teamMembers.map((member, index) => (
                    <div key={index}>
                        <img
                            src={member.photo}
                            alt={`${member.name}'s phot`}
                            style={imageStyle}
                        />
                        <h3>{member.name}</h3>
                        <p style={descriptionStyle}>{member.description}</p>
                    </div>
                ))}
            </div>
        </div>
    );
};

export default AboutUsPage;

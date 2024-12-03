import React from 'react';
import placeholder1 from './res/placeholder1.png';
import '../styles/AboutUsStyle.css';

const AboutUsPage = () => {
    const teamMembers = [
        {
            name: 'Igor',
            photo: placeholder1,
            description: 'Placeholder description for Igor',
            LinkedIn: 'https://www.linkedin.com/in/igor-janotti-1613ba193/'
        },
        {
            name: 'Frank',
            photo: placeholder1,
            description: 'Placeholder description for Frank',
            LinkedIn: 'http://linkedin.com/in/frankcvanris'
        },
        {
            name: 'Trong',
            photo: placeholder1,
            description: 'Placeholder description for Trong',
            LinkedIn: 'http://linkedin.com/in/frankcvanris'
        },
        {
            name: 'Joseph',
            photo: placeholder1,
            description: 'Placeholder description for Joseph',
            LinkedIn: 'http://linkedin.com/in/frankcvanris'
        }
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

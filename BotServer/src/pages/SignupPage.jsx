import React, { useState } from 'react'
import api from '../services/api';

const Signup = () => {
    const [formData, setFormData] = useState({
        username: '',
        email: '',
        password: '',
        phone_number: '',
        business_id: '',
        privacy_consent: false,
    });

    const [responseMessage, setResponseMessage] = useState('');

    const handleChange = (event) => {
        const { name, value, type, checked } = event.target;
        setFormData((prevData) => ({
            ...prevData,       // create a copy of existing state
            [name]: type === 'checkbox' ? checked : value,
        }));
    }

    const handleSubmit = async (event) => {
        event.preventDefault(); // stops default form submission
        try {
            const response = api.postSignUp(formData);

            if (response.error) {
                setResponseMessage(`Error: ${response.error}`);
            } else {
                setResponseMessage(`Success: ${response.message}`);
            }
        } catch (error) {
            console.error('Error signing up: ', error)
            setResponseMessage('Failed to sign up due to a server error.')
        }
    }

    return (
        <div>
            <h2>Sign Up</h2>

            <form onSubmit={handleSubmit}>
                <label>
                    Username:
                    <input
                        type="text"
                        name="username"
                        value={formData.username}
                        onChange={handleChange}
                        required
                        style={{ marginLeft: '10px' }}
                    />
                </label>
                <br/>
                <label>
                    Email:
                    <input
                        type="email"
                        name="email"
                        value={formData.email}
                        onChange={handleChange}
                        required
                        style={{ marginLeft: '10px' }}
                    />
                </label>
                <br/>
                <label>
                    Password:
                    <input
                        type="password"
                        name="password"
                        value={formData.password}
                        onChange={handleChange}
                        required
                        style={{ marginLeft: '10px' }}
                    />
                </label>
                <br/>
                <label>
                    Phone Number:
                    <input
                        type="text"
                        name="phone_number"
                        value={formData.phone_number}
                        onChange={handleChange}
                        style={{ marginLeft: '10px' }}
                    />
                </label>
                <br/>
                <label>
                    Business ID:
                    <input
                        type="text"
                        name="business_id"
                        value={formData.business_id}
                        onChange={handleChange}
                        style={{ marginLeft: '10px' }}
                    />
                </label>
                <br/>
                <label>
                    <input
                        type="checkbox"
                        name="privacy_consent"
                        checked={formData.privacy_consent}
                        onChange={handleChange}
                    />
                    I consent to my FollowBot's data being used for improving precision and calibrations.
                </label>
                <br/>
                <button type="submit">Sign Up</button>
            </form>

            {responseMessage && <p>{responseMessage}</p>}

        </div>
    );
};

export default Signup
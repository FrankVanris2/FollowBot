import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { Box, Button, Checkbox, FormControlLabel, TextField, Typography, Link, Paper } from '@mui/material';
import api from '../services/api';
// Commenting out OtpForm temporarily
// import OtpForm from './OtpForm';

const Signup = () => {
  const navigate = useNavigate();
  const [formData, setFormData] = useState({
    username: '',
    email: '',
    password: '',
    phone_number: '',
    business_id: '',
    privacy_consent: false,
  });
  const [showOtp, setShowOtp] = useState(false);
  const [responseMessage, setResponseMessage] = useState({ type: '', text: '' });

  const handleChange = (event) => {
    const { name, value, type, checked } = event.target;
    setFormData(prev => ({
      ...prev,
      [name]: type === 'checkbox' ? checked : value
    }));
  };

  const handleSubmit = async (event) => {
    event.preventDefault();
    try {
      const response = await api.postSignUp(formData);
      
      if (response.success) {
        setShowOtp(true);
        setResponseMessage({ type: 'success', text: 'Verification code sent to your email' });
      } else {
        setResponseMessage({ type: 'error', text: response.error });
      }
    } catch (error) {
      setResponseMessage({ type: 'error', text: 'Registration failed. Please try again.' });
    }
  };

  return (
    <Box sx={{ maxWidth: 400, mx: 'auto', mt: 4, p: 3 }}>
      <Paper sx={{ padding: 3 }}>
        <Typography variant="h4" gutterBottom>Sign Up</Typography>
        
        {!showOtp ? (
          <form onSubmit={handleSubmit}>
            <TextField
              fullWidth
              label="Username"
              name="username"
              value={formData.username}
              onChange={handleChange}
              margin="normal"
              required
            />
            
            <TextField
              fullWidth
              label="Email"
              type="email"
              name="email"
              value={formData.email}
              onChange={handleChange}
              margin="normal"
              required
            />
            
            <TextField
              fullWidth
              label="Password"
              type="password"
              name="password"
              value={formData.password}
              onChange={handleChange}
              margin="normal"
              required
            />
            
            <TextField
              fullWidth
              label="Phone Number"
              name="phone_number"
              value={formData.phone_number}
              onChange={handleChange}
              margin="normal"
            />
            
            <TextField
              fullWidth
              label="Business ID"
              name="business_id"
              value={formData.business_id}
              onChange={handleChange}
              margin="normal"
            />
            
            <FormControlLabel
              control={
                <Checkbox
                  name="privacy_consent"
                  checked={formData.privacy_consent}
                  onChange={handleChange}
                  required
                />
              }
              label="I consent to data usage for service improvements"
            />
            
            <Button 
              fullWidth 
              variant="contained" 
              type="submit"
              sx={{ mt: 2 }}
            >
              Register
            </Button>
          </form>
        ) : (
          // Temporarily disable OtpForm
          // <OtpForm 
          //   email={formData.email}
          //   onSuccess={() => navigate('/dashboard')}  // Ensure '/dashboard' is defined
          //   onResend={() => api.resendOtp(formData.email)}
          // />
          <Typography variant="body1" sx={{ mt: 2 }}>Please check your email for the verification code.</Typography>
        )}
        
        {responseMessage.text && (
          <Typography 
            color={responseMessage.type === 'error' ? 'error' : 'success'}
            sx={{ mt: 2 }}
          >
            {responseMessage.text}
          </Typography>
        )}
        
        <Typography sx={{ mt: 2 }}>
          Already have an account? <Link href="/login">Login here</Link>
        </Typography>
      </Paper>
    </Box>
  );
};

export default Signup;

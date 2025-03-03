import React from 'react';
import Box from '@mui/material/Box';
import TextField from '@mui/material/TextField';
import Button from '@mui/material/Button';

const LoginForm = ({ username, password, handleUsernameChange, handlePasswordChange, handleSubmit }) => {
    return (
        <Box component="form" onSubmit={handleSubmit} sx={{ display: 'flex', flexDirection: 'column' }}>
            <TextField
                label="Username"
                value={username}
                onChange={handleUsernameChange}
                onKeyDown={(evt) => evt.stopPropagation()}
                variant="outlined"
                margin="normal"
                size="small"
            />
            <TextField
                label="Password"
                value={password}
                onChange={handlePasswordChange}
                onKeyDown={(evt) => evt.stopPropagation()}
                variant="outlined"
                margin="normal"
                size="small"
            />
            <Button type="submit" variant="contained" color="primary" size="small">Login</Button>
        </Box>
    );
}

export default LoginForm;
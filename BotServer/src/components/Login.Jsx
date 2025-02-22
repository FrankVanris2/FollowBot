import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import Box from '@mui/material/Box';
import Avatar from '@mui/material/Avatar';
import Menu from '@mui/material/Menu';
import MenuItem from '@mui/material/MenuItem';
import ListItemIcon from '@mui/material/ListItemIcon';
import Divider from '@mui/material/Divider';
import IconButton from '@mui/material/IconButton';
import TextField from '@mui/material/TextField';
import Tooltip from '@mui/material/Tooltip';
import PersonAdd from '@mui/icons-material/PersonAdd';
import Settings from '@mui/icons-material/Settings';
import Logout from '@mui/icons-material/Logout';
import Button from '@mui/material/Button';

/**
 TODO: send login form to database
 TODO: change the dropdown menu after user is logged in
 TODO: create authifcations 

 */

const LoginForm = ({username, password, handleUsernameChange, handlePasswordChange, handleSubmit}) => {
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
    )
}


const AccountMenu = () => {
    const [anchorEl, setAnchorEl] = useState(null);
    const [username, setUsername] = useState('');
    const [password, setPassword] = useState('');
    const open = Boolean(anchorEl);

    const handleClick = (event) => { setAnchorEl(event.currentTarget); };
    const handleClose = () => { setAnchorEl(null); };

    const handleUsernameChange = (event) => { setUsername(event.target.value); };
    const handlePasswordChange = (event) => { setPassword(event.target.value); };

    // TODO: authentication
    const handleSubmit = (event) => {
        event.preventDefault();
        // Send the username and password to the login database
        // Example: axios.post('/api/login', { username, password })
        //setLoginInfo(`Username: ${username}, Password: ${password}`);
        console.log('Username:', username);
        console.log('Password:', password);
    };

    const navigate = useNavigate();
    // when user click it redirect them to other page 
    const handleSignupRedirect = () => {
        //    webpage 
        navigate('/signup') //   make page to return them 
    }

    const menuProps = {
        elevation: 0,
        sx: {
            mt: 1.5,
            '&:before': {
                content: '""',
                display: 'block',
                position: 'absolute',
                top: 0,
                right: 14,
                width: 10,
                height: 10,
                bgcolor: 'background.paper',
                transform: 'translateY(-50%) rotate(45deg)',
                zIndex: 0,
            },
        },
    };

    return (
        <React.Fragment>
            <Box sx={{ display: 'flex', alignItems: 'left', textAlign: 'center' }}>
                <Tooltip title="Account settings">
                    <IconButton
                        onClick={handleClick}
                        size="small"
                        sx={{ ml: 2 }}
                        aria-controls={open ? 'account-menu' : undefined}
                        aria-haspopup="true"
                        aria-expanded={open ? 'true' : undefined}
                    >
                        <Avatar sx={{ width: 32, height: 32 }}></Avatar>
                    </IconButton>
                </Tooltip>
            </Box>
            <Menu
                anchorEl={anchorEl}
                open={open}
                onClose={handleClose}
                disableAutoFocusItem
                PaperProps={menuProps}
                transformOrigin={{ horizontal: 'right', vertical: 'top' }}
                anchorOrigin={{ horizontal: 'right', vertical: 'bottom' }}
            >
                <MenuItem>
                    <LoginForm
                        username={username}
                        password={password}
                        handleUsernameChange={handleUsernameChange}
                        handlePasswordChange={handlePasswordChange}
                        handleSubmit={handleSubmit}
                    />
                </MenuItem>
                <Divider />


                <MenuItem onClick={handleSignupRedirect}>Sign Up</MenuItem>

                {/* TODO: IF SIGNED IN   make changes so parts of website appear and dispear when user signs   */}
                <MenuItem>
                    <ListItemIcon>
                        <PersonAdd fontSize="small" />
                    </ListItemIcon>
                    Add another account
                </MenuItem>
                <MenuItem>
                    <ListItemIcon>
                        <Settings fontSize="small" />
                    </ListItemIcon>
                    Settings
                </MenuItem>
                <MenuItem>
                    <ListItemIcon>
                        <Logout fontSize="small" />
                    </ListItemIcon>
                    Logout
                </MenuItem>
                {/* TODO: IF SIGNED IN */}

            </Menu>
        </React.Fragment>
    );
}

export default AccountMenu
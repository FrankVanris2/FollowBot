import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import Box from '@mui/material/Box';
import Avatar from '@mui/material/Avatar';
import Menu from '@mui/material/Menu';
import MenuItem from '@mui/material/MenuItem';
import ListItemIcon from '@mui/material/ListItemIcon';
import Divider from '@mui/material/Divider';
import IconButton from '@mui/material/IconButton';
import Tooltip from '@mui/material/Tooltip';
import PersonAdd from '@mui/icons-material/PersonAdd';
import Settings from '@mui/icons-material/Settings';
import Logout from '@mui/icons-material/Logout';
import LoginForm from './LoginForm.jsx';/// why does removing t casue a blank page
import AccountCircleIcon from '@mui/icons-material/AccountCircle';
import RuleIcon from '@mui/icons-material/Gavel';
import api from "../services/api";

const AccountMenu = () => {
    const [anchorEl, setAnchorEl] = useState(null);
    const [username, setUsername] = useState('');
    const [password, setPassword] = useState('');
    const [isSignedIn, setIsSignedIn] = useState(false); // Track login state
    const open = Boolean(anchorEl);

    const handleClick = (event) => setAnchorEl(event.currentTarget);
    const handleClose = () => setAnchorEl(null);

    const handleUsernameChange = (event) => setUsername(event.target.value);
    const handlePasswordChange = (event) => setPassword(event.target.value);

    const handleSubmit = async (event) => {
        event.preventDefault();
        try {
            const response = await api.postLogin({username, password});

            if (response.success) {
                setIsSignedIn(true);
            } else {
                console.error(response.error);
            }
            setAnchorEl(null);
        } catch (error) {
            console.error('Error during login:', error);
        }
    };

    const navigate = useNavigate();

    const handleSignupRedirect = () => {
        handleClose();
        navigate('/signup');
    };

    const handleLogout = async () => {
        try {
            const response = await api.postLogout();

            if (response.success) {
                setIsSignedIn(false);
                handleClose();
                navigate('/');  // dashboard
            } else {
                console.error(response.error);
            }
            handleClose()
        } catch (error) {
            console.error('Logout error:', error);
        }
    };

    const handleNavigate = (path) => {
        handleClose();
        navigate(path);
    };

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
                {!isSignedIn && (
                    <MenuItem>
                        <LoginForm
                            username={username}
                            password={password}
                            handleUsernameChange={handleUsernameChange}
                            handlePasswordChange={handlePasswordChange}
                            handleSubmit={handleSubmit}
                        />
                    </MenuItem>
                )}

                <Divider />

                {!isSignedIn && (
                    <MenuItem onClick={handleSignupRedirect}>
                        <ListItemIcon>
                            <PersonAdd fontSize="small" />
                        </ListItemIcon>
                        Sign Up
                    </MenuItem>
                )}

                {isSignedIn && [
                    <MenuItem key="profile" onClick={() => handleNavigate('/my-profile')}>
                        <ListItemIcon>
                            <AccountCircleIcon fontSize="small" />
                        </ListItemIcon>
                        My Profile
                    </MenuItem>,
                    <MenuItem key="rules" onClick={() => handleNavigate('/rules')}>
                        <ListItemIcon>
                            <RuleIcon fontSize="small" />
                        </ListItemIcon>
                        Rules
                    </MenuItem>,
                    <MenuItem key="settings" onClick={() => handleNavigate('/settings')}>
                        <ListItemIcon>
                            <Settings fontSize="small" />
                        </ListItemIcon>
                        Settings
                    </MenuItem>,
                    <MenuItem key="logout" onClick={handleLogout}>
                        <ListItemIcon>
                            <Logout fontSize="small" />
                        </ListItemIcon>
                        Logout
                    </MenuItem>
                ]}

            </Menu>
        </React.Fragment>
    );
};

export default AccountMenu;

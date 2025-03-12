// src/components/PasswordInputWithValidation.js untested !!!!!!!!!!!
import React, { useState } from "react";

const PasswordInputWithValidation = () => {
  const [password, setPassword] = useState("");
  const [errors, setErrors] = useState({
    minValueValidation: false,
    numberValidation: false,
    capitalLetterValidation: false,
    specialCharacterValidation: false,
  });

  // Handle password change
  const handlePasswordChange = (event) => {
    const newPassword = event.target.value;
    setPassword(newPassword);
    validatePassword(newPassword);
  };

  // Validate password based on rules
  const validatePassword = (password) => {
    setErrors({
      minValueValidation: password.length >= 8,
      numberValidation: /\d/.test(password),
      capitalLetterValidation: /[A-Z]/.test(password),
      specialCharacterValidation: /[^A-Za-z0-9]/.test(password),
    });
  };

  return (
    <div>
      <input
        type="password"
        value={password}
        onChange={handlePasswordChange}
        placeholder="Enter your password"
      />
      <ul>
        <li
          style={{
            color: errors.minValueValidation ? "green" : "red",
          }}
        >
          Minimum 8 characters
        </li>
        <li
          style={{
            color: errors.numberValidation ? "green" : "red",
          }}
        >
          At least one number
        </li>
        <li
          style={{
            color: errors.capitalLetterValidation ? "green" : "red",
          }}
        >
          At least one uppercase letter
        </li>
        <li
          style={{
            color: errors.specialCharacterValidation ? "green" : "red",
          }}
        >
          At least one special character
        </li>
      </ul>
    </div>
  );
};

export default PasswordInputWithValidation;

// src/components/OtpInputWithValidation.js
import React, { useState, useEffect, useRef } from "react";

function OtpInputWithValidation({ numberOfDigits, correctOTP }) {
  const [otp, setOtp] = useState(new Array(numberOfDigits).fill(""));
  const [otpError, setOtpError] = useState(null);
  const otpBoxReference = useRef([]);

  // Handle OTP input change
  function handleChange(value, index) {
    let newOtp = [...otp];
    newOtp[index] = value;
    setOtp(newOtp);

    if (value && index < numberOfDigits - 1) {
      otpBoxReference.current[index + 1].focus();
    }
  }

  // Handle backspace and enter functionality
  function handleBackspaceAndEnter(e, index) {
    if (e.key === "Backspace" && !e.target.value && index > 0) {
      otpBoxReference.current[index - 1].focus();
    }
    if (e.key === "Enter" && e.target.value && index < numberOfDigits - 1) {
      otpBoxReference.current[index + 1].focus();
    }
  }

  // Validate OTP and show error message
  useEffect(() => {
    if (otp.join("") !== "" && otp.join("") !== correctOTP) {
      setOtpError("❌ Wrong OTP. Please check again.");
    } else {
      setOtpError(null);
    }
  }, [otp, correctOTP]);

  return (
    <div>
      <div className="otp-input">
        {otp.map((d, i) => (
          <input
            key={i}
            type="text"
            maxLength="1"
            value={d}
            onChange={(e) => handleChange(e.target.value, i)}
            onKeyUp={(e) => handleBackspaceAndEnter(e, i)}
            ref={(el) => (otpBoxReference.current[i] = el)}
          />
        ))}
      </div>
      {otpError && <p>{otpError}</p>}
    </div>
  );
}

export default OtpInputWithValidation;

// TextBox.js
import React, { useState, useEffect } from 'react';

let player1initials = "";
let player2initials = "";

const TextBox = (props) => {
  const [value, setValue] = useState('');
  const { width, height, onValueChange } = props;
  const [firstInputGiven, setFirstInputGiven] = useState(false);

  const textBoxStyle = {
    width: width || '88px',
    height: height || '50px',
    flexShrink: 0,
  };

  useEffect(() => {
    // Check if the variable is empty, i.e., it's the first input
    if (firstInputGiven) {
      player2initials = value;
      onValueChange(player2initials); // Trigger label change
      setValue(''); // Clear the input value after processing
    }
  }, [firstInputGiven, value, onValueChange]);

  const handleKeyDown = (event) => {
    if (event.key === 'Enter') {
      event.preventDefault(); // Prevent the default Enter key behavior (e.g., form submission)

      // Check if the variable is empty, i.e., it's the first input
      if (!firstInputGiven) {
        setFirstInputGiven(true);
        player1initials = value;
      }
    }
  };

  return (
    <input
      type="text"
      maxLength={3}
      value={value}
      onChange={(event) => setValue(event.target.value)}
      onKeyDown={handleKeyDown}
      style={textBoxStyle}
    />
  );
};

export default TextBox;

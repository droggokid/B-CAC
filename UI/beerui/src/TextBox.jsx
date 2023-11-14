// TextBox.js
import React, { useState } from 'react';

export let player1initials = "";
export let player2initials = "";

const TextBox = (props) => {
  const [value, setValue] = useState('');
  const { onValueChange } = props;
  const [firstInputGiven, setFirstInputGiven] = useState(false);

  const handleKeyDown = (event) => {
    if (event.key === 'Enter') {
      event.preventDefault(); // Prevent the default Enter key behavior (e.g., form submission)

      // Check if the variable is empty, i.e., it's the first input
      if (!firstInputGiven) {
        setFirstInputGiven(true);
        player1initials = value;
        onValueChange(player1initials); // Trigger label change for the first input
      } else {
        player2initials = value;
        onValueChange(player2initials); // Trigger label change for the second input
      }

      setValue('');
    }
  };

  return (
    <input
      type="text"
      maxLength={3}
      value={value}
      onChange={(event) => setValue(event.target.value)}
      onKeyDown={handleKeyDown}
      style={{ width: '88px', height: '50px', flexShrink: 0 }}
    />
  );
};

export default TextBox;

// TextBox.js
import React, { useState } from 'react';

const TextBox = (props) => {
  const [value, setValue] = useState('');
  const { width, height } = props;

  const textBoxStyle = {
    width: width || '88px',
    height: height || '50px',
    flexShrink: 0,
  };

  return (
    <input
      type="text"
      maxLength={3}
      value={value}
      onChange={(event) => {
        setValue(event.target.value);
      }}
      style={textBoxStyle}
    />
  );
};

export default TextBox;

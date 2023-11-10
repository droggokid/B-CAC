// InitialsBox.js
import React from 'react';
import TextBorder from './TextBorder';
import TextBox from './TextBox';

const InitialsBox = ({ label, onLabelChange }) => {
  const handleTextBoxChange = (newValue) => {
    onLabelChange(newValue);
  };

  return (
    <div style={{ display: 'flex', justifyContent: 'center', alignItems: 'center', height: '100vh' }}>
      <TextBorder
        label={label}
        width="578px"
        height="122px"
        borderRadius="23px"
        border="1px solid #000"
        background="#000"
        boxShadow="0px 4px 4px 0px rgba(0, 0, 0, 0.25)"
        color="white"
        fontFamily="Inter"
        fontSize="40px"
        fontStyle="normal"
        fontWeight={400}
        lineHeight="normal"
      >
        {/* Place TextBox inside TextBorder */}
        <TextBox onValueChange={handleTextBoxChange} />
      </TextBorder>
    </div>
  );
};

export default InitialsBox;

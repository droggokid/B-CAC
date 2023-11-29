// TextBorder.js
import React from 'react';
import Text from './Text';

function TextBorder(props) {
  const { label, width, height, borderRadius, border, background, boxShadow, color, fontFamily, fontSize, fontStyle, fontWeight, lineHeight } = props;

  const borderStyle = {
    width: width || '578px',
    height: height || '122px',
    borderRadius: borderRadius || '23px',
    border: border || '1px solid #000',
    background: background || '#000',
    boxShadow: boxShadow || '0px 4px 4px 0px rgba(0, 0, 0, 0.25)',
    display: 'flex',
    justifyContent: 'flex-start', // Center text on the left and textbox on the right
    alignItems: 'center',
    alignContent: "space-between",
    position: 'relative',
    padding: '0 20px', // Add padding to create space between text and textbox
  };

  const textStyles = {
    color: color || 'white',
    fontFamily: fontFamily || 'Inter',
    fontSize: fontSize || '40px',
    fontStyle: fontStyle || 'normal',
    fontWeight: fontWeight || 400,
    lineHeight: lineHeight || 'normal',
    // Remove absolute positioning to center text on the left
  };

  return (
    <div style={borderStyle}>
      <Text label={label} styles={textStyles} />
      {props.children}
    </div>
  );
}

export default TextBorder;

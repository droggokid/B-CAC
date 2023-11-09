import React from 'react';
import Text from './Text';

function TextBorder(props) {
    const { label, width, height, borderRadius, border, background, boxShadow, 
    /*Text options*/color, fontFamily, fontSize, fontStyle, fontWeight, lineHeight } = props;

    const borderStyle = {
        //Border properties:
        width: width || '578px',
        height: height || '122px',
        borderRadius: borderRadius || '23px',
        border: border || '1px solid #000',
        background: background || '#000',
        boxShadow: boxShadow || '0px 4px 4px 0px rgba(0, 0, 0, 0.25)',
        display: 'flex',
        justifyContent: 'center',
        alignItems: 'center',
        position: 'relative', // Ensure the positioning context for absolute positioning
    };
    const textStyles = {
        //Text properties:
        color: color || 'white',
        fontFamily: fontFamily || 'Inter',
        fontSize: fontSize || '40px',
        fontStyle: fontStyle || 'normal',
        fontWeight: fontWeight || 400,
        lineHeight: lineHeight || 'normal',
        position: 'absolute', // Position the text absolutely within the TextBorder
        zIndex: 1, // Set a higher z-index to make sure it's on top
        padding: "0 20px 0 20px"

    }    
    
    return (
        <>
            <Text label={textStyles.label} styles={textStyles}/>
            <div className='border' style={borderStyle}/>
        </>
    );
}

export default TextBorder;

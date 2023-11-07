import React from 'react';
import Text from './Text';

function TextBorder(props) {
    const { label, width, height, borderRadius, border, background, boxShadow } = props;

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
    };
    //const textStyles    
    
    return (
        <TextBorder>
            <Text label={label} styles={borderStyle}/>
            <div className='border' style={borderStyle}/>
        </TextBorder>
        //<div className="border" style={borderStyle} />
    );
}

export default TextBorder;

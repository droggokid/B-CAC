import React from 'react';
import Button from './Button';

function Text(props) {
    const { label, color, fontFamily, fontSize, fontStyle, fontWeight, lineHeight } = props;

    return (
        <div style={{
            color: color || 'white',
            fontFamily: fontFamily || 'Inter',
            fontSize: fontSize || '40px',
            fontStyle: fontStyle || 'normal',
            fontWeight: fontWeight || 400,
            lineHeight: lineHeight || 'normal'
        }}>
            <p>{props.label}</p> 
        </div>
    );
}

export default Text;

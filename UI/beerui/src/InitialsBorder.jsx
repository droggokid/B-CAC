import React from 'react';
import Text from './Text';

function InitialsBorder(props) {
    const { label, width, height, borderRadius, border, background, boxShadow } = props;

    const borderStyle = {
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
    
    
    return (
        <div className="border" style={borderStyle} />
    );
}

export default InitialsBorder;

import React from 'react';
import Text from './Text';
import InitialsBox from './InitialsBox';

function Button(props) {
    const { onClick, label, width, height, borderRadius, border, background, boxShadow } = props;

    const buttonStyle = {
        width: width || '278px',
        height: height || '94px',
        borderRadius: borderRadius || '23px',
        border: border || '1px solid #000',
        background: background || '#000',
        boxShadow: boxShadow || '0px 4px 4px 0px rgba(0, 0, 0, 0.25)',
        display: 'flex',
        justifyContent: 'center',
        alignItems: 'center',     
    };

    return (
        <button className="button" onClick={onClick} style={buttonStyle}>
            <Text label={label} />
        </button>
    );
}

export default Button;

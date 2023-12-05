import React from 'react';
import Button from './Button';

function Text(props) {
    const { label, show, color, fontFamily, fontSize, fontStyle, fontWeight, lineHeight, styles } = props;

    return (
        <div style={styles || {
            display: (show === undefined ? 1 : show) ? "block" : "none",
            color: color || 'white',
            fontFamily: fontFamily || 'Inter',
            fontSize: fontSize || '40px',
            fontStyle: fontStyle || 'normal',
            fontWeight: fontWeight || 400,
            lineHeight: lineHeight || 'normal',
            label: label || 'Sample Text'
        }}>
            <p>{label}</p> 
        </div>
    );
}

export default Text;

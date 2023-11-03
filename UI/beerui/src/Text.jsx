import React from 'react';
import Button from './Button';

function Text(props) {
    return (
        <div style={{
            color: '#FFF',
            fontFamily: 'Inter',
            fontSize: '40px',
            fontStyle: 'normal',
            fontWeight: 400,
            lineHeight: 'normal'
        }}>
            <p>{props.label}</p> 
        </div>
    );
}

export default Text;

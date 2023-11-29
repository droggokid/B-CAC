import React from 'react';
import Text from './Text';

function ActiveBtn(props)
{
    const { label, active, onclick, show, height, color, fontColor } = props;

    const activeBtnStyle = {
        display: show ? "inline-block" : "none",
        border: "none",
        backgroundColor: active ? (color || "#9DFF7B") : "#505050",
        fontSize: `${height * 0.4}px`,
        color: active ? (fontColor || "black") : '#F0F0F0',
        borderRadius: "23px",
        paddingLeft: `${height * 0.3}px`,
        paddingRight: `${height * 0.3}px`,
        margin: "20px",
        boxShadow: "0px 10px 15px -3px rgba(0,0,0,0.1)",
        cursor: active ? "pointer" : "not-allowed",
    };
    
    return (
        <button id="abtn" style={activeBtnStyle} onClick={active ? onclick : null}>
            <Text color={activeBtnStyle.color} fontFamily="arial" label={label} />
        </button>
    );
}

export default ActiveBtn;
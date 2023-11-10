import React from 'react';

function StartBtn(props)
{
    const { active, onclick, height } = props;

    const startBtnStyle = {
        border: "none",
        backgroundColor: active ? "#9DFF7B" : "#505050",
        fontSize: `${height * 0.4}px`,
        color: active ? "black" : '#F0F0F0',
        borderRadius: "23px",
        padding: `${height * 0.3}px`,
        margin: "auto",
        boxShadow: "0px 10px 15px -3px rgba(0,0,0,0.1)",
        cursor: active ? "pointer" : "default",
    };

    return (
        <button style={startBtnStyle} onClick={onclick}>
            Start Game
        </button>
    );
}

export default StartBtn;
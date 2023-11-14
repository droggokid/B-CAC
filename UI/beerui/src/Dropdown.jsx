import React from 'react';
import Text from './Text';
import TextBorder from './TextBorder';
import chev from './assets/chev.png';

function Dropdown(props)
{
    const {options, fontSize, color, width, height, borderRadius, border, background, boxShadow} = props;

    const dropdownStyle = {
        fontSize: fontSize || "40px",
        color: color || '#F0F0F0',
        width: width || '578px',
        height: height || '80px',
        borderRadius: borderRadius || '23px',
        border: border || '1px solid #000',
        background: background || '#000',
        boxShadow: boxShadow || '0px 4px 4px 0px rgba(0, 0, 0, 0.25)',
    };

    const imgStyle = {
        transform: `translateX(calc(${dropdownStyle.height} * -1))`,
        height: `calc(${dropdownStyle.height} * 0.25)`,
        margin: `calc(${dropdownStyle.height} * (0.75 / 2))`,
    };

    return (
        <div className='dropdown'>
            <select style={dropdownStyle}>
                {options.map((opt) => (
                    <option value={opt}>{opt}</option>
                ))}
            </select>
            <img src={chev} alt="chevron-down" style={imgStyle} />
        </div>
    );
}

export default Dropdown;
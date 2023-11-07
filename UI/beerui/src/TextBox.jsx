import React, { useState } from 'react';

// Global variable 
let inputValue = '';

const TextBox = (props) => {
    const [value, setValue] = useState('');
    const {width, height} = props;

    return (
        <input type="text" maxLength={3} value={value} onChange={(event) => {
            // Update the local state
            setValue(event.target.value);

            // Update the global variable
            inputValue = event.target.value;
        }} style={{width: '88px', height: '50px', flexShrink: 0}} />
    );
};

export default TextBox;

import React from 'react';
import TextBorder from './TextBorder';
import TextBox from './TextBox';

function InitialsBox(props){
    return (
        <div>
            <TextBorder>
                <TextBox />
            </TextBorder>
        </div>
    );
}

export default InitialsBox;
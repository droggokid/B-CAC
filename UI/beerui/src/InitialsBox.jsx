import React from 'react';
import TextBorder from './TextBorder';
import TextBox from './TextBox';

function InitialsBox(props){
    return (
        <div>
            <TextBorder label={props.label}>
                
                <TextBox/>
            </TextBorder>
        </div>
    );
}

export default InitialsBox;
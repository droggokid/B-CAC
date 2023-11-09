import React from 'react';
import TextBorder from './TextBorder';
import TextBox from './TextBox';

function InitialsBox(props){
    return (
        <div>
            <TextBorder label={props.label}/>
            <TextBox zIndex={2}/> //flyt den til højre og op
        </div>
    );
}

export default InitialsBox;
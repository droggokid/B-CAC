// MainMenu.js
import React, { useState } from "react";
import "./mainMenu.css"; 
import Button from "./Button";
import InitialsBox from "./InitialsBox";
import yourImage from "./b-cac_logo.png";

function MainMenu() {
    const [playerLabel, setPlayerLabel] = useState("Enter Player 1 initials: ");
    const [initialInputGiven, setInitialInputGiven] = useState(false);

    const handlePlayerLabelChange = (newLabel) => {
        if (initialInputGiven) {
            setPlayerLabel("Enter Player 2 initials: ");
        } else {
            setInitialInputGiven(true);
            // Do not update the label immediately; wait for Enter key
        }
    };

    return (
        <div className="MainMenu">
            <img src={yourImage} alt="Your Alt Text" className="TopRightImage" />
            
            <div className="Button">
                <Button label="Prepare Game" />
            </div>

            <div className="InitialsBox">
                <InitialsBox label={playerLabel} onLabelChange={handlePlayerLabelChange} />
            </div>  
        </div>
    );
}

export default MainMenu;

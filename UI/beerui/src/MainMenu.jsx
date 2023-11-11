// MainMenu.js
import React, { useState } from "react";
import "./mainMenu.css"; 
import Button from "./Button";
import InitialsBox from "./InitialsBox";
import yourImage from "./b-cac_logo.png";

function MainMenu() {
    const [playerLabel, setPlayerLabel] = useState("Enter Player 1 initials: ");
    const [initialInputGiven, setInitialInputGiven] = useState(false);
    const [activeComponent, setActiveComponent] = useState(null);

    const handlePlayerLabelChange = (newLabel) => {
        if (initialInputGiven) {
            setPlayerLabel("Enter Player 2 initials: ");
        } else {
            setInitialInputGiven(true);
            // Do not update the label immediately; wait for Enter key
        }
    };

    const handleOnClickPrepareGame = () => {
        setActiveComponent("InitialsBox");
    }

    const renderActiveComponent = () => {
        switch(activeComponent) {
            case "InitialsBox":
                return(
                    <div className="InitialsBox">
                        <InitialsBox label={playerLabel} onLabelChange={handlePlayerLabelChange} />
                    </div>
                );
            default:
                return null;
        }
    }

    return (
        <div className="MainMenu">
            <img src={yourImage} alt="Beer logo" className="TopRightImage" />
            
            <div className="Button--top">
                <Button label="Prepare Game" onClick={handleOnClickPrepareGame}/>
            </div>

            <div className="Button--bottom">
                <Button label="Leaderboard" />
            </div>

            {renderActiveComponent()} 
        </div>
    );
}

export default MainMenu;

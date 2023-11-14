import React, { useState } from "react";
import "./mainMenu.css"; 
import Button from "./Button";
import InitialsBox from "./InitialsBox";
import yourImage from "./b-cac_logo.png";

function MainMenu({onComponentChange}) {
    const [playerLabel, setPlayerLabel] = useState("Enter Player 1 initials: ");
    const [initialInputGiven, setInitialInputGiven] = useState(false);
    const [secondInputGiven, setSecondInputGiven] = useState(false);
    const [activeComponent, setActiveComponent] = useState(null);

    const handlePlayerLabelChange = (newLabel) => {
        if (secondInputGiven) {
            setPlayerLabel("Starting game in 1 second...");
            setTimeout(() => {
              onComponentChange("GameMenu");
            }, 1000);
          } else if (initialInputGiven) {
            setPlayerLabel("Enter Player 2 initials: ");
            setSecondInputGiven(true);
          } else {
            setInitialInputGiven(true);
          }
    }
      
  

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
import React, { useState } from "react";
import Button from "./Button";
import InitialsBox from "./InitialsBox";
import Leaderboard from "./Leaderboard";
import yourImage from "./b-cac_logo.png";
import "./mainMenu.css";
import {server, ssend} from "./Server";

function MainMenu({onComponentChange}) {
    const [playerLabel, setPlayerLabel] = useState("Enter Player 1 initials: ");
    const [initialInputGiven, setInitialInputGiven] = useState(false);
    const [activeComponent, setActiveComponent] = useState(null);

    const handlePlayerLabelChange = () => {
        if (initialInputGiven) {
            setPlayerLabel("Starting game in 1 second...");
            setTimeout(() => {
            onComponentChange("GameMenu");
          }, 1000);
        } else {
            setPlayerLabel("Enter Player 2 initials: ");
            setInitialInputGiven(true);
        }
      };
      
  

    const handleOnClickPrepareGame = () => {
        setActiveComponent("InitialsBox");
    }

    const handleOnClickLeaderboard = () => {
        setActiveComponent("Leaderboard");
    }

    const renderActiveComponent = () => {
        switch(activeComponent) {
            case "InitialsBox":
                return(
                    <div className="InitialsBox">
                        <InitialsBox label={playerLabel} onLabelChange={handlePlayerLabelChange} />
                    </div>
                );
            case "Leaderboard": {
                return(
                    <div className="Leaderboard">
                        <Leaderboard />
                    </div>
                );
            }
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
                <Button label="Leaderboard" onClick={handleOnClickLeaderboard}/>
            </div>

            <Button label="POST (test)" onClick={() => {
                ssend();
            }} />

            {renderActiveComponent()} 
        </div>
    );
}


export default MainMenu;
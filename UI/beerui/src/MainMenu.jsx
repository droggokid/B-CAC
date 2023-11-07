import React from "react";
import Text from "./Text";
import Button from "./Button";
import InitialsBox from "./InitialsBox";


function MainMenu() {
    return (
        <div className="MainMenu">
            <div className="Button">
                <Button label="Prepare Game" />
            </div>

            <div className="InitialsBox">
                <InitialsBox label="Player 1 " />
            </div>
        </div>
    );
}

export default MainMenu;

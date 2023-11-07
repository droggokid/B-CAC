import React from "react";
import Text from "./Text";
import Button from "./Button";
import InitialsBox from "./InitialsBox";


function MainMenu() {
    return (
        <div style={{ display: "flex", justifyContent: "center", alignItems: "center", height: "100vh" }}>
            <Button label="Prepare Game" />
            <InitialsBox />
        </div>
    );
}

export default MainMenu;

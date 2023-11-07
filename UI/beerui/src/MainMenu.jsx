import React from "react";
import Text from "./Text";
import Button from "./Button";


function MainMenu() {
    return (
        <div style={{ display: "flex", justifyContent: "center", alignItems: "center", height: "100vh" }}>
            <Button label="Prepare Game" />
        </div>
    );
}

export default MainMenu;

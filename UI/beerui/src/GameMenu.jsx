import React, { useState } from 'react';
import Text from './Text';
import PlayerStat from './PlayerStat';
import Dropdown from './Dropdown';
import StartBtn from './StartBtn';

function GameMenu(props) {
    const [startBtnActive, setStartBtnActive] = useState(false);
    const [startBtnShow, setStartBtnShow] = useState(true);
    const [timerShow, setTimerShow] = useState(false);
    const [p1Initials, setP1Initials] = useState("XXX"); // Brug setP1Initials til at ændre værdier
    const [p2Initials, setP2Initials] = useState("XXX");
    const [p1Time, setP1Time] = useState("00:00.00");
    const [p2Time, setP2Time] = useState("00:00.00");
    const [timerTime, setTimerTime] = useState("00:00");
    const [dropdownDisabled, setDropdownDisabled] = useState(false);

    const gameMenuStyle = {
        display: "grid",
    };

    const rowStyle = {
        display: "grid",
        gridTemplateColumns: "250px auto",
    };

    function dropdownCb(event)
    {
        if (event.target.value === "Vælg")
        {
            setStartBtnActive(false);
        }
        else
        {
            setStartBtnActive(true);
        }
    }

    function startGame()
    {
        console.log("startGame called");

        setStartBtnActive(false);
        setStartBtnShow(false);
        setTimerShow(true);
        setDropdownDisabled(true);
    }

    return (
        <div style={gameMenuStyle}>
            <PlayerStat id="1" initials={p1Initials} time={p1Time} style={rowStyle} />
            <PlayerStat id="2" initials={p2Initials} time={p2Time} style={rowStyle} />
            <div id="drinkType" style={rowStyle}>
                <Text label="Drink type" fontSize="30px" fontFamily="Arial" color="black" />
                <Dropdown options={["Vælg", "Bajer", "Mokai"]} callback={dropdownCb} disable={dropdownDisabled} fontSize="30px" />
            </div>
            <div className="activeCont">
                <StartBtn
                    height={100}
                    active={startBtnActive}
                    show={startBtnShow}
                    onclick={startGame}
                />
                <Text label={timerTime} show={timerShow} color="#000000" fontFamily="Arial" fontSize="100px" />
            </div>
        </div>
    );
}

export default GameMenu;

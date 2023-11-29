import React, { useState, useEffect } from 'react';
import Text from './Text';
import PlayerStat from './PlayerStat';
import Dropdown from './Dropdown';
import ActiveBtn from './ActiveBtn';
import { server } from "./Server";
import { data } from "./Data";

function GameMenu(props) {
    const [startBtnActive, setStartBtnActive] = useState(false);
    const [startBtnShow, setStartBtnShow] = useState(true);
    const [checkBtnActive, setCheckBtnActive] = useState(false);
    const [checkBtnShow, setCheckBtnShow] = useState(true);
    const [timerShow, setTimerShow] = useState(false);
    const [p1Initials, setP1Initials] = useState(data.players[0].initials); // Brug setP1Initials til at ændre værdier
    const [p2Initials, setP2Initials] = useState(data.players[1].initials);
    const [p1Time, setP1Time] = useState("00:00.00");
    const [p2Time, setP2Time] = useState("00:00.00");
    const [timerSec, setTimerSec] = useState(0);
    const [dropdownDisabled, setDropdownDisabled] = useState(false);
    const [drinkType, setDrinkType] = useState("Vælg");
    const [gameRunning, setGameRunning] = useState(false);
    const [count, setCount] = useState(0);

    useEffect(() => {
        setTimeout(() => {
            setCount((count) => count + 1);
            if (gameRunning)
            {
                // setGameRunning(server.getGameRunning());
                setTimerSec(timerSec + 1);
            }
        }, 1000);
    });

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
            setDrinkType(event.target.value);
        }
    }

    function startGame()
    {
        console.log("startGame called");

        setStartBtnActive(false);
        setStartBtnShow(false);
        setTimerShow(true);
        setDropdownDisabled(true);
        setGameRunning(true);

        server.postStartGame(p1Initials, p2Initials, drinkType);
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
                <ActiveBtn
                    label="Godkend"
                    height={100}
                    active={checkBtnActive}
                    show={checkBtnShow}
                    onclick={startGame}
                />
                <ActiveBtn
                    label="Start"
                    height={100}
                    active={startBtnActive}
                    show={startBtnShow}
                    onclick={startGame}
                />
                <Text label={`${Math.floor(timerSec / 60)}:${timerSec % 60}`} show={timerShow} color="#000000" fontFamily="Arial" fontSize="100px" />
            </div>
        </div>
    );
}

export default GameMenu;

import React, { useState, useEffect } from 'react';
import Text from './Text';
import PlayerStat from './PlayerStat';
import Dropdown from './Dropdown';
import ActiveBtn from './ActiveBtn';
import Button from "./Button";
import { server } from "./Server";
import { data } from "./Data";


function GameMenu({onComponentChange}) {
    const [startBtnActive, setStartBtnActive] = useState(false);
    const [startBtnShow, setStartBtnShow] = useState(true);
    const [checkBtnActive, setCheckBtnActive] = useState(false);
    const [checkBtnShow, setCheckBtnShow] = useState(true);
    const [cancelBtnShow, setCancelBtnShow] = useState(false);
    const [countDownShow, setCountDownShow] = useState(false);
    const [countDownLabel, setCountDownLabel] = useState(3);
    const [timerShow, setTimerShow] = useState(false);
    const [winShow, setWinShow] = useState(false);
    const [winLabel, setWinLabel] = useState("Ingen har vundet");
    const [p1Initials, setP1Initials] = useState(data.players[0].initials); // Brug setP1Initials til at ændre værdier
    const [p2Initials, setP2Initials] = useState(data.players[1].initials);
    const [p1Time, setP1Time] = useState("00:00.00");
    const [p2Time, setP2Time] = useState("00:00.00");
    const [timerSec, setTimerSec] = useState(0);
    const [dropdownDisabled, setDropdownDisabled] = useState(false);
    const [drinkType, setDrinkType] = useState("Vælg");
    const [rmTxtShow, setRmTxtShow] = useState(true);
    const [rmTxtLabel, setRmTxtLabel] = useState("Fjern alle genstande fra platforme, tryk derefter godkend");
    const [gameRunning, setGameRunning] = useState(false);
    const [count, setCount] = useState(0);



    useEffect(() => {
        setTimeout(() => {
            setCount(count + 1);

            if (countDownShow)
            {
                setCountDownLabel(countDownLabel - 1);

                if (countDownLabel <= 1)
                {
                    setCountDownShow(false);
                }
            }

            if (gameRunning)
            {
                let gameRunningResp = server.getGameRunning();
                
                switch (gameRunningResp)
                {
                    case true:
                        setTimerSec(timerSec + 1);
                        break;
                        
                    // End of game code
                    case false:
                        setGameRunning(false);
                        
                        let times = server.getTime();
                        console.log(times)
                        
                        // Opdater tider og vinder tekst når det er modtaget
                        
                        setTimerShow(false);
                        setWinLabel("Player XXX har vundet!");
                        setWinShow(true);
                        
                        break;

                    default:
                        console.warn("No connection to server"); 
                        setTimerSec(timerSec + 1);
                }
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
            setCheckBtnActive(false);
        }
        else
        {
            setCheckBtnActive(true);
            setDrinkType(event.target.value);
        }
    }

    function tare()
    {
        console.log("tare called");

        setCheckBtnActive(false);
        setDropdownDisabled(true);
        setRmTxtLabel("Kalibrerer, rør ikke platforme");

        server.postTare();
        
        // Afvent tare godkendt fra psoc, aktiver derefter start-knap
        server.getTareReady();

        setTimeout(() => {
            setStartBtnActive(true);
            setCheckBtnShow(false);
            setCancelBtnShow(true);
            setRmTxtLabel("Placer genstande på platforme, tryk derefter start");

        }, 1000);
    }

    function cancel()
    {
        setDropdownDisabled(false);
        setStartBtnActive(false);
        setCancelBtnShow(false);
        setCheckBtnShow(true);
        setRmTxtLabel("Fjern alle genstande fra platforme, tryk derefter godkend");
        setCheckBtnActive(!(drinkType === "Vælg"));
    }

    function startGame()
    {
        console.log("startGame called");

        const countDown = 3;

        setStartBtnActive(false);
        setStartBtnShow(false);
        setCheckBtnShow(false);
        setCancelBtnShow(false);
        setRmTxtShow(false);
        setCountDownShow(true);

        server.postStartGame(p1Initials, p2Initials, drinkType);

        // Afvent game ready fra psoc, start derefter nedtælling til spil start
        server.getGameReady();

        setTimeout(() => {
            setTimerShow(true);
            setGameRunning(true);
        }, countDown * 1000);
    }

    return (
        <div style={gameMenuStyle}>
            <PlayerStat id="1" initials={p1Initials} time={p1Time} style={rowStyle} />
            <PlayerStat id="2" initials={p2Initials} time={p2Time} style={rowStyle} />
            <div id="drinkType" style={rowStyle}>
                <Text label="Drink type" fontSize="30px" fontFamily="Arial" color="black" />
                <Dropdown options={["Vælg", "Bajer"]} callback={dropdownCb} disable={dropdownDisabled} fontSize="30px" />
            </div>
            <Text label={rmTxtLabel} show={rmTxtShow} color="black" fontFamily="arial" fontSize="30px" />
            <div class="activeCont">
                <ActiveBtn
                    label="Godkend"
                    height={100}
                    active={checkBtnActive}
                    show={checkBtnShow}
                    onclick={tare}
                    width={300}
                />
                <ActiveBtn
                    label="Annuller"
                    height={100}
                    color="#FF7C7C"
                    active={true}
                    show={cancelBtnShow}
                    onclick={cancel}
                    width={300}
                />
                <ActiveBtn
                    label="Start"
                    height={100}
                    active={startBtnActive}
                    show={startBtnShow}
                    onclick={startGame}
                    width={300}
                />
                <Text label={`Spillet begynder om ${countDownLabel} sekunder`} show={countDownShow} color="#000000" fontFamily="Arial" fontSize="30px" />
                <Text label={`${Math.floor(timerSec / 60)}:${timerSec % 60}`} show={timerShow} color="#000000" fontFamily="Arial" fontSize="100px" />
                <div style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', justifyContent: 'center', height: '30vh' }}>                
                <Text label={winLabel} show={winShow} color="#000000" fontFamily="Arial" fontSize="100px" />
                <ActiveBtn
                    color="#000000"
                    fontColor="white"
                    width={200}
                    show={winShow}
                    active={true}
                    label="Quit"
                    onclick={() => { onComponentChange("MainMenu"); }} 
                /> 
                </div>
            </div>
        </div>
    );
}

export default GameMenu;

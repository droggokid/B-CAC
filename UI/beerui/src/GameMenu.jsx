import React from 'react';
import Text from './Text';
import PlayerStat from './PlayerStat'
import Dropdown from './Dropdown';
import StartBtn from './StartBtn';

function GameMenu(props)
{
    const gameMenuStyle = {
        display: "grid",
    };

    const rowStyle = {
        display: "grid",
        gridTemplateColumns: "220px auto",
    };

    let startBtnActive = false;
    let startBtnShow = true;
    let timerShow = false;

    function startGame()
    {
        console.log("startGame called");

        startBtnActive = false;
        startBtnShow = false;
        timerShow = true;
    }

    return (
        <div style={gameMenuStyle}>
            <PlayerStat id="1" initials="abc" time="01:56.40" style={rowStyle} />
            <PlayerStat id="2" initials="def" time="02:56.40" style={rowStyle} />
            <div id="drinkType" style={rowStyle}>
                <Text label="Drink type" fontSize="30px" fontFamily="Arial" color="black" />
                <Dropdown options={["Vælg", "Bajer", "Mokai"]} fontSize="30px" />
            </div>
            <div className="activeCont">
                <StartBtn height={100} active={startBtnActive} show={startBtnShow} onclick={startGame} />
                <Text label="00:29" show={timerShow} color="#000000" fontFamily="Arial" fontSize="100px" />
            </div>
        </div>
    );
}

export default GameMenu;
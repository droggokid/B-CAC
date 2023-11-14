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

    return (
        <div style={gameMenuStyle}>
            <PlayerStat id="1" initials="abc" time="01:56.40" />
            <PlayerStat id="2" initials="def" time="02:56.40" />
            <div id="drinkType">
                <Text label="Drink type" fontSize="30px" fontFamily="Arial" color="black" />
                <Dropdown options={["Bajer", "Mokai"]} fontSize="30px" />
            </div>
            <StartBtn height={100} active={1} onclick={() => {console.log("hej");}} />
        </div>
    );
}

export default GameMenu;
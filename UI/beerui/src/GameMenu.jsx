import React from 'react';
import Text from './Text';
import PlayerStat from './PlayerStat'
import Dropdown from './Dropdown';

function GameMenu(props)
{
    return (
        <>
            <PlayerStat id="1" initials="abc" time="01:56.40" />
            <PlayerStat id="2" initials="def" time="02:56.40" />
            <div id="drinkType">
                <Text label="Drink type" fontSize="30px" fontFamily="Arial" height="80px" />
                <Dropdown options={["Bajer", "Mokai"]} fontSize="30px" />
            </div>
        </>
    );
}

export default GameMenu;
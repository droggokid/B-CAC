import React from 'react';
import Text from './Text';
import PlayerStat from './PlayerStat'

function GameMenu(props)
{
    return (
        <>
            <PlayerStat id="1" initial="abc" time="01:56.40" />
            <PlayerStat id="2" initial="def" time="02:56.40"/>
        </>
    );
}

export default GameMenu;
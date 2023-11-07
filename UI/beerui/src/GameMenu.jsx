import React from 'react';
import Text from './Text';
import PlayerStat from './PlayerStat'

function GameMenu(props)
{
    return (
        <>
            <PlayerStat id="1" initials="abc" time="01:56.40" />
            <PlayerStat id="2" initials="def" time="02:56.40"/>
        </>
    );
}

export default GameMenu;
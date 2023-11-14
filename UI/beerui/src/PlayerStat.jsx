import React from 'react';
import Text from './Text';
import TextBorder from './TextBorder';

function PlayerStat(props)
{
    const { id, initials, time} = props;

    return (
        <div className='playerStat'>
            <Text label={`Player ${id}: ${initials}`} fontSize="30px" fontFamily="Arial" color="black"/>
            <TextBorder label={`${time}`} fontSize="30px" fontFamily="Arial" height="80px" />
        </div>
    );
}

export default PlayerStat;
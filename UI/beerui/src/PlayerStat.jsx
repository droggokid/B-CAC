import React from 'react';
import Text from './Text';
import TextBorder from './TextBorder';

function PlayerStat(props)
{
    const { id, initials, time} = props;

    return (
        <div className='playerStat'>
            <Text label={`Player ${id}: ${initials}`} />
            <TextBorder label={`${time}`} />
        </div>
    );
}

export default PlayerStat;
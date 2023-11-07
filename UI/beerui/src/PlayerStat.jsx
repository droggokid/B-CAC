import React from 'react';
import Text from './Text';

function PlayerStat(props)
{
    const { id, initials, time} = props;

    return (
        <div>
            <Text label={`Player ${id}: ${initials}`} />
            <Text label={`${time}`} />
        </div>
    );
}

export default PlayerStat;
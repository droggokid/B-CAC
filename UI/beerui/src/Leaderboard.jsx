import React from 'react';

function Leaderboard(props) {
    const leaderboardStyle = {
        display: 'flex',
        alignItems: 'center',
        justifyContent: 'center',
        height: '100vh',
    };

    const boxStyle = {
        width: '889px',
        height: '614px',
        position: 'relative',
        background: '#D9D9D9',
        display: 'grid',
        gridTemplateColumns: 'repeat(2, 1fr)',
        gridTemplateRows: 'repeat(3, 1fr)',
        gap: '10px', // Adjust as needed
    };

    const textStyle = {
        color: '#2D2D2D',
        fontSize: '24px',
        fontFamily: 'Inter',
        fontWeight: 400,
        wordWrap: 'break-word',
        position: 'relative', // Adjusted from absolute
        textAlign: 'left',
        paddingLeft: '10px', // Add left padding for better alignment
    };

    return (
        <div style={leaderboardStyle}>
            <div style={boxStyle}>
                <div style={textStyle}>Name 1</div>
                <div style={textStyle}>00:00:00</div>
                <div style={textStyle}>Name 2</div>
                <div style={textStyle}>00:00:00</div>
                <div style={textStyle}>Name 3</div>
                <div style={textStyle}>00:00:00</div>
            </div>
        </div>
    );
}

export default Leaderboard;

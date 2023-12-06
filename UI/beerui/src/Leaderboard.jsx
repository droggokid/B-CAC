import React, { useEffect, useState } from 'react';
import {server} from "./Server";
import TextBorder from "./TextBorder";
import Text from "./Text";
import { data } from "./Data";

export function Leaderboard(props) {
    const [p1n, setp1n] = useState("Loading..");
    const [p2n, setp2n] = useState("Loading..");
    const [p3n, setp3n] = useState("Loading..");
    const [p1t, setp1t] = useState("00:00:00");
    const [p2t, setp2t] = useState("00:00:00");
    const [p3t, setp3t] = useState("00:00:00");
    
    useEffect(() => {
        server.getLeaderboard();
        setTimeout(() => {
            console.log('recieved delayed leaderboard ' + data.recievedLeaderboard);
            let parsedLeaderboard = JSON.parse(data.recievedLeaderboard);
            setp1n(parsedLeaderboard[0].initials);
            setp2n(parsedLeaderboard[1].initials);
            //setp3n(parsedLeaderboard[2].initials);
            setp1t(parsedLeaderboard[0].time);
            setp2t(parsedLeaderboard[1].time);
            //setp3t(parsedLeaderboard[2].time);
        }, 1000);
    });
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
    }
    ;
    return (
        <div style={leaderboardStyle}>
            <div className="vertcontainer">
                <TextBorder>
                    <div className="container">
                        <Text label={p1n}/>
                        <Text label={p1t} id="player1time" />
                    </div>
                </TextBorder>
                <TextBorder>
                    <div className="container">
                        <Text label={p2n} id="player2name" />
                        <Text label={p2t} id="player2time" />
                    </div>
                </TextBorder>
                <TextBorder>
                    <div className="container">
                        <Text label={p3n} id="player3name" />
                        <Text label={p3t} id="player3time" />
                    </div>
                </TextBorder>
            </div>
        </div>
        
    );
}

// export function setPlayerData(players) 
// {
//     setp1n(players[0].initials);
//     document.getElementById("player1time").innerHTML = players[0].time;
// }


//export default Leaderboard;

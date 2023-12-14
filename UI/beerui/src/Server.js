// How 2 host på rpizw med god OS:
// 1. på en anden maskine kør: npm run build
// 2. push
// 3. pull på rpizw
// 4. på rpizw i build-mappen for ui'en kør: sudo python3 -m http.server 80
// Hvis der skal skiftes mellem at hoste på gh-pages og lokalt, skal package.json homepage ændres til "."
// evt. check ip i bunden af denne fil
// Backenden skal også bygges på en anden maskine, og køres på rpizw med ./backend
import { data } from "./Data";

class Server
{
    constructor(url)
    {
        this.url = url;
        this.xhr = new XMLHttpRequest();
        this.getDelay = 800;
    }

    // GET methods

    getTareReady()
    {
        // Return boolean if taring is done
        const getStr = "tareReady";
        this.get(getStr);
        setTimeout(() => {
            try
            {
                data.recievedTareReady = data.recievedGet[getStr] === "true" ? true : false;
            }
            catch (e)
            {
                console.warn(e);
            }
        }, this.getDelay);
    }

    getGameReady()
    {
        // Return boolean if the game is ready to start
        const getStr = "gameReady";
        this.get(getStr);
        setTimeout(() => {
            try
            {
                data.recievedGameReady = data.recievedGet[getStr] === "true" ? true : false;
            }
            catch (e)
            {
                console.warn(e);
            }
        }, this.getDelay);
    }
    
    getGameRunning()
    {
        // Return boolean if the game is running
        const getStr = "gameRunning";
        this.get(getStr);
        setTimeout(() => {
            try
            {
                data.recievedGameRunning = data.recievedGet[getStr] === "true" ? true : false;
            }
            catch (e)
            {
                console.warn(e);
            }
        }, this.getDelay);
    }

    getTime()
    {
        // Returns the exact times of the players
        const getStr = "time";
        this.get(getStr);
        setTimeout(() => {
            try
            {
                data.recievedTime = JSON.parse(data.recievedGet[getStr].replace(/'/g, '"'));
            }
            catch (e)
            {
                console.warn(e);
            }
        }, this.getDelay);
    }
    
    getLeaderboard() {
        // Returns all the leaderboard data
        const getStr = "leaderboard";
        this.get(getStr);
        setTimeout(() => {
            try
            {
                data.recievedLeaderboard = JSON.parse(data.recievedGet[getStr].replace(/'/g, '"'));
            }
            catch (e)
            {
                console.warn(e);
            }
        }, this.getDelay);
    }

    // POST methods

    postTare()
    {
        this.post(`{"cmd": "tare", "data": {}}`);
    }

    postStartGame(p1Initals, p2Initials, drinkType)
    {
        this.post(`{"cmd": "startGame", "data": {"p1": "${p1Initals}", "p2": "${p2Initials}", "drinkType": "${drinkType}"}}`);
    }

    postWinner(winnerId)
    {
        this.post(`{"cmd": "winner", "data": {"winnerId": ${winnerId}}}`);
    }

    // Don't touch or use outside class

    get(getData)
    {
        this.xhr.open('GET', `${this.url}/${getData}`);
        this.xhr.setRequestHeader("Content-Type", "text/plain");
        this.xhr.onload = () => {
            if (this.xhr.status === 200)
            {
                console.log("Raw response from server: " + this.xhr.responseText);
                data.recievedGet[getData] = this.xhr.responseText;
            }
        };
        this.xhr.send();


    }

    post(postData)
    {
        this.xhr.open('POST', this.url);
        this.xhr.setRequestHeader("Content-Type", "text/plain");
        this.xhr.onload = () => {
            if (this.xhr.status === 200)
            {
                console.log(this.xhr.responseText);
            }
        };
        this.xhr.send(postData);
    }
}

export const server = new Server('http://192.168.137.240:8080');
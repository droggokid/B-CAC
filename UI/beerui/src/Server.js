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
    }

    // GET methods

    getTareReady()
    {
        // Return boolean if taring is done
        //return this.get("tareReady") === "true" ? true : false; // Prod
        return this.get("tareReady") // Dev
    }

    getGameReady()
    {
        // Return boolean if the game is ready to start
        //return this.get("gameReady") === "true" ? true : false; // Prod
        return this.get("gameReady") // Dev
    }
    
    getGameRunning()
    {
        // Return boolean if the game is running
        //return this.get("gameRunning") === "true" ? true : false; // Prod
        return this.get("gameRunning") // Dev
    }

    getTime()
    {
        // Returns the exact times of the players
        return this.get("time");
    }
    
    getLeaderboard() {
        // Returns all the leaderboard data
        //let data1111 = this.get("leaderboard");
        this.get("leaderboard");
        setTimeout(() => {
            console.log(data.recievedData);
        }, 1000);
        return data.recievedData;
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

    // Don't touch or use outside class

    get(getData)
    {
        this.xhr.open('GET', `${this.url}/${getData}`);
        this.xhr.setRequestHeader("Content-Type", "text/plain");
        this.xhr.onload = () => {
            if (this.xhr.status === 200)
            {
                console.log(this.xhr.responseText);
                data.recievedData = (this.xhr.responseText);
            }
        };
        this.xhr.send();

        return this.xhr.responseText;
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

export const server = new Server('http://192.168.51.214:8080');
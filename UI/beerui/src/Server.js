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
    
    getLeaderboard()
    {
        // Returns all the leaderboard data
        return this.get("leaderboard");
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

    get(data)
    {
        this.xhr.open('GET', `${this.url}/${data}`);
        this.xhr.setRequestHeader("Content-Type", "text/plain");
        this.xhr.onload = () => {
            if (this.xhr.status === 200)
            {
                console.log(this.xhr.responseText);
            }
        };
        this.xhr.send();

        return this.xhr.responseText;
    }

    post(data)
    {
        this.xhr.open('POST', this.url);
        this.xhr.setRequestHeader("Content-Type", "text/plain");
        this.xhr.onload = () => {
            if (this.xhr.status === 200)
            {
                console.log(this.xhr.responseText);
            }
        };
        this.xhr.send(data);
    }
}

export const server = new Server('http://192.168.51.214:8080');
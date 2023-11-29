class Server
{
    constructor(url)
    {
        this.url = url;
        this.xhr = new XMLHttpRequest();
    }

    getTime()
    {
        // Returns the exact times of the players
        return this.get("time");
    }

    getGameRunning()
    {
        // Return boolean if the game is running
        //return this.get("gameRunning") === "true" ? true : false; // Prod
        return this.get("gameRunning") // Dev
    }

    getLeaderboard()
    {
        // Returns all the leaderboard data
        return this.get("leaderboard");
    }

    postTare()
    {
        this.post(`{"cmd": "tare", "data": {}}`);
    }

    postStartGame(p1Initals, p2Initials, drinkType)
    {
        this.post(`{"cmd": "startGame", "data": {"p1": "${p1Initals}", "p2": "${p2Initials}", "drinkType": "${drinkType}"}}`);
    }

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

export const server = new Server('http://10.9.8.2:8080');
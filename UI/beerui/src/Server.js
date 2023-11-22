class Server
{
    constructor(url)
    {
        this.url = url;
        this.xhr = new XMLHttpRequest();
    }

    getTime()
    {
        return this.get("time");
    }

    getLeaderboard()
    {
        return this.get("leaderboard");
    }

    postStartGame(p1Initals, p2Initials, drinkType)
    {
        this.post(`{"p1": "${p1Initals}", "p2": "${p2Initials}", "drinkType": "${drinkType}"}`);
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

export const server = new Server('http://192.168.1.27:8080');
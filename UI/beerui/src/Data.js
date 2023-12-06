class Player
{
    constructor(id)
    {
        this.id = id;
        this.initials = "XXX";
        this.time = "00:00.00";
    }
}

class Data
{
    constructor()
    {
        this.players = [];
        
        this.players[0] = new Player(0);
        this.players[1] = new Player(1);
        this.players[2] = new Player(2);

        this.recievedGet = {};

        this.recievedTareReady = false;
        this.recievedGameReady = false;
        this.recievedGameRunning = false;
        this.recievedTime = "";
        this.recievedLeaderboard = "";
    }
}

export const data = new Data();
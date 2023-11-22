class Player
{
    constructor(id)
    {
        this.id = id;
        this.initials = "XXX";
    }
}

class Data
{
    constructor()
    {
        this.players = [];
        
        this.players[0] = new Player(0);
        this.players[1] = new Player(1);
    }
}

export const data = new Data();
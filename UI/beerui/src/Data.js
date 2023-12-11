class Player
{
    constructor(id)
    {
        this.id = id;
        this.initials = "XXX";
        this.time = "00:00.00";
        this.timeMs = 0;
        this.dnf = false;
    }

    setTime(timeStr)
    {
        try
        {
            if (timeStr.includes("DNF"))
            {
                this.dnf = true;
                return;
            }
            this.time = timeStr;
            this.timeMs = this.strToMs(timeStr);
        }
        catch (e)
        {
            console.warn(e);
        }
    }

    strToMs(minSecMs)
    {
        const [min, secMs] = minSecMs.split(':');
        const [sec, ms] = secMs.split('.');
        const totalMs = (+min) * 60000 + (+sec) * 1000 + (+ms);
        return totalMs;
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
        this.recievedGameRunning = true;
        this.recievedTime = "";
        this.recievedLeaderboard = "";
    }
}

export const data = new Data();
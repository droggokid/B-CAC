export function ssend() {
    const xhr = new XMLHttpRequest();
    xhr.open('GET', 'http://127.0.0.1:8080');
    xhr.onload = function() {
    if (xhr.status === 200) {
        console.log(xhr.responseText);
        // setData(JSON.parse(xhr.responseText));
    }
    };
    xhr.send();
}

class Server
{
    constructor(url)
    {
        this.xhr = new XMLHttpRequest();
    }

    get()
    {

    }

    post()
    {

    }
}

export const server = new Server('http://127.0.0.1:8080');
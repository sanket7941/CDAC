const http = require('http');

const server = http.createServer((request, response) => {
    console.log(`request received with method: ${request.method} and url: ${request.url}`);

    if (request.method == 'POST')
     {
        if (request.url == '/redled/on') {
            console.log('turn on the RED LED');
        } else if (request.url == '/redled/off') {
            console.log('turn off the RED LED');
        } else if (request.url == '/greenled/off') {
            console.log('turn off the GREEN LED');
        } else if (request.url == '/greenled/on') {
            console.log('turn on the GREEN LED');
        } else if (request.url == '/yellowled/off') {
            console.log('turn off the YELLOW LED');
        } else if (request.url == '/yellowled/on') {
            console.log('turn on the YELLOW LED');
        }
    } else if (request.method == 'GET') {
        if (request.url == '/yellowled') {
            console.log('status: on');
        } else if (request.url == '/greenled') {
            console.log('status: off');
        } else if (request.url == '/redled') {
            console.log('status: on');
        }
    }
    response.end();
});



server.listen(4000, 'localhost', () => {
    console.log('server started on port 4000');
});
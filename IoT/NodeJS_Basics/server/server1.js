// import the http module
const http = require('http');

// create the server process
const server = http.createServer((request, response) => {
    console.log(`callback function is called`);
    console.log(`server has received a request`);

    // the response will be sent to the client
    response.end();
});

// start the server on a port
server.listen(4040, '0.0.0.0', () => {
    console.log('server started on port 4040');
});
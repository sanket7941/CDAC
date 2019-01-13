const http = require('http');

const server = http.createServer((request, response) => {
    // process

    console.log('new request received');

    // response.end('hello client..');
    // response.end('<h1>hello client</h1>');

    // json
    var result = `{muje abhi tak partttyyyy mnai mili ;(((  ))) :( }`;

    response.writeHead(200, { "Content-Type": "application/json" });
    response.end(result);
});

server.listen(4000, 'localhost', () => {
    console.log('server started on port 4000');
});
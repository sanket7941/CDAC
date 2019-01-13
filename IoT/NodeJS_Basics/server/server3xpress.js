// import
const express = require('express');

// create server (application)
const app = express();
/*
define glbal var for all things


*/
var  redLed,greenLed,yellowled;

// route
app.get('/greenled', (request, response) => {
    console.log('get /greenled  is called');
    console.log(`status=${greenLed}`);
    response.send(greenLed);
});

app.get('/redled', (request, response) => {
    console.log('get /redled  is called');
    response.send('off');
});

app.get('/yellowled', (request, response) => {
    console.log('get /yellowled  is called');
    response.send('off')
});

app.post('/greenled/:led_status', (request, response) => {

    // get the positional parameter
    var status = request.params.led_status;
    console.log('green led status: '  + status);

    // json
    var result = { "status": "success" };
    // var str = JSON.stringify(result);
    // response.writeHead(200, {'Content-Type': 'application/json'});
    // response.end(str);

    response.send(result);
});

app.post('/redled/:led_status', (request, response) => {
    var status = request.params.led_status;
    console.log('red led status: ' + status);
    redLed = status;
    response.send({ "result": "success" });
});

app.post('/yellowled/:led_status', (request, response) => {
    var status = request.params.led_status;
    console.log('yellow led status: ' + status);
    yellowled = status;
    response.send({ "result": "success" });
});

// listen on port 4000
app.listen(4000, '172.0.3.33', () => {
    console.log('server started on port 4000');
});
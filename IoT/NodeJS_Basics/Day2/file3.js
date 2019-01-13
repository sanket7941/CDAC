const os = require('os');

// console.log(os);
console.log(`platform: ${os.platform()}`);
console.log(`achitecture: ${os.arch()}`);
console.log(`memory: ${os.totalmem()}`);

var cpus = os.cpus();
for (var index = 0; index < cpus.length; index++) {
    var cpu = cpus[index];
    console.log(`model: ${cpu.model}`);
    console.log(`speed: ${cpu.speed}`);
}
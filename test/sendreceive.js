var Transmitter = require('../').Transmitter;
var Receiver = require('../').Receiver;

var t = new Transmitter(0);
var r = new Receiver(2);

function send(val) {
	console.log("Sending:", val);
	t.send(val);
}

r.on('error', function(err) {
	console.error("Error happened", err);
});
r.on('data', function(value) {
	console.log("Received: ", value);
	if(value < 10) {
		send(value + 1);
	}
});
r.on(10, function() {
	console.log("10 was received!");
	process.exit(0);
});

send(1);

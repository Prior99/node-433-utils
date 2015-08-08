var Receiver = require('../').Receiver;

var r = new Receiver(2);
r.on('error', function(err) {
	console.error("Error happened", err);
});
r.on('data', function(value) {
	console.log("Received: ", value);
});

var Util = require('util');
var EventEmitter = require('events').EventEmitter;

var Transmitter =  require('bindings')('433-utils').Transmitter;
var Receiver =  require('bindings')('433-utils').Receiver;

var WrappedReceiver = function(pin, interval) {
	if(interval === undefined) {
		interval = 2;
	}
	this.receiver = new Receiver(pin);
	setInterval(this._check.bind(this), interval);
};

Util.inherits(WrappedReceiver, EventEmitter);

WrappedReceiver.prototype._check = function() {
	if(this.receiver.available()) {
		var value = this.receiver.value();
		this.receiver.reset();
		if(value === 0) {
			this.emit('error', new Error("Unknown encoding"));
		}
		else {
			this.emit(value);
			this.emit('data', value);
		}
	}
};

module.exports = {
	Transmitter : Transmitter,
	Receiver : WrappedReceiver
};

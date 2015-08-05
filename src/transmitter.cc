#include "transmitter.h"


using namespace node;
using namespace v8;

Transmitter::Transmitter(unsigned int pin) : pin(pin) {
	if(wiringPiSetup() == -1) { //Check whether wpi has been setup correctly
		NanThrowTypeError("Error setting up wiring-pi.");
	}
	else {
		s.enableTransmit(pin); //And tell it which pin to use.
	}
}

Transmitter::~Transmitter() {
}

NAN_METHOD(Transmitter::New) {
	NanScope();
	if(!args.IsConstructCall()) {
		NanThrowTypeError("Must be called as constructor");
		NanReturnUndefined();
	}
	if(args.Length() < 1) {
		NanThrowTypeError("Incorrect number of arguments, expected number of GPIO pin to use.");
		NanReturnUndefined();
	}
	if(!args[0]->IsNumber()) {
		NanThrowTypeError("Expected first argument to be a number.");
		NanReturnUndefined();
	}
	Transmitter *instance = new Transmitter((unsigned int) args[0]->NumberValue());
	instance->Wrap(args.This());
	NanReturnValue(args.This());
}

NAN_METHOD(Transmitter::Send) {
	NanScope();
	Transmitter *instance = node::ObjectWrap::Unwrap<Transmitter>(args.This());
	if(args.Length() < 1) {
		NanThrowTypeError("Incorrect number of arguments, expected unsigned integer to send.");
		NanReturnUndefined();
	}
	if(!args[0]->IsNumber()) {
		NanThrowTypeError("Expected first argument to be a number.");
		NanReturnUndefined();
	}
	unsigned int length;
	if(args.Length() >= 2) {
		if(!args[0]->IsNumber()) {
			NanThrowTypeError("Expected second argument to be a number.");
			NanReturnUndefined();
		}
		length = (unsigned int) args[0]->NumberValue();
	}
	else {
		length = 24;
	}
	unsigned int value = (unsigned int) args[0]->NumberValue();
	instance->s.send(value, length);
	NanReturnValue(args.This());
}

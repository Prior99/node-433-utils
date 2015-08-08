#include "receiver.h"


using namespace node;
using namespace v8;

Receiver::Receiver(unsigned int pin) : pin(pin) {
	if(wiringPiSetup() == -1) { //Check whether wpi has been setup correctly
		NanThrowTypeError("Error setting up wiring-pi.");
	}
	else {
		s.enableReceive(pin); //And tell it which pin to use.
	}
}

Receiver::~Receiver() {
}

NAN_METHOD(Receiver::New) {
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
	Receiver *instance = new Receiver((unsigned int) args[0]->NumberValue());
	instance->Wrap(args.This());
	NanReturnValue(args.This());
}

NAN_METHOD(Receiver::reset) {
	NanScope();
	Receiver *instance = node::ObjectWrap::Unwrap<Receiver>(args.This());
	instance->s.resetAvailable();
	NanReturnValue(args.This());
}

NAN_METHOD(Receiver::available) {
	NanScope();
	Receiver *instance = node::ObjectWrap::Unwrap<Receiver>(args.This());
	bool b = instance->s.available();
	NanReturnValue(NanNew<Boolean>(b));
}

NAN_METHOD(Receiver::value) {
	NanScope();
	Receiver *instance = node::ObjectWrap::Unwrap<Receiver>(args.This());
	unsigned int value = instance->s.getReceivedValue();
	NanReturnValue(NanNew<Number>(value));
}

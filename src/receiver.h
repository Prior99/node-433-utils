#ifndef RECEIVER_H
#define RECEIVER_H

#include <v8.h>
#include <nan.h>
#include <node_buffer.h>
#include <iostream>
#include <wiringPi.h>

#include "../deps/433Utils/RPi_utils/RCSwitch.h"

class Receiver : public node::ObjectWrap {
	public:
		explicit Receiver(unsigned int);
		~Receiver();
		static NAN_METHOD(New);
		static NAN_METHOD(available);
		static NAN_METHOD(reset);
		static NAN_METHOD(value);
		RCSwitch s;
	private:
		unsigned int pin;
};

#endif

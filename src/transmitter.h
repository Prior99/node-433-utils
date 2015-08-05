#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <v8.h>
#include <nan.h>
#include <node_buffer.h>
#include <iostream>

#include "../deps/433Utils/RPi_utils/RCSwitch.h"

class Transmitter : public node::ObjectWrap {
	public:
		explicit Transmitter(unsigned int);
		~Transmitter();
		static NAN_METHOD(New);
		static NAN_METHOD(Send);
		RCSwitch s;
	private:
		unsigned int pin;
};

#endif

#include <v8.h>
#include <nan.h>
#include "transmitter.h"
#include "receiver.h"

using namespace node;
using namespace v8;

static void InitTransmitter(Handle<Object> exports) {
	Local<FunctionTemplate> transmit = NanNew<FunctionTemplate>(Transmitter::New);
	transmit->SetClassName(NanNew("Transmitter"));
	transmit->InstanceTemplate()->SetInternalFieldCount(1);
	transmit->PrototypeTemplate()->Set(NanNew("send"), NanNew<FunctionTemplate>(Transmitter::Send)->GetFunction());
	exports->Set(NanNew("Transmitter"), transmit->GetFunction());

	Local<FunctionTemplate> receive = NanNew<FunctionTemplate>(Receiver::New);
	receive->SetClassName(NanNew("Receiver"));
	receive->InstanceTemplate()->SetInternalFieldCount(1);
	receive->PrototypeTemplate()->Set(NanNew("reset"), NanNew<FunctionTemplate>(Receiver::reset)->GetFunction());
	receive->PrototypeTemplate()->Set(NanNew("available"), NanNew<FunctionTemplate>(Receiver::available)->GetFunction());
	receive->PrototypeTemplate()->Set(NanNew("value"), NanNew<FunctionTemplate>(Receiver::value)->GetFunction());
	exports->Set(NanNew("Receiver"), receive->GetFunction());
}

NODE_MODULE(433_utils, InitTransmitter);

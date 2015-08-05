#include <v8.h>
#include <nan.h>
#include "transmitter.h"

using namespace node;
using namespace v8;

static void InitTransmitter(Handle<Object> exports) {
	Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(Transmitter::New);
	tpl->SetClassName(NanNew("Transmitter"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);
	tpl->PrototypeTemplate()->Set(NanNew("send"), NanNew<FunctionTemplate>(Transmitter::Send)->GetFunction());
	exports->Set(NanNew("Transmitter"), tpl->GetFunction());
}

NODE_MODULE(433_utils, InitTransmitter);

#ifndef NODE_CPP_CALCULATOR_CALC_H
#define NODE_CPP_CALCULATOR_CALC_H

#include <napi.h>

namespace calc {
class CalcValue : public Napi::ObjectWrap<calc::CalcValue> {
private:
    int _value;
    static Napi::FunctionReference constructor;

    Napi::Value Add(const Napi::CallbackInfo &callbackInfo);
    Napi::Value Subtract(const Napi::CallbackInfo &callbackInfo);
    Napi::Value Multiply(const Napi::CallbackInfo &callbackInfo);
    Napi::Value Divide(const Napi::CallbackInfo &callbackInfo);
    Napi::Value Val(const Napi::CallbackInfo &callbackInfo);

public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    explicit CalcValue(const Napi::CallbackInfo &callbackInfo);
};
}

#endif //NODE_CPP_CALCULATOR_CALC_H

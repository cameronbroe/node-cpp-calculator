#include "calc.h"


namespace calc {

    CalcValue::CalcValue(const Napi::CallbackInfo &callbackInfo) : ObjectWrap<calc::CalcValue>(callbackInfo) {
        Napi::Number val = callbackInfo[0].As<Napi::Number>();
        this->_value = val.Int64Value();
    }

    Napi::Value CalcValue::Add(const Napi::CallbackInfo &callbackInfo) {
        Napi::Env env = callbackInfo.Env();
        Napi::Number val = callbackInfo[0].As<Napi::Number>();

        this->_value += val.Int64Value();
        return this->Value();
    }

    Napi::Value CalcValue::Subtract(const Napi::CallbackInfo &callbackInfo) {
        Napi::Env env = callbackInfo.Env();
        Napi::Number val = callbackInfo[0].As<Napi::Number>();

        this->_value -= val.Int64Value();
        return this->Value();
    }

    Napi::Value CalcValue::Multiply(const Napi::CallbackInfo &callbackInfo) {
        Napi::Env env = callbackInfo.Env();
        Napi::Number val = callbackInfo[0].As<Napi::Number>();

        this->_value *= val.Int64Value();
        return this->Value();
    }

    Napi::Value CalcValue::Divide(const Napi::CallbackInfo &callbackInfo) {
        Napi::Env env = callbackInfo.Env();
        Napi::Number val = callbackInfo[0].As<Napi::Number>();

        this->_value /= val.Int64Value();
        return this->Value();
    }

    Napi::Object CalcValue::Init(Napi::Env env, Napi::Object exports) {
        Napi::Function func = DefineClass(env, "CalcValue", {
            InstanceMethod("Add", &CalcValue::Add),
            InstanceMethod("Subtract", &CalcValue::Subtract),
            InstanceMethod("Multiply", &CalcValue::Multiply),
            InstanceMethod("Divide", &CalcValue::Divide),
            InstanceMethod("Val", &CalcValue::Val)
        });

        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set("CalcValue", func);
        return exports;
    }

    Napi::Value CalcValue::Val(const Napi::CallbackInfo &callbackInfo) {
        Napi::Env env = callbackInfo.Env();
        return Napi::Number::New(env, this->_value);
    }

    Napi::FunctionReference CalcValue::constructor;
}

// Initialize native add-on
Napi::Object Init (Napi::Env env, Napi::Object exports) {
    calc::CalcValue::Init(env, exports);
    return exports;
}

// Register and initialize native add-on
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
#pragma once
#ifndef PDK_SCRATCHVALUE
#define PDK_SCRATCHVALUE
#include <string>
class IScratchValue {
protected:
	std::string value;
public:
	virtual std::string asString() = 0;
	virtual double asDouble() = 0;
	virtual float asFloat() = 0;
	virtual int asInt() = 0;
	virtual bool asBool() = 0;
};
void InitObject(IScratchValue *&v);
#endif

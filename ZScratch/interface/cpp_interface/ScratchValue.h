#pragma once
#include "IScratchValue.h"
class ScratchValue :public IScratchValue {
public:
	virtual std::string asString();
	virtual double asDouble();
	virtual float asFloat();
	virtual int asInt();
	virtual bool asBool();
};

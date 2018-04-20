#include "ScratchValue.h"
#include <sstream>

std::string ScratchValue::asString() {
	return this->value;
}

double ScratchValue::asDouble() {
	double ret;
	std::stringstream strm;
	strm << value;
	strm >> ret;
	return ret;
}

float ScratchValue::asFloat() {
	float ret;
	std::stringstream strm;
	strm << value;
	strm >> ret;
	return ret;
}
int ScratchValue::asInt() {
	int ret;
	std::stringstream strm;
	strm << value;
	strm >> ret;
	return ret;
}
bool ScratchValue::asBool() {
	if (this->value.empty)
		return false;
	if (this->value == "false")
		return false;
	if (this->asInt == 0)
		return false;
	return true;
}
#ifndef _DEBUG
#endif

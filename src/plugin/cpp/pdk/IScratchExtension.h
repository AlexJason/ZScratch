#pragma once
//#ifndef SCEXT
//#define SCEXT "C++1.0"
#include <string>
class IScratchExtension {
public:
	std::string extid;
	std::string title;
	IScratchExtension() {}
	~IScratchExtension() {}
	virtual void construct() = 0;
	virtual void preInitialisation() {}
	virtual void Initialisation() {}
	virtual void postInitialisation() {}
//	virtual void eventCallback() {}
//	virtual void systemCallback() {}
//	virtual void systemInputOutput() {}
};
//#endif

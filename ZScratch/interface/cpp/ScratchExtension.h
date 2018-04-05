#pragma once
//#ifndef SCEXT
//#define SCEXT "C++1.0"
#include <string>
class ScratchExtension {
public:
	std::string extid;
	std::string title;
	ScratchExtension() {
		extid.clear();
		title.clear();
	}
	~ScratchExtension() {

	}
	virtual void preInitialisation() {

	}
	virtual void Initialisation() {

	}
	virtual void postInitialisation() {

	}
};
//#endif

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
	virtual void eventCallback() {

	}
};

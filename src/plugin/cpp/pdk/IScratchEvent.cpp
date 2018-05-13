#include "IScratchEvent.h"



IScratchEvent::IScratchEvent() {}


IScratchEvent::~IScratchEvent() {}

int IScratchEvent::RegisterEventCallback(std::function<int(void*)> callback) {
	this->callback.push_back(callback);
	return this->callback.size();
}

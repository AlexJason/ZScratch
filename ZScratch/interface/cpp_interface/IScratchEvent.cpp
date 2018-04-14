#include "IScratchEvent.h"



IScratchEvent::IScratchEvent() {}


IScratchEvent::~IScratchEvent() {}

int RegisterEventCallback(IScratchEvent * event, std::function<int(void*)> callback) {
	event->callback.push_back(callback);
	return event->callback.size();
}

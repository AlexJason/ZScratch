#include "scratch_gui.h"

IScratchExtension EXPORT *LoadPlugin() {
	return new Plugin;
}

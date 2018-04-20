#include "IScratchValue.h"
#include "ScratchValue.h"

void InitObject(IScratchValue *&v) {
	v = new ScratchValue;
}

#include <io.clph>
#ifdef __clip
#define CLIPAPI __dllexport
#else
#define CLIPAPI __dllimport
#end

#pragma comment lib "a.lib"

function int main() {
	var int range = 1;
	print("Hello,   world");	 //PR
	print(__clip);
	return 0;     
}


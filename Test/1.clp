#include <io.clph>
#ifdef __clip
#define CLIPAPI __dllexport
#else
#define CLIPAPI __dllimport
#end

#pragma comment lib "a.lib"

int main() {
	print("Hello,   world");	
	return 0;     
}

//EEEEE

/*
EEEEEEE
*/

#include "../include/Console.h"

bool WAC::Console::Create() {
	isAllocated = ::AllocConsole();
	if (!isAllocated)
		return false;
	
	errno_t err = freopen_s(&file, "CONOUT$", "w", stdout);
	if (err != 0) {
		FreeConsole();
		return false;
	}
	return true;
}

void WAC::Console::Destroy() {
	if (isAllocated) {
		fclose(file);
		FreeConsole();
	}
}
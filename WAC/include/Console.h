#pragma once
#include "base.h"
#include <iostream>

namespace WAC::Console {
	static bool isAllocated = false;
	static FILE* file = nullptr;

	bool Create();
	void Destroy();
}
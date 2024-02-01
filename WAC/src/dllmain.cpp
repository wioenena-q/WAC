#include "../include/base.h"
#include "../include/Console.h"

DWORD APIENTRY ThreadMain(HMODULE hModule) {
	WAC::Console::Create();
	while (!GetAsyncKeyState(VK_END)) {
		std::cout << "Hello World!" << std::endl;
		Sleep(1000);
	}
	WAC::Console::Destroy();
	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}

BOOL APIENTRY DllMain(
	HMODULE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved
) {
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		HANDLE hThread = CreateThread(
			NULL, NULL,
			reinterpret_cast<LPTHREAD_START_ROUTINE>(ThreadMain), hModule,
			NULL, NULL
		);
		if (hThread != NULL)
			CloseHandle(hThread);
	}
	return true;
}
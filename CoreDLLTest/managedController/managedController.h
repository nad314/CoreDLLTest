#pragma once
#using "WindowsBase.dll"
#using "PresentationFramework.dll"
#using "PresentationCore.dll"
#include <msclr\marshal.h>


public ref class ManagedController {
private:
	ManagedController^ current = nullptr;
	System::Windows::Window^ parentWindow;
public:
	ManagedController(System::Windows::Window^ wnd) { parentWindow = wnd; current = this; }

	[System::STAThreadAttribute]
	void Run();
	void Quit();
};

#include <main/main.h>

void ManagedController::Run() {
	HWND wnd = (HWND)System::Windows::Interop::WindowInteropHelper(parentWindow).Handle.ToInt32();
	core::Init()(new Program(wnd));
}

void ManagedController::Quit() {
	PostQuitMessage(0);
}

void ManagedController::Reshape() {
}
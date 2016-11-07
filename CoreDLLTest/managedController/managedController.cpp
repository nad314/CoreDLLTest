#include <main/main.h>

void ManagedController::Run() {
	HWND wnd = (HWND)System::Windows::Interop::WindowInteropHelper(parentWindow).Handle.ToInt32();
	core::Init()(new Program(wnd));
}

void ManagedController::Quit() {
	PostQuitMessage(0);
}

void ManagedController::Reshape() {
	int w = (int)(safe_cast<System::Windows::Controls::Grid^>(parentWindow->Content))->RenderSize.Width;
	int h = (int)(safe_cast<System::Windows::Controls::Grid^>(parentWindow->Content))->RenderSize.Height;
	MoveWindow(MainWindow::get(), 4, 4, w - 192 - 8, h - 8, true);
	MainWindow::get().DrawScene();
}
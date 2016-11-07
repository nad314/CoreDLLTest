#include <main/main.h>

void ManagedController::Run() {
	HWND wnd = (HWND)System::Windows::Interop::WindowInteropHelper(parentWindow).Handle.ToInt32();
	core::Init()(new Program(wnd));
}

void ManagedController::Quit() {
	PostQuitMessage(0);
}

void ManagedController::Reshape() {
	try {
		System::Windows::Controls::Grid^ grid = safe_cast<System::Windows::Controls::Grid^>(parentWindow->Content);
		if (grid->RowDefinitions->Count < 2 || grid->ColumnDefinitions->Count < 1) return;
		int gridHeight = (int)grid->RowDefinitions[1]->ActualHeight;
		int gridWidth = (int)grid->ColumnDefinitions[0]->ActualWidth;
		int menuHeight = grid->RowDefinitions[0]->ActualHeight;
		MainWindow::get().move(core::Rect(4, 4 + menuHeight, gridWidth - 4, gridHeight - 4 + menuHeight));
		MainWindow::get().DrawScene();
	} catch (System::InvalidCastException^ e){}
}

void ManagedController::InitGL() {
	glClearColor(0.2f, 0.2f, 0.22f, 1.0f);
	MainWindow::get().DrawScene();
}
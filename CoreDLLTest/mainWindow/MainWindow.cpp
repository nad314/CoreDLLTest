#include <main/main.h>

MainWindow* core::Getter<MainWindow>::getter = NULL;

void MainWindow::onOpening() {
	Window::onOpening();
	set(*this);
	setTitle("Core DLL Test");
	setFlags(glw_hidden);
}

void MainWindow::onClosing() {
	GL::makeCurrent(*this);
	Window::onClosing();
}

void MainWindow::onOpened() {
	Window::onOpened();

	SetParent(*this, hwParent);
	SetWindowLong(*this, GWL_STYLE, WS_CHILD|WS_VISIBLE);
	
	RECT r;
	GetClientRect(hwParent, &r);
	move(core::Rect(4, 4, r.right-r.left-260, r.bottom-r.top-4));

	ShowWindow(*this, SW_SHOWNORMAL);
	GL::createContext(*this);
	glClear(GL_COLOR_BUFFER_BIT);
	GL::swapBuffers(*this);
	GL::setVsync(0);

	ManagedController::get()->Reshape();
}

int MainWindow::onResize(const core::eventInfo& e) {
	Window::onResize(e);
	if (width < 1 || height < 1)
		return e;
	return e;
}

void MainWindow::DrawScene() {
	glClear(GL_COLOR_BUFFER_BIT);
	GL::swapBuffers(*this);
}


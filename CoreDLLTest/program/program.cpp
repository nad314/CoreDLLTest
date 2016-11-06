#include <main/main.h>

Program::Program(HWND hwParent) {
	Module();
	wnd.setHwParent(hwParent);
	wnd.setFlags(glw_hwparent);
}

int Program::onLoad() {
	return 0;
}

int Program::onDispose() {
	return 0;
}

int Program::onStart() {
	if (!wnd.open())
		return 1;
	return 0;
}

int Program::onStop() {
	wnd.close();
	return 0;
}

int Program::main() {
	bool done(0);
	while (!done) {
		if (wnd.peekMessageAsync(done))
			continue;
		wnd.DrawScene();
		Sleep(1);
	}
	return 0;
}

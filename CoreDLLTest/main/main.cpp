#include <main/main.h>

using namespace core::opengl;
#define DLL __declspec(dllexport)

extern "C" {
	DLL void Click() {
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	[System::STAThreadAttribute]
	DLL void Run(HWND wnd) {
		core::Init()(new Program(wnd));
	}

	DLL void Quit() {
		PostQuitMessage(0);
	}

	DLL void Reshape() {
	}
}

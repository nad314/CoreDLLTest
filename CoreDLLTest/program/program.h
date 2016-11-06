#pragma once

class Program final : public core::Module, public core::SIMD {
protected:
	MainWindow wnd; //view

public:
	Program(HWND hwParent);
	int onLoad() override;
	int onDispose() override;

	int onStart() override;
	int onStop() override;
	int main() override;
};

public ref class ManagedController {

};


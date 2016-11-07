#pragma once
class MainWindow final : public core::Window, public core::Getter<MainWindow> {
public:
public:
	void onOpening() override;
	void onClosing() override;
	void onOpened() override;

	int onResize(const core::eventInfo& e) override;
	void DrawScene();
};

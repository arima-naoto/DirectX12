#include "WinApp.h"
#include "DirectXCommon.h"

// Windowアプリのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	WinApp* win = nullptr;
	DirectXCommon* dxCommon = nullptr;

	win = WinApp::GetInstance();
	win->CreateGameWindow();

	dxCommon = DirectXCommon::GetInstance();
	dxCommon->Initialize(win);

	while (true) {
		if (win->ProcessMessage()) {
			break;
		}

		dxCommon->BeginDraw();

		dxCommon->EndDraw();

	}

	
	win->TerminateGameWindow();
	return 0;
}
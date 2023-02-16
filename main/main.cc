/*
				░█████╗░░█████╗░███████╗██╗██████╗░░░░░█████╗░░█████╗░
				██╔══██╗██╔══██╗██╔════╝██║██╔══██╗░░░██╔══██╗██╔══██╗
				███████║██║░░╚═╝█████╗░░██║██║░░██║░░░██║░░╚═╝██║░░╚═╝
				██╔══██║██║░░██╗██╔══╝░░██║██║░░██║░░░██║░░██╗██║░░██╗
				██║░░██║╚█████╔╝███████╗██║██████╔╝██╗╚█████╔╝╚█████╔╝
				╚═╝░░╚═╝░╚════╝░╚══════╝╚═╝╚═════╝░╚═╝░╚════╝░░╚════╝░

				  Ｔｈｅ ｃｏｄｅ ｗａｓ ｗｒｉｔｔｅｎ ｂｙ Ｋｉｎｙｓｈｕ

				  Links to Aceid.
				   - Website:	https://aceid.cc/
				   - Telegram:  https://t.me/aceid_cc
				   - VK:		https://vk.me/join/AJQ1dwO39CRYputL5JFysaY6

				  Contacts with Coder.
				   - VK:		https://vk.com/kinyshu
				   - Discord:   Kinyshu#5558

				  Github link:  https://github.com/Kinyshu

				  Donate.
				   - QIWI:      https://qiwi.com/n/KINYSHUACEID

				  Used in the project.
				   - HookLib:	https://github.com/HoShiMin/HookLib
				   - ImGui:		https://github.com/ocornut/imgui
				   - stb_image:	https://github.com/planetack/stb_image
				   - termcolor: https://github.com/ikalnytskyi/termcolor
*/
#include "stdafx.hpp"

class CInitialize
	: public IGameFrameworkListener {
public:

	void OnActionEvent(const SActionEvent& event) {

		auto gEnv = SSystemGlobalEnvironment::GetInstance();
		if (gEnv == 0) {
			return;
		}

		auto m_pFlowchartManager = reinterpret_cast<CGame*>(gEnv->pGame)->m_pFlowchartManager;
		if (m_pFlowchartManager == 0) {
			return;
		}

		if (event.m_event == EActionEvent::eAE_loadLevel
			|| m_pFlowchartManager->m_currentState == EFlowchartState::eFS_Lobby) {
			dxhook::create();
			gEnv->pGame->GetIGameFramework()->UnregisterListener(this);
		}
	}
};

void DllThread() {

	while (true) {

		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		auto gEnv = SSystemGlobalEnvironment::GetInstance();
		if (gEnv == 0) {
			continue;
		}

		auto pGame = gEnv->pGame;
		if (pGame == 0) {
			continue;
		}

		auto pFramework = pGame->GetIGameFramework();
		if (pFramework == 0) {
			continue;
		}

		web::Register();
		web::Update();

		web::user_id = web::GetUserId();
		web::username = web::GetUsername();

		pFramework->RegisterListener(new CInitialize(), "", FRAMEWORKLISTENERPRIORITY_GAME);

		CloseHandle(
			CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(web::OnlineThread), nullptr, 0, nullptr)
		);

		break;
	}
}

int __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {

	if (fdwReason == DLL_PROCESS_ATTACH) {
		CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(DllThread), nullptr, 0, nullptr);
	}

	return 1;
}
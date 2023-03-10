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
*/#pragma once

#ifndef HOOK_HPP
#define HOOK_HPP

#include "handler.hpp"

namespace vmt {

	template <typename T>
	T hook(void* Original, T Detour) {

		DWORD OldProtect = 0;
		VirtualProtect(Original, 4, 0x40, &OldProtect);

		auto original = *reinterpret_cast<T*>(Original);
		*reinterpret_cast<T*>(Original) = Detour;

		VirtualProtect(Original, 4, OldProtect, &OldProtect);

		return original;
	}

	std::uintptr_t* get(std::uintptr_t Pointer) {

		std::uintptr_t* buffer = nullptr;
		buffer = reinterpret_cast<std::uintptr_t*>(Pointer);
		buffer = reinterpret_cast<std::uintptr_t*>(buffer[0]);
		return buffer;
	}
}

namespace dxhook {

	bool create() {

		SSystemGlobalEnvironment* gEnv = SSystemGlobalEnvironment::GetInstance();

		std::uintptr_t* SwapChain = nullptr;
		SwapChain = reinterpret_cast<std::uintptr_t*>(reinterpret_cast<CRenderer*>(gEnv->pRenderer)->m_pSwapChain);
		SwapChain = reinterpret_cast<std::uintptr_t*>(SwapChain[0]);

		//handler::swapChainPresent = CreateHook<IDXGISwapChainPresent>(
		//	reinterpret_cast<void*>(SwapChain[8]), handler::hookPresent
		//	);

		//handler::resizeBuffers = CreateHook<ResizeBuffers>(
		//	reinterpret_cast<void*>(SwapChain[13]), handler::hookResizeBuffers
		//	);

		handler::swapChainPresent = vmt::hook(reinterpret_cast<void*>(&SwapChain[8]), handler::hookPresent);
		handler::resizeBuffers = vmt::hook(reinterpret_cast<void*>(&SwapChain[13]), handler::hookResizeBuffers);

		{
			gEnv->pGame->GetIGameFramework()->RegisterListener(new CWeaponListener(), 0, EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_GAME);
			gEnv->pGame->GetIGameFramework()->RegisterListener(new CVisualListener(), 0, EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_GAME);
			gEnv->pGame->GetIGameFramework()->RegisterListener(new CAimingListener(), 0, EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_GAME);

			gEnv->pGame->GetIGameFramework()->RegisterListener(new CActionsListener, 0, EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_GAME);
		}

		return true;
	}
}

#endif // !HOOK_HPP
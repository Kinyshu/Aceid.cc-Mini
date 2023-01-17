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

namespace dxhook {

	std::uintptr_t* __vtbl(void* __ptr64 ptr) {
		std::uintptr_t* vtbl = nullptr;
		{
			vtbl = reinterpret_cast<std::uintptr_t*>(ptr);
			vtbl = reinterpret_cast<std::uintptr_t*>(vtbl[0]);
		}

		return vtbl;
	}

	bool create() {

		WNDCLASSEXA wc;
		{
			wc.cbSize = sizeof WNDCLASSEXA;
			wc.lpfnWndProc = DefWindowProcA;
			wc.lpszClassName = "Dummy Class";
		}

		if (!::RegisterClassExA(&wc)) {
			return false;
		}

		handler::hwnd = CreateWindowA(wc.lpszClassName, "", WS_DISABLED, 0, 0, 0, 0, 0, 0, 0, nullptr);

		DXGI_SWAP_CHAIN_DESC desc;
		{
			desc.BufferCount = 1;
			desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
			desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
			desc.OutputWindow = handler::hwnd;
			desc.SampleDesc.Count = 1;
			desc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
			desc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
			desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
			desc.Windowed = TRUE;
		}

		D3D_FEATURE_LEVEL level;
		HRESULT result = ::D3D11CreateDeviceAndSwapChain(
			nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			nullptr, 0, nullptr, 0,
			D3D11_SDK_VERSION, &desc,
			&handler::g_swapChain,
			&handler::g_device,
			&level, &handler::g_deviceContext);

		if (result < 0) {
			::DestroyWindow(desc.OutputWindow);
			::UnregisterClassA(wc.lpszClassName, ::GetModuleHandleA(0));

			return false;
		}

		std::uintptr_t* sc = __vtbl(handler::g_swapChain);
		while (!sc) {
			sc = __vtbl(handler::g_swapChain);
		}

		const auto present = sc[8];
		const auto resizeBuffers = sc[13];

		handler::swapChainPresent = CreateHook<IDXGISwapChainPresent>(
			reinterpret_cast<void*>(present), handler::hookPresent
			);

		handler::resizeBuffers = CreateHook<ResizeBuffers>(
			reinterpret_cast<void*>(resizeBuffers), handler::hookResizeBuffers
			);

		SSystemGlobalEnvironment* gEnv = SSystemGlobalEnvironment::GetInstance();
		{
			gEnv->pGame->GetIGameFramework()->RegisterListener(new CWeaponListener(), 0, EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_GAME);
			gEnv->pGame->GetIGameFramework()->RegisterListener(new CVisualListener(), 0, EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_GAME);
			gEnv->pGame->GetIGameFramework()->RegisterListener(new CAimingListener(), 0, EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_GAME);
		}

		ShowWindow(GetConsoleWindow(), SW_HIDE);
		return true;
	}
}

#endif // !HOOK_HPP
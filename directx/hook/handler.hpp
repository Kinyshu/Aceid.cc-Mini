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

#ifndef HANDLER_HPP
#define HANDLER_HPP
#define CALC(x, y, w, h) { x, y }, { x + w, y + h }
#include "../../includes/imgui/imgui.h"
#include "../../includes/imgui/imgui_impl_win32.h"
#include "../../includes/imgui/imgui_impl_dx11.h"

#include "../gui/gui.hpp"

using WNDPROC = LRESULT(CALLBACK*)(HWND, UINT, WPARAM, LPARAM);
using IDXGISwapChainPresent = HRESULT(WINAPI*)(IDXGISwapChain*, UINT, UINT);
using D3D11ClearRenderTargetView = VOID(WINAPI*)(ID3D11DeviceContext*, ID3D11RenderTargetView*, const FLOAT[4]);
using ResizeBuffers = HRESULT(WINAPI*)(IDXGISwapChain*, UINT, UINT, UINT, DXGI_FORMAT, UINT);
using D3D11DrawIndexed = VOID(WINAPI*)(ID3D11DeviceContext*, UINT, UINT, INT);

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace dxhook::handler {

	int w = 0, h = 0;

	HWND hwnd;
	WNDPROC wndProc;

	ID3D11Device* g_device = nullptr;
	IDXGISwapChain* g_swapChain = nullptr;
	ID3D11DeviceContext* g_deviceContext = nullptr;

	IDXGISwapChainPresent swapChainPresent;
	D3D11ClearRenderTargetView clearRenderTargetView;
	ResizeBuffers resizeBuffers;
	D3D11DrawIndexed drawIndexed;

	static bool g_initialized = false;

	void createStyle() {

		ImGuiStyle* style = &ImGui::GetStyle();
		{
			style->Alpha = 1.f;

			style->WindowPadding = ImVec2();
			style->WindowRounding = 0.f;

			style->FrameRounding = 0.0f;
			style->ItemSpacing = { 15.f, 5.f };

			style->ScrollbarSize = 4.f;
			style->ScrollbarRounding = 0.f;

			style->GrabMinSize = 2.f;

			style->AntiAliasedLines = true;
			style->AntiAliasedFill = true;
			style->AntiAliasedLinesUseTex = true;

			style->FrameRounding = 6.f;

			style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
			style->Colors[ImGuiCol_TextDisabled] = ImColor(235, 235, 235, 255);

			style->Colors[ImGuiCol_WindowBg] = ImColor(55, 55, 55);
			style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
			style->Colors[ImGuiCol_Border] = ImColor(255, 255, 255, 0);
			style->Colors[ImGuiCol_FrameBg] = ImColor(22, 22, 22);

			style->Colors[ImGuiCol_Button] = ImColor(45, 45, 45);
			style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
			style->Colors[ImGuiCol_ButtonActive] = ImColor(40, 40, 40);

			style->Colors[ImGuiCol_ScrollbarBg] = ImColor(55, 55, 60);
			style->Colors[ImGuiCol_ScrollbarGrab] = ImColor(62, 87, 93);
			style->Colors[ImGuiCol_ScrollbarGrabActive] = ImColor(75, 95, 120);

			style->Colors[ImGuiCol_SliderGrab] = ImColor(55, 55, 60);
			style->Colors[ImGuiCol_SliderGrabActive] = ImColor(55, 75, 100);

			style->Colors[ImGuiCol_FrameBg] = ImColor(18, 18, 18);
			style->Colors[ImGuiCol_FrameBgHovered] = ImColor(40, 40, 40);
			style->Colors[ImGuiCol_FrameBgActive] = ImColor(45, 45, 45);
			style->Colors[ImGuiCol_CheckMark] = ImColor(255, 35, 35);

			style->Colors[ImGuiCol_Header] = ImColor(235, 35, 35);
			style->Colors[ImGuiCol_HeaderHovered] = ImColor(195, 35, 35);
			style->Colors[ImGuiCol_HeaderActive] = ImColor(225, 35, 35);
		}
	}

	LRESULT CALLBACK WndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam) {

		if (::ImGui_ImplWin32_WndProcHandler(handle, message, wParam, lParam))
			return true;

		return ::CallWindowProc(wndProc, handle, message, wParam, lParam);
	}

	std::tuple< int, int > wndWH(HWND hw) {

		auto monitor = MonitorFromWindow(hw, MONITOR_DEFAULTTONEAREST);

		MONITORINFO info;
		{
			info.cbSize = sizeof(MONITORINFO);
			GetMonitorInfo(monitor, &info);
		}

		return {
			info.rcMonitor.right - info.rcMonitor.left,
			info.rcMonitor.bottom - info.rcMonitor.top
		};
	}

	ImFont* font;
	void create(IDXGISwapChain* swapChain) {

		if (g_initialized == false) {
			swapChain->GetDevice(__uuidof(ID3D11Device), reinterpret_cast<void**>(&dxhook::handler::g_device));
			dxhook::handler::g_device->GetImmediateContext(&dxhook::handler::g_deviceContext);

			DXGI_SWAP_CHAIN_DESC desc;
			swapChain->GetDesc(&desc);

			dxhook::handler::hwnd = desc.OutputWindow;
			dxhook::handler::wndProc = reinterpret_cast<WNDPROC>(SetWindowLongPtrA(dxhook::handler::hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(WndProc)));

			std::tie(w, h) = wndWH(hwnd);

			/* ImGui */
			ImGui::CreateContext();

			ImGuiIO& io = ImGui::GetIO();
			io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;

			char path[MAX_PATH];
			GetWindowsDirectoryA(path, MAX_PATH);

			font = io.Fonts->AddFontFromFileTTF(std::string(path + std::string("\\Fonts\\Bahnschrift.ttf")).c_str(), 16.f, NULL, io.Fonts->GetGlyphRangesCyrillic());

			::ImGui_ImplDX11_Init(dxhook::handler::g_device, dxhook::handler::g_deviceContext);
			::ImGui_ImplWin32_Init(dxhook::handler::hwnd);

			createStyle();

			g_initialized = true;
		}
	}

	void resize(IDXGISwapChain* swapChain) {

		dxhook::handler::g_device->Release();
		dxhook::handler::g_deviceContext->Release();

		swapChain->GetDevice(__uuidof(ID3D11Device), reinterpret_cast<void**>(&dxhook::handler::g_device));
		dxhook::handler::g_device->GetImmediateContext(&dxhook::handler::g_deviceContext);

		::ImGui_ImplDX11_Init(dxhook::handler::g_device, dxhook::handler::g_deviceContext);
		::ImGui_ImplWin32_Init(dxhook::handler::hwnd);
	}

	HRESULT WINAPI hookPresent(IDXGISwapChain* swapChain, UINT interval, UINT flags) {

		if (::GetAsyncKeyState(VK_INSERT) & 1 || ::GetAsyncKeyState(VK_HOME) & 1) {
			ctx::ui = !ctx::ui;
		}

		dxhook::handler::create(swapChain);

		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();

		ImGui::NewFrame();
		{

			if (ctx::ui) {
				gui::Create(dxhook::handler::g_device);
				gui::Render();
			}

			if (ctx::drawFov) {
				ImGui::GetBackgroundDrawList()->AddCircle(
					ImVec2(SSystemGlobalEnvironment::GetInstance()->pRenderer->GetWidth() / 2,
						SSystemGlobalEnvironment::GetInstance()->pRenderer->GetHeight() / 2), 
					ctx::fov, ImColor(110, 3, 255), 0, 0.2f);
			}
		}
		ImGui::EndFrame();

		ImGui::Render();

		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

		return swapChainPresent(swapChain, interval, flags);
	}

	HRESULT WINAPI hookResizeBuffers(IDXGISwapChain* swapChain, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT format, UINT flags) {

		w = width;
		h = height;

		dxhook::handler::resize(swapChain);
		return resizeBuffers(swapChain, bufferCount, width, height, format, flags);
	}
}

#endif // !HANDLER_HPP
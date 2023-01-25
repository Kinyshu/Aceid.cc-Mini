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
#pragma once

#ifndef DATA_HPP
#define DATA_HPP

namespace data {

	std::uintptr_t gEnv = 0x14228E718;
	std::uintptr_t IRenderer = 0x48;
	std::uintptr_t IPhysicalWorld = 0x70;
	std::uintptr_t IConsole = 0xC8;
	std::uintptr_t IGame = 0xD0;
	std::uintptr_t I3DEngine = 0x100;

	std::uintptr_t SetGetCamera = 68;
	std::uintptr_t GetWidth = 102;
	std::uintptr_t GetHeight = 103;
	std::uintptr_t ProjectToScreenInternal = 112;

	std::uintptr_t RayWorldIntersection = 35;

	std::uintptr_t ShowConsole = 13;

	std::uintptr_t SCVars = 0x130;
	std::uintptr_t CFlowchartManager = 0x210;
	std::uintptr_t GetIGameFramework = 15;

	std::uintptr_t SetPostEffectParam = 146;

	std::uintptr_t cl_fov = 0x4;
	std::uintptr_t g_ingame_afk_timeout = 0x84C;
	std::uintptr_t g_gameroom_afk_timeout = 0x848;

	std::uintptr_t m_currentState = 0x30;

	std::uintptr_t GetClientActorInternal = 142;
	std::uintptr_t GetGameRules = 137;
	std::uintptr_t GetClientChannel = 71;

	std::uintptr_t GetHealth = 28;
	std::uintptr_t GetCurrentItem = 58;
	std::uintptr_t GetMovementController = 62;
}

#endif // !DATA_HPP
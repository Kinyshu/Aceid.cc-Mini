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

#ifndef SSYSTEMGLOBALENVIRONMENT_HPP
#define SSYSTEMGLOBALENVIRONMENT_HPP

#include "SPlatformInfo.hpp"

#include "../classes/CGame.hpp"
#include "../classes/CXConsole.hpp"
#include "../classes/CRenderer.hpp"
#include "../classes/C3DEngine.hpp"
#include "../classes/CScriptSystem.hpp"
#include "../classes/CPhysicalWorld.hpp"

#include "../classes/CSystem.hpp"

struct SSystemGlobalEnvironment {
public:
	ACEID_API CREATE_FUNCTOR(IScriptSystem*, pScriptSystem, 0x40);
	ACEID_API CREATE_FUNCTOR(IRenderer*, pRenderer, 0x48);
	ACEID_API CREATE_FUNCTOR(IPhysicalWorld*, pPhysicalWorld, 0x70);
	ACEID_API CREATE_FUNCTOR(CXConsole*, pConsole, 0xC8);
	ACEID_API CREATE_FUNCTOR(IGame*, pGame, 0xD0);
    ACEID_API CREATE_FUNCTOR(ISystem*, pSystem, 0xF0);
	ACEID_API CREATE_FUNCTOR(C3DEngine*, p3DEngine, 0x100);

	static SSystemGlobalEnvironment* GetInstance() {
		return *reinterpret_cast<SSystemGlobalEnvironment**>(data::gEnv);
	}
};

#endif // !SSYSTEMGLOBALENVIRONMENT_HPP
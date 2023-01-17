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

#ifndef CGAME_HPP
#define CGAME_HPP

#include "../interfaces/IGame.hpp"

#include "CHUD.hpp"
#include "CLobbyChat.hpp"
#include "COnlineAccount.hpp"
#include "CFlowchartManager.hpp"

struct SCVars {
	ACEID_API CREATE_FUNCTOR(float, cl_fov, data::cl_fov);
	ACEID_API CREATE_FUNCTOR(int, g_gameroom_afk_timeout, data::g_gameroom_afk_timeout);
	ACEID_API CREATE_FUNCTOR(int, g_ingame_afk_timeout, data::g_ingame_afk_timeout);
};

class CGame 
	: IGame {
public:

	ACEID_API CREATE_FUNCTOR(CHUD*, m_pHUD, 0x110); 								// Find: Libs/UI/HUD_Network_Icon.gfx
	ACEID_API CREATE_FUNCTOR(SCVars*, m_pCVars, data::SCVars);
	ACEID_API CREATE_FUNCTOR(CFlowchartManager*, m_pFlowchartManager, data::CFlowchartManager); 		// Find: FlowchartManager
	ACEID_API CREATE_FUNCTOR(COnlineAccount*, m_pOnlineAccount, 0x240); // Find: bootstrap
};

#endif // !CGAME_HPP
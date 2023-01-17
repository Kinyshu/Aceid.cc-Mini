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

#ifndef CHUD_HPP
#define CHUD_HPP

#include "CHUDCommon.hpp"
#include "CHUDTweakMenu.hpp"
#include "CHUDSilhouettes.hpp"

class CHUD
	: public CHUDCommon {
public:

	ACEID_API CREATE_FUNCTOR(CHUDTweakMenu*, m_pHUDTweakMenu, 0x70);
	ACEID_API CREATE_FUNCTOR(CHUDSilhouettes*, m_pHUDSilhouettes, 0x88);

	ACEID_API CREATE_FUNCTOR(int, m_playerAmmo, 0xCC);
	ACEID_API CREATE_FUNCTOR(int, m_playerClipSize, 0xD4);
	ACEID_API CREATE_FUNCTOR(int, m_iGrenadeAmmo, 0xC8);

	// IFFont* m_pDefaultFont; // 0xB0
	// v4->RegisterListener(v4, &this->IGameFrameworkListener, "hud", FRAMEWORKLISTENERPRIORITY_HUD);
}; 

#endif // !CHUD_HPP
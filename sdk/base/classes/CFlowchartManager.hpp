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

#ifndef CFLOWCHARTMANAGER_HPP
#define CFLOWCHARTMANAGER_HPP

enum EFlowchartState {

	eFS_None = 0xFFFFFFFF,
	eFS_First = 0x0,
	eFS_NoUI = 0x0,
	eFS_Login = 0x1,
	eFS_LoadingLobby = 0x2,
	eFS_CharacterCreation = 0x3,
	eFS_Lobby = 0x4,
	eFS_LoadingLevel = 0x5,
	eFS_Ingame = 0x6,
	eFS_Renaming = 0x7,
	eFS_PromoTutorial = 0x8,
	eFS_PostGame = 0x9,
	eFS_Count = 0xA,
};

class CFlowchartManager {
public:

	ACEID_API CREATE_FUNCTOR(EFlowchartState, m_currentState, data::m_currentState);
};

#endif // !CFLOWCHARTMANAGER_HPP

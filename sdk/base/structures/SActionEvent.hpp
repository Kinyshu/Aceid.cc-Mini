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

#ifndef SACTIONEVENT_HPP
#define SACTIONEVENT_HPP

enum EActionEvent {

	eAE_channelCreated = 0x0,
	eAE_channelDestroyed = 0x1,
	eAE_connectFailed = 0x2,
	eAE_connected = 0x3,
	eAE_disconnected = 0x4,
	eAE_clientDisconnected = 0x5,
	eAE_resetBegin = 0x6,
	eAE_resetEnd = 0x7,
	eAE_resetProgress = 0x8,
	eAE_preSaveGame = 0x9,
	eAE_postSaveGame = 0xA,
	eAE_inGame = 0xB,
	eAE_serverName = 0xC,
	eAE_serverIp = 0xD,
	eAE_earlyPreUpdate = 0xE,
	eAE_demoRecorderCreated = 0xF,
	eAE_mapCmdIssued = 0x10,
	eAE_unloadLevel = 0x11,
	eAE_postUnloadLevel = 0x12,
	eAE_loadLevel = 0x13,
	eAE_demoRecorderDestroyed = 0x14,
};

struct SActionEvent {

	EActionEvent m_event;
	int m_value;
	const char* m_description;
};

#endif // !SACTIONEVENT_HPP

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

#ifndef EENTITYASPECTS_HPP
#define EENTITYASPECTS_HPP

enum EEntityAspects {

	eEA_All = 0xFFFFFFFF,
	eEA_Script = 0x2,
	eEA_Physics = 0x8,
	eEA_GameClientStatic = 0x10,
	eEA_GameServerStatic = 0x20,
	eEA_GameClientDynamic = 0x40,
	eEA_GameServerDynamic = 0x80,
	eEA_GameClientA = 0x100,
	eEA_GameServerA = 0x200,
	eEA_GameClientB = 0x400,
	eEA_GameServerB = 0x800,
	eEA_GameClientC = 0x1000,
	eEA_GameServerC = 0x2000,
	eEA_GameClientD = 0x4000,
	eEA_GameClientE = 0x8000,
	eEA_GameClientF = 0x10000,
	eEA_GameClientG = 0x20000,
	eEA_GameClientH = 0x40000,
	eEA_GameClientI = 0x80000,
	eEA_GameClientJ = 0x100000,
	eEA_GameServerD = 0x200000,
	eEA_GameClientK = 0x400000,
	eEA_Aspect23 = 0x800000,
	eEA_Aspect24 = 0x1000000,
	eEA_Aspect25 = 0x2000000,
	eEA_Aspect26 = 0x4000000,
	eEA_Aspect27 = 0x8000000,
	eEA_Aspect28 = 0x10000000,
	eEA_Aspect29 = 0x20000000,
	eEA_Aspect30 = 0x40000000,
	eEA_Aspect31 = 0x80000000,
};

#endif // !EENTITYASPECTS_HPP

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

#ifndef STHREADTASKPARAMS_HPP
#define STHREADTASKPARAMS_HPP

struct SThreadTaskParams {

	SThreadTaskParams(const char* Name) {
		nFlags = 0;
		name = Name;
		nPreferedThread = 0;
		nThreadsGroupId = 0;
		nPriorityOff = 0;
		nStackSizeKB = 0;
	}

	unsigned int nFlags;
	int nPreferedThread;
	int nThreadsGroupId;
	__int16 nPriorityOff;
	__int16 nStackSizeKB;
	const char* name;
};

#endif // !STHREADTASKPARAMS_HPP
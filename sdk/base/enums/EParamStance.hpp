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

#ifndef EPARAMSTANCE_HPP
#define EPARAMSTANCE_HPP

enum EParamStance {

	eS_First = 0x0,
	eS_Stand = 0x0,
	eS_Crouch = 0x1,
	eS_Prone = 0x2,
	eS_ZoomedStand = 0x3,
	eS_ZoomedCrouch = 0x4,
	eS_ZoomedProne = 0x5,
	eS_Haste = 0x6,
	eS_Run = 0x7,
	eS_Walk = 0x8,
	eS_Jump = 0x9,
	eS_ZoomedJump = 0xA,
	eS_ZoomedWalk = 0xB,
	eS_Rest = 0xC,
	eS_ZoomedRest = 0xD,
	eS_Transition = 0xE,
	eS_Knockdown = 0xF,
	eS_ZoomedKnockdown = 0x10,
	eS_Slide = 0x11,
	eS_ZoomedSlide = 0x12,
	eS_Last = 0x13,
	eS_Num = 0x13,
};

#endif // !EPARAMSTANCE_HPP
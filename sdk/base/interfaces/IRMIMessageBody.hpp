﻿/*
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

#ifndef IRMIMESSAGEBODY_HPP
#define IRMIMESSAGEBODY_HPP

#include "../enums/ENetReliabilityType.hpp"
#include "../enums/ERMIAttachmentType.hpp"

#include "../structures/SNetMessageDef.hpp"

interface IRMIMessageBody {
public:

	virtual void vecDelDtor() = 0;
	virtual void SerializeWith(void*) = 0;
	virtual unsigned __int64 GetSize() = 0;
	virtual void DeleteThis();

public:
	ENetReliabilityType reliability;
	ERMIAttachmentType attachment;
	const unsigned int objId;
	const unsigned int dependentId;
	const char funcId;
	SNetMessageDef* pMessageDef;
	const int userId;
	interface IRMIListener* pListener;
	volatile int m_cnt;
};

#endif // !IRMIMESSAGEBODY_HPP
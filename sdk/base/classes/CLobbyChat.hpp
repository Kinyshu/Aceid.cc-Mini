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

#ifndef CLOBBYCHAT_HPP
#define CLOBBYCHAT_HPP

#undef SendMessage

enum ELobbyChatChannel {

	eCC_First = 0x0,
	eCC_Global = 0x0,
	eCC_Room = 0x1,
	eCC_Team = 0x2,
	eCC_Clan = 0x3,
	eCC_Observer = 0x4,
	eCC_Whisper = 0x5,
	eCC_Count = 0x6,
};

struct SLobbyChatMessage {

	CryStringT<char> nick;
	CryStringT<char> message;
	bool is_local;
	bool is_service;
	CTimeValue time_stamp;
};

struct SChannelAntispamCfg {

	CTimeValue highFrequency;
	CTimeValue lowFrequency;
	CTimeValue notifFrequency;
};

class CLobbyChat
	/* : IOnlineServiceStatusListener, IChatChannelInfoListener, IGameRoomListener, IClansListener, IFlowchartListener */ {
public:

};

#endif // !CLOBBYCHAT_HPP
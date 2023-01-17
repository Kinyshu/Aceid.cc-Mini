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

#ifndef SMASTERSERVERINFO_HPP
#define SMASTERSERVERINFO_HPP

#include "../classes/CryStringT.hpp"

using EStatus = int;
using EChannelType = int;

using M_LOAD_MAP = std::map<CryStringT<char>, int, std::less<CryStringT<char> >, std::allocator<std::pair<CryStringT<char> const, int>>>;

struct SMasterServerInfo {

	enum EChannelRankGroup {

		All = 0x0,
		Newbie = 0x1,
		Skilled = 0x2,
	};

	int server_id;
	CryStringT<char> resource;
	CryStringT<char> channel;
	CryStringT<char> bootstrap;
	EChannelType channel_type;
	EChannelRankGroup rank_group;
	float load;
	int online_users;
	EStatus status;
	int min_rank;
	int max_rank;
	M_LOAD_MAP loadMap;
};


#endif // !SMASTERSERVERINFO_HPP
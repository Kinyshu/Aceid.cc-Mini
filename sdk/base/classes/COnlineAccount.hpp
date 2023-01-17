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

#ifndef CONLINEACCOUNT_HPP
#define CONLINE_ACCOUNT_HPP

#include "CTimeValue.hpp"
#include "CryStringT.hpp"
#include "../structures/SAuthProfileInfo.hpp"
#include "COnlineVariables.hpp"
#include "CLocalProfileConfig.hpp"
#include "COnlineChannel.hpp"
#include "COnlineProfile.hpp"

using V_ONLINE_SERVERS = std::vector<CryStringT<char>, std::allocator<CryStringT<char>>>;
using V_AUTH_PROFILE_INFO = std::vector<SAuthProfileInfo, std::allocator<SAuthProfileInfo>>;

class COnlineAccount {
public:

	enum EConnectionState {

		ECS_Disconnected = 0x0,
		ECS_WaitingForCredentials = 0x1,
		ECS_WaitingForConnection = 0x2,
		ECS_WaitingForDisconnect = 0x3,
		ECS_Connected = 0x4,
	};
public:

	using fnLogout = void(__fastcall*)(COnlineAccount*, bool);
	void Logout(bool scheduleDelayed) {
		fnLogout(0x14126D5A0)(this, scheduleDelayed);
	}
public:

	ACEID_API CREATE_FUNCTOR(bool, m_isForcedReconnectSceduled, 0x10);
	ACEID_API CREATE_FUNCTOR(bool, m_isForcedLogoutSceduled, 0x11);
	ACEID_API CREATE_FUNCTOR(bool, m_reconnectMode, 0x12);
	ACEID_API CREATE_FUNCTOR(CTimeValue, m_lastReconnectTime, 0x18);
	ACEID_API CREATE_FUNCTOR(int, m_reconnectTimeout, 0x20);
	ACEID_API CREATE_FUNCTOR(int, m_ignoreForcedReconnect, 0x24);
	ACEID_API CREATE_FUNCTOR(int, m_survivalLbEnabled, 0x28);
	ACEID_API CREATE_FUNCTOR(unsigned __int64, m_userId, 0x30);
	ACEID_API CREATE_FUNCTOR(CryStringT<char>, m_tokenId, 0x38);
	ACEID_API CREATE_FUNCTOR(V_AUTH_PROFILE_INFO, m_account_profiles, 0x48);
	ACEID_API CREATE_FUNCTOR(COnlineVariables*, m_variables, 0x60);
	ACEID_API CREATE_FUNCTOR(CLocalProfileConfig*, m_local_config, 0x68);
	ACEID_API CREATE_FUNCTOR(V_ONLINE_SERVERS, m_online_servers, 0x80);
	ACEID_API CREATE_FUNCTOR(unsigned __int64, m_current_server, 0x98);
	ACEID_API CREATE_FUNCTOR(CryStringT<char>, m_host, 0xA0);
	ACEID_API CREATE_FUNCTOR(CryStringT<char>, m_regionId, 0xB0);
	ACEID_API CREATE_FUNCTOR(EConnectionState, m_state, 0xC0);
	ACEID_API CREATE_FUNCTOR(COnlineChannel*, m_channel, 0xD8);
	ACEID_API CREATE_FUNCTOR(COnlineProfile*, m_profile, 0xE0);
};

#endif // !CONLINEACCOUNT_HPP
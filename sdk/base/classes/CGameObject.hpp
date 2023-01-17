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

#ifndef CGAMEOBJECT_HPP
#define CGAMEOBJECT_HPP

#include "../interfaces/IGameObject.hpp"
#include "../interfaces/IGameObjectView.hpp"
#include "../interfaces/IGameObjectProfileManager.hpp"

#include "../structures/SGameObjectExtensionRMI.hpp"

struct SDistanceChecker {

	unsigned int m_distanceChecker;
	float m_distanceCheckerTimer;
};

class CWorldQuery {
public:
	ACEID_API CREATE_FUNCTOR(EntityId, m_lookAtEntityId, 0x170);
};

class CGameObject
	: IGameObject {
public:

	enum EUpdateState {

		eUS_Visible_Close = 0x0,
		eUS_Visible_FarAway = 0x1,
		eUS_NotVisible_Close = 0x2,
		eUS_NotVisible_FarAway = 0x3,
		eUS_CheckVisibility_Close = 0x4,
		eUS_CheckVisibility_FarAway = 0x5,
		eUS_COUNT_STATES = 0x6,
		eUS_INVALID = 0x6,
	};

	enum EUpdateStateEvent {

		eUSE_BecomeVisible = 0x0,
		eUSE_BecomeClose = 0x1,
		eUSE_BecomeFarAway = 0x2,
		eUSE_Timeout = 0x3,
		eUSE_COUNT_EVENTS = 0x4,
	};

	struct SExtension {

		interface IGameObjectExtension* pExtension;
		unsigned __int16 id;
		char refCount;
		char updateEnables[5];
		char forceEnables[5];
		__int8 flagUpdateWhenVisible : 5;
		__int8 flagUpdateWhenInRange : 5;
		__int8 flagUpdateCombineOr : 5;
		__int8 flagDisableWithAI : 5;
		__int8 flagNeverUpdate : 5;
		__int8 activated : 1;
		__int8 sticky : 1;
		__int8 postUpdate : 1;
	};
	using V_EXTENSIONS = std::vector<SExtension, std::allocator<SExtension> >;

public:

	CWorldQuery* GetWorldQuery() {
		return __vtbl< CWorldQuery*, 51 >(this);
	}

public:

	ACEID_API CREATE_FUNCTOR(IGameObjectView*, m_pViewDelegate, 0x30);
	ACEID_API CREATE_FUNCTOR(IGameObjectProfileManager*, m_pProfileManager, 0x38);
	ACEID_API CREATE_FUNCTOR(V_EXTENSIONS, m_extensions, 0x68);
	ACEID_API CREATE_FUNCTOR(unsigned __int16, m_channelId, 0x80);
	ACEID_API CREATE_FUNCTOR(unsigned int, m_enabledAspects, 0x84);
	ACEID_API CREATE_FUNCTOR(SDistanceChecker, m_distanceChecker, 0xA4);
};

#endif // !CGAMEOBJECT_HPP
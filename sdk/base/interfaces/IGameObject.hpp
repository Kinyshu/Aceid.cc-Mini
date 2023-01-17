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

#ifndef IGAMEOBJECT_HPP
#define IGAMEOBJECT_HPP

#include "../classes/CEntity.hpp"
#include "IMovementController.hpp"

#include "../interfaces/IRMIMessageBody.hpp"

enum ERMInvocation {

	eRMI_ToClientChannel = 0x1,
	eRMI_ToOwnClient = 0x2,
	eRMI_ToOtherClients = 0x4,
	eRMI_ToAllClients = 0x8,
	eRMI_ToServer = 0x100,
	eRMI_NoLocalCalls = 0x10000,
	eRMI_NoRemoteCalls = 0x20000,
	eRMI_ToRemoteClients = 0x10008,
};

interface IGameObject {

	enum EChangeExtension {

		eCE_Activate = 0x0,
		eCE_Deactivate = 0x1,
		eCE_Acquire = 0x2,
		eCE_Release = 0x3,
	};

	class CRMIBody 
		: public IRMIMessageBody {
	public:

	};

	template <typename T>
	class CRMIBodyImpl
		: public CRMIBody {
	public:
		T m_params;
	};

	template <typename T>
	void DoInvokeRMI(CRMIBodyImpl< T >** pBody , unsigned int where, int channel) {
		__vtbl< void, 56 >(this, pBody, where, channel);
	}

	ACEID_API CREATE_FUNCTOR(EntityId, m_entityId, 0x8);
	ACEID_API CREATE_FUNCTOR(IMovementController*, m_pMovementController, 0x10);
	ACEID_API CREATE_FUNCTOR(IEntity*, m_pEntity, 0x10);
};

#endif // !IGAMEOBJECT_HPP
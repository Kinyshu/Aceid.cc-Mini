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

#ifndef IGAMEFRAMEWORK_HPP
#define IGAMEFRAMEWORK_HPP

#include "../classes/CPlayer.hpp"
#include "IGameFrameworkListener.hpp"
#include "../classes/CActorSystem.hpp"

#include "../classes/CGameRules.hpp"

interface IGameFramework {
public:

	CActorSystem* GetIActorSystem() {
		return __vtbl< CActorSystem*, 25 >(this);
	}

	CTimeValue* GetServerTime(CTimeValue* result) {
		return __vtbl< CTimeValue*, 73 >(this, result);
	}

	void RegisterListener(IGameFrameworkListener* pGameFrameworkListener, const char* name,
		EFRAMEWORKLISTENERPRIORITY eFrameworkListenerPriority) {
		__vtbl< void, 108 >(this, pGameFrameworkListener, name, eFrameworkListenerPriority); 
	}

	void UnregisterListener(IGameFrameworkListener* pGameFrameworkListener) { 
		__vtbl< void, 109 >(this, pGameFrameworkListener); 
	}

	CGameRules* GetGameRules() {
		return __ivtbl< CGameRules* >(this, data::GetGameRules);
	}

	char GetClientActorInternal(IActor** pOutActor) {
		return __ivtbl< char >(this, data::GetClientActorInternal, pOutActor);
	}

	void* GetClientChannel() {
		return __ivtbl<void*>(this, data::GetClientChannel);
	}
};

#endif // !IGAMEFRAMEWORK_HPP

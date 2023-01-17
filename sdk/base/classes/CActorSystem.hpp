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

#ifndef CACTORSYSTEM_HPP
#define CACTORSYSTEM_HPP

#include "CActor.hpp"
#include "../interfaces/IActorSystem.hpp"

using M_ACTORS = std::map<unsigned int, CActor*, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, CActor*>>>;

class CActorSystem :
	IActorSystem {
public:
	CActor* GetActor(EntityId entityId) { 
		return __vtbl< CActor*, 15 >(this, entityId);
	}

	CActor* FindActorById(EntityId id) {
		auto pActor = this->m_actors.find(id)->second;
		return pActor != nullptr ? pActor : nullptr;
	}

	CActor* FindActorByName(const char* name) {
		for (auto it : this->m_actors) {

			auto m_name = reinterpret_cast<IActor*>(it.second)->m_pEntity->GetName();
			if (strstr(m_name, name)) {
				return it.second;
			}
		}

		return nullptr;
	}
public:

	ACEID_API CREATE_FUNCTOR(M_ACTORS, m_actors, 0x30);
};

#endif // !CACTORSYSTEM_HPP
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

#ifndef CWEAPONGENERAL_HPP
#define CWEAPONGENERAL_HPP

#include "../interfaces/IWeaponGeneral.hpp"
#include "CFireModeObjectBase.hpp"
#include "CClipMode.hpp"

#include "CWeaponNetwork.hpp"

class CWeaponGeneral
	: IWeaponGeneral {
public:

	using FN_IsReloadingAvailable = bool(__fastcall*)(CWeaponGeneral*, bool);
	bool IsReloadingAvailable(bool manual = true) {
		return FN_IsReloadingAvailable(0x14131CD40)(this, manual);
	}

	CWeaponNetwork** GetNetwork() { return *(CWeaponNetwork***)((uintptr_t)this + 0x50); }
	using FN_RequestReload = void(__fastcall*)(void* __ptr64, bool);
	void RequestReload(bool manual) {
		FN_RequestReload(0x1413D83B0)(this->GetNetwork(), manual);
	}
public:

	ACEID_API CREATE_FUNCTOR(CWeaponNetwork**, m_network, 0x50);
	ACEID_API CREATE_FUNCTOR(IClipMode*, m_clipmode, 0x68);
	ACEID_API CREATE_FUNCTOR(std::vector<IFireModeObject*>, m_firemodes, 0x80);
	ACEID_API CREATE_FUNCTOR(std::uint32_t, m_currFiremode, 0xBC);
};

#endif // !CWEAPONGENERAL_HPP

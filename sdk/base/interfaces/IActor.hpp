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

#ifndef IACTOR_HPP
#define IACTOR_HPP

#include "../classes/CEntity.hpp"
#include "../classes/CGameObjectExtensionHelper.hpp"
#include "../classes/CItemProxy.hpp"

#include "../enums/EBonesID.hpp"
#include "../math/Vec3_tpl.hpp"

#include "../interfaces/IMovementController.hpp"

interface IActor 
	: IGameObjectExtension {
public:
	int GetHealth() {
		return __ivtbl< int >(this, data::GetHealth);
	}

	bool IsDead() {
		return this->GetHealth() <= 0;
	}

	IItemProxy* GetCurrentItem() {
		return __ivtbl< IItemProxy* >(this, data::GetCurrentItem);
	}

	IMovementController* GetMovementController() {
		return __ivtbl< IMovementController* >(this, data::GetMovementController);
	}

	void SetThirdPerson(bool bValue) {
		__vtbl< void, 67 >(this, bValue);
	}

	bool GetBonePos(Vec3_tpl<float>* pos, EBonesID ID, int slot, int* pBoneIndex) {
		return __vtbl< bool, 158 >(this, pos, ID, slot, pBoneIndex);
	}

	void Revive(bool bFromInit) {
		return __vtbl< void, 127 >(this, bFromInit);
	}

	void LocalRevive() {
		return __vtbl< void, 167 >(this);
	}

	void SetActorModel() {
		return __vtbl< void, 169 >(this);
	}

	void NetworkUpdateCharacterParams() {
		return __vtbl< void, 181 >(this);
	}
};

#endif // !IACTOR_HPP*
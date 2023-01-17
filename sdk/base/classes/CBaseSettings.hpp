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

#ifndef CBASESETTINGS_HPP
#define CBASESETTINGS_HPP

#include "../enums/ECharacterClassId.hpp"

#include "../math/math.hpp"

#include "CEntityClass.hpp"

class CBaseSettings {
public:

	enum EFiremode {

		eFM_First = 0x0,
		eFM_Single = 0x0,
		eFM_SingleSmoothed = 0x1,
		eFM_Rapid = 0x2,
		eFM_Burst = 0x3,
		eFM_RapidBurst = 0x4,
		eFM_Restore = 0x5,
		eFM_Throw = 0x6,
		eFM_UnderBarrel = 0x7,
		eFM_Melee = 0x8,
		eFM_Plant = 0x9,
		eFM_Drop = 0xA,
		eFM_Defibrillator = 0xB,
		eFM_Resurrect = 0xC,
		eFM_Control = 0xD,
		eFM_Last = 0xE,
		eFM_Num = 0xE,
	};

	enum eCombatLogIcon {

		eCLI_Default = 0x0,
		eCLI_Melee = 0x1,
		eCLI_Resurrect = 0x2,
	};


	struct SClassRestrictionParams {
		virtual bool CheckClassRestriction(ECharacterClassId classId) = 0;
		virtual void ParseClassRestrictions(CryStringT<char>* restrictions) = 0;

		bool m_class_restrictions[5];
	};

	struct SFireParams {
		int pellets;
		IEntityClass* ammo_type_class;
		int extra_ammo;
		int place_on_ground;
		int throwing;
		float hold_time;
		Vec3_tpl<float> ai_muzzle_pos;
		Vec3_tpl<float> force_launch_dir;
	};


	struct SFireModeParams 
		: _reference_target<int> {

		CBaseSettings::EFiremode fireMode;
		int rpm_burst;
		int burst_bullet_count;
		CryStringT<char> fireModeIcon;
		CryStringT<char> mfEffect;
	};
	using V_FIREMODEPARAMS = std::vector<SFireModeParams*, std::allocator<SFireModeParams*>>;

	struct SDropModelParams {

		CryStringT<char> m_model;
		float m_modelScale;
	};

public:

	SFireModeParams* GetFireModeParams(int idx) {
		return this->m_firemodes[idx];
	}

public:

	ACEID_API CREATE_FUNCTOR_STRUCT(SFireParams, m_fireparams, 0x10); // "fire" xref: +17
	ACEID_API CREATE_FUNCTOR(V_FIREMODEPARAMS, m_firemodes, 0x68); /*               description_ingame (CBaseSettings::ReadFiremodes(v3, v32);)             */
	ACEID_API CREATE_FUNCTOR(CryStringT<char>, m_name, 0x408); // @combatlog_weapon_refilled
};//@combatlog_weapon_refilled

#endif // !CBASESETTINGS_HPP

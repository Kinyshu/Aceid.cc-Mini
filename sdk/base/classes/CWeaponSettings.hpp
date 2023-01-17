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

#ifndef CWEAPONSETTINGS_HPP
#define CWEAPONSETTINGS_HPP

#include "../math/Vec2_tpl.hpp"

#include "CBaseSettings.hpp"
#include "CMaskedVarT.hpp"

class CWeaponSettings
	: public CBaseSettings {
public:

	enum eInteractType {

		eIT_First = 0x0,
		eIT_Heal = 0x0,
		eIT_Repair = 0x1,
		eIT_Resurrect = 0x2,
		eIT_Damage = 0x3,
		eIT_GiveAmmo = 0x4,
		eIT_Plant = 0x5,
		eIT_None = 0x6,
		eIT_Last = 0x6,
	};

	class CRecoilParams {
	public:
		int m_hintLoopStart;
		std::vector<Vec2_tpl<CMaskedVarT<float, unsigned int>>, std::allocator<Vec2_tpl<CMaskedVarT<float, unsigned int>>>> m_hints;
		std::vector<CMaskedVarT<float, unsigned int>, std::allocator<CMaskedVarT<float, unsigned int> > > m_muls;
	};

	class CSpreadParams {
	public:
		std::vector<CMaskedVarT<float, unsigned int>, std::allocator<CMaskedVarT<float, unsigned int> > > m_muls;
	};

	class CClipParams {
	public:
		bool m_isBarrel;
		bool m_isUnlimited;
		bool m_isUnlimitedInventory;
		bool m_isAutoReloadEnabled;
		bool m_isManualReloadEnabled;
	};

	class CMeleeParams {
	public:
		CryStringT<char> m_hitType;
		float m_impulse;
		float m_aoeHeight;
		bool m_noRayTest;
		bool m_armorAbsorb;
		int m_pierceability;
		bool m_aoe_enabled;
	};

	class CAmmoPackParams 
		: CBaseSettings::SClassRestrictionParams {
	public:
		std::vector<struct SProfileItem, std::allocator<SProfileItem> > m_ammoPackItemsList;
		CryStringT<char> m_ammoPackModel;
		float m_dropDuration;
		CWeaponSettings::eInteractType m_interactType;
	};

	class CResurrectParams : CBaseSettings::SClassRestrictionParams {
	public:
		CMaskedVarT<float, unsigned int> m_resurrectDuration;
		CMaskedVarT<float, unsigned int> m_activateDuration;
		CMaskedVarT<float, unsigned int> m_distance;
		CryStringT<char> m_hitType;
		float m_healthMult;
		std::set<enum ECharacterClassId, std::less<enum ECharacterClassId>, std::allocator<enum ECharacterClassId> > m_class_restrictions;
	};


	class CDFDamageParams {
	public:
		CMaskedVarT<float, unsigned int> m_hitDuration;
		CMaskedVarT<float, unsigned int> m_activateDuration;
		CMaskedVarT<float, unsigned int> m_effectStartDuration;
		CMaskedVarT<float, unsigned int> m_distance;
		CryStringT<char> m_hitType;
		float m_damage;
		int m_bulletType;
	};

	class CRestoreParams 
		: CBaseSettings::SClassRestrictionParams {
	public:
		CMaskedVarT<float, unsigned int> m_InitialDistance;
		CMaskedVarT<float, unsigned int> m_distance;
		float m_startRestoreDuration;
		float m_restoreDuration;
		float m_restoreCoopDuration;
		float m_restoreAmount;
		int m_hitTypeId;
		std::set<enum ECharacterClassId, std::less<enum ECharacterClassId>, std::allocator<enum ECharacterClassId> > m_class_restrictions;
	};

	class CRechargeParams {
	public:

		enum eChargeType {

			ChargeType_Kit = 0x0,
			ChargeType_Weapon = 0x1,
			ChargeType_Count = 0x2,
		};
	public:

		float m_rechargeDuration;
		bool m_canRecharge;
		int m_maxChargeLevel;
		int m_useCost;
		eChargeType m_chargeType;
		float m_lowLevelNotification;
		float m_rechargeDelay;
		eInteractType m_interactType;
	}; // enum CWeaponSettings::CRechargeParams::<unnamed_enum_DEFAULT_CHARGE_LEVEL> : __int32 { DEFAULT_CHARGE_LEVEL = 0x64, };

	struct CInteractionParams {

		int m_crosshairId;
		int m_crosshairType;
		CryStringT<char> m_message;
	};

public:
	//																				SEARCHING
	ACEID_API CREATE_FUNCTOR(CryStringT<char>, m_category, 0x490);
	ACEID_API CREATE_FUNCTOR(CryStringT<char>, m_netPolicy, 0x4A0);
	ACEID_API CREATE_FUNCTOR(bool, m_recoilResetDelay, 0x4B8);
	ACEID_API CREATE_FUNCTOR_STRUCT(CRecoilParams, m_recoilparams, 0x4C0);		    // String: remove_when_no_ammo
	ACEID_API CREATE_FUNCTOR_STRUCT(CSpreadParams, m_spreadparams, 0x4F8);			// String: recoil
	ACEID_API CREATE_FUNCTOR(CMeleeParams*, m_meleeparams, 0x510);					// String: melee_params
	ACEID_API CREATE_FUNCTOR(CMeleeParams*, m_secondaryMeleeparams, 0x518);			// String: melee_secondary_params
	ACEID_API CREATE_FUNCTOR(CClipParams*, m_clipParams, 0x520);					// String: clipmode
	ACEID_API CREATE_FUNCTOR(CRestoreParams*, m_restoreParams, 0x528);				// String: clipmode + 0x8
	ACEID_API CREATE_FUNCTOR(CResurrectParams*, m_resurrectParams, 0x530);			// String: resurrect_params
	ACEID_API CREATE_FUNCTOR(CDFDamageParams*, m_dfDamageParams, 0x538);			// String: resurrect_params
	ACEID_API CREATE_FUNCTOR(CAmmoPackParams*, m_ammoPackParams, 0x5C0); // -24
	ACEID_API CREATE_FUNCTOR(CRechargeParams*, m_rechargeParams, 0x5C8); // -16
	ACEID_API CREATE_FUNCTOR(CInteractionParams*, m_interaction, 0x5D0); // -8
	ACEID_API CREATE_FUNCTOR(bool, m_removeWhenNoAmmo, 0x5D8);						// String remove_when_ammo
	ACEID_API CREATE_FUNCTOR(bool, m_selectOnAmmoPickup, 0x5D9);
};

#endif // !CWEAPONSETTINGS_HPP

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

#ifndef EGAMESTATTYPE_HPP
#define EGAMESTATTYPE_HPP


enum EGameStatType {

	eGS_Absorption = 0x0,
	eGS_Accuracy = 0x1,
	eGS_ActivateDuration = 0x2,
	eGS_AimAccuracy = 0x3,
	eGS_AiSoundRadius = 0x4,
	eGS_AmmoAmount = 0x5,
	eGS_ArmorHealth = 0x6,
	eGS_ArmorRegenHps = 0x7,
	eGS_ArmorRegenTimeout = 0x8,
	eGS_ArmsDamageMult = 0x9,
	eGS_AutoZoomIn = 0x0A,
	eGS_AutoZoomOut = 0x0B,
	eGS_BallisticIronsight = 0x0C,
	eGS_BayonetMeleeDuration = 0x0D,
	eGS_BayonetMeleeOutDuration = 0x0E,
	eGS_BlindAmountMul = 0x0F,
	eGS_BodyDamageMult = 0x10,
	eGS_BoltAction = 0x11,
	eGS_BoltActionDuration = 0x12,
	eGS_BulletPierceability = 0x13,
	eGS_ClaymoreActivationDelayMul = 0x14,
	eGS_ClaymoreDetectorRadius = 0x15,
	eGS_ClipSize = 0x16,
	eGS_CrouchSpeedMul = 0x17,
	eGS_CustomizeInDuration = 0x18,
	eGS_CustomizeOutDuration = 0x19,
	eGS_Damage = 0x1A,
	eGS_DamageDropMinDistance = 0x1B,
	eGS_DamageDropPerMeter = 0x1C,
	eGS_DamageMin = 0x1D,
	eGS_DamageUnderbarrel = 0x1E,
	eGS_DeselectDuration = 0x1F,
	eGS_DeselectDurationBuff = 0x20,
	eGS_ExtraAmmoPistolMul = 0x21,
	eGS_ExtraAmmoPrimaryMul = 0x22,
	eGS_FireUnderbarrelDuration = 0x23,
	eGS_FireUnderbarrelOnRelease = 0x24,
	eGS_FlashbangTimeMul = 0x25,
	eGS_FovMul = 0x26,
	eGS_HeadDamageMult = 0x27,
	eGS_HealthMul = 0x28,
	eGS_HipAccuracy = 0x29,
	eGS_HolsterInDuration = 0x2A,
	eGS_HpRegenerationHps = 0x2B,
	eGS_HpRegenerationTimeout = 0x2C,
	eGS_IgnoreBulletBody = 0x2D,
	eGS_SuppressIgnoreBulletBody = 0x2E,
	eGS_IgnoreBulletHead = 0x2F,
	eGS_SuppressIgnoreBulletHead = 0x30,
	eGS_KnockBackChance = 0x31,
	eGS_KnockBackMinDistance = 0x32,
	eGS_KnockBackMaxDistance = 0x33,
	eGS_KnockBackResistance = 0x34,
	eGS_KnockBackStaminaDamage = 0x35,
	eGS_LegsDamageMult,

	eGS_Unknown0,
	eGS_Unknown1,

	eGS_MeleeDamage,
	eGS_MeleeDuration,
	eGS_MeleeDurationBuff,
	eGS_MeleeKnockBackChance,
	eGS_MeleeKnockBackStaminaDamage,
	eGS_CyborgDamageBuff,
	eGS_MeleeOutDuration,
	eGS_MeleeRadius,
	eGS_MeleeRange,
	eGS_MeleeRes,
	eGS_Range,

	eGS_RclAtt,
	eGS_RclDec,
	eGS_RclDecDelay,
	eGS_RclMax,
	eGS_RclRnd,
	eGS_RclSmth,
	eGS_ReloadDuration,
	eGS_ReloadDurationBuff,
	eGS_ReloadUnderbarrelDuration,
	eGS_ResArms,
	eGS_ResBody,
	eGS_ResHead,
	eGS_ResLegs,
	eGS_Resistance,
	eGS_Rpm,
	eGS_MoveSoundVolumeDamping,
	eGS_SecondaryMeleeDamage,
	eGS_SecondaryMeleeDuration,
	eGS_SecondaryMeleeDurationBuff,
	eGS_SecondaryMeleeOutDuration,
	eGS_SecondaryMeleeRadius,
	eGS_SecondaryMeleeRange,
	eGS_SelectDuration,
	eGS_SelectDurationBuff,
	eGS_SlideDistMul,
	eGS_SplashRes,

	eGS_SprdAtt,
	eGS_SprdDec,
	eGS_SprdDecDelay,
	eGS_SprdMax,
	eGS_SprdMin,

	eGS_SprintSpeedMul,
	eGS_SprintTimeMul,
	eGS_StaminaMul,
	eGS_SwayDec,
	eGS_SwayMinX,
	eGS_SwayMinY,
	eGS_SwaySpeedMult,
	eGS_ThrowDelayDuration,
	eGS_ThrowDuration,
	eGS_ThrowFireDelayDuration,
	eGS_TossDuration,
	eGS_ZoomFactor,
	eGS_ZoomInDuration,
	eGS_ZoomInDurationBuff,
	eGS_ZoomOutDuration,
	eGS_ZoomOutDurationBuff,
	eGS_ZoomedBoltActionDuration,
	eGS_PoisonGrenadeDamageMul,
	eGS_InSlotSelectDuration,
	eGS_InSlotDeselectDuration,
	eGS_UseInSlotWeaponChange,
	eGS_CameraShakeMul,
	eGS_SprdInverted,
	eGS_StrafeMultiplier,
	eGS_ClimbExtraHeight,
	eGS_ArmorAbsorbRatio,
	eGS_InvalidStat = -1 // 0x0FFFFFFFF
};

#endif // !EGAMESTATTYPE_HPP

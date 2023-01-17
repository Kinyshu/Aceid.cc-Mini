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

#ifndef SSPECIAMOVEMENTSTATE_HPP
#define SSPECIAMOVEMENTSTATE_HPP

#include "../enums/ESMType.hpp"
#include "../math/Vec3_tpl.hpp"
#include "../classes/CryStringT.hpp"

enum EUpdateMode {

	eUM_EXCLUSIVE = 0x0,
	eUM_MUTATOR = 0x1,
};

struct SSpecialMovementState {

	struct KnockBackHitInfo {
		float chance;
		float staminaDamage;
		CryStringT<char> hitType;
		Vec3_tpl<float> impactDir;
		unsigned int shooterId;
	};

	ESMType activeSM;
	EUpdateMode activeSMUpdateMode;
	ESMType prevSM;
	ESMType interruptedSM;
	bool useViewLimits;
	Vec3_tpl<float> viewLimitDir;
	float horzLimitAngle;
	float vertLimitAngleMin;
	float vertLimitAngleMax;
	bool useViewOffset;
	Vec3_tpl<float> viewOffset;
	bool useRoll;
	float rollAngle;
	bool useStance;
	EStance smStance;
	class CSafeCapsule* pSafeCapsule;
	bool interruptHaste;
	bool restartHaste;
	bool hasteAwaitingRestart;
	unsigned __int16 hasteInterruptFlags;
	float hasteCurTime;
	float hasteTimeMult;
	float hasteSpeedMult;
	float slideDistanceMult;
	float minStaminaToStartHaste;
	bool setFinalStance;
	Vec3_tpl<float> slideDir;
	float climbExtraHeight;
	CryStringT<char> interactionAction;
	float interactionTime;
	float interactionServerTime;
	unsigned int interactionTrigger;
	bool isInteractionActionActive;
	unsigned int holdEntity;
	CryStringT<char> holdEntityItemName;
	bool isHoldEntityAttached;
	CTimeValue LocalAnimStartTime;
	bool holsterOutAfterSMEnd;
	std::vector<KnockBackHitInfo> knockBackHits;
	float knockBackResistance;
	float knockBackStaminaDamage;
	unsigned int knockBackShooterId;
	bool knockBackFallingFinished;
	bool setRaiseAssistState;
	bool setStunned;
	bool isStunned;
	CryStringT<char> hitType;
	bool setAssistState;
	unsigned int setAssister;
	bool waitingInAssist;
	Vec3_tpl<float> coopExactDir;
	/*Lineseg_tpl<float>*/ char coopEdge[24];
	bool coopSingle;
	bool coopClimbFeedback;
	bool coopAssistFeedback;
	bool coopEnterAssistFeedback;
	bool interruptFeedback;
	bool raiseAssistFeedback;
	CTimeValue interruptTime;
	float coopScoreCoolDownTime;
	float raiseScoreCoolDownTime;
	Vec3_tpl<float> animStartPos;
	Vec3_tpl<float> helperClosestPoint;
	bool turnSpeedScale;
};

#endif // !SSPECIAMOVEMENTSTATE_HPP
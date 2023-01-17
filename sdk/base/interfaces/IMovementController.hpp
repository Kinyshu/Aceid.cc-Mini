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

#ifndef IMOVEMENTCONTROLLER_HPP
#define IMOVEMENTCONTROLLER_HPP

#include "../math/AABB.hpp"
#include "../math/Vec2_tpl.hpp"
#include "../math/Vec3_tpl.hpp"

#include "../enums/EStance.hpp"

struct SStanceState {

	Vec3_tpl<float> pos;
	Vec3_tpl<float> entityDirection;
	Vec3_tpl<float> animationBodyDirection;
	Vec3_tpl<float> upDirection;
	Vec3_tpl<float> weaponPosition;
	Vec3_tpl<float> aimDirection;
	Vec3_tpl<float> fireDirection;
	Vec3_tpl<float> eyePosition;
	Vec3_tpl<float> eyeDirection;
	AABB m_StanceSize;
	AABB m_ColliderSize;
};

struct SMovementState 
	: SStanceState {

	Vec3_tpl<float> fireTarget;
	EStance stance;
	Vec3_tpl<float> animationEyeDirection;
	Vec3_tpl<float> movementDirection;
	Vec3_tpl<float> lastMovementDirection;
	float desiredSpeed;
	float minSpeed;
	float normalSpeed;
	float maxSpeed;
	float slopeAngle;
	bool atMoveTarget;
	bool isAiming;
	bool isVisible;
};

interface IMovementController {

	virtual void DIMovementController();
	virtual bool RequestMovement(const class CMovementRequest* request);
	virtual void GetMovementState(SMovementState* state);
	virtual bool GetStanceState(const struct SStanceStateQuery* query, SStanceState* state);
	virtual Vec2_tpl<float>* GetDesiredMoveDir(Vec2_tpl<float>* result);
};

#endif // !IMOVEMENTCONTROLLER_HPP

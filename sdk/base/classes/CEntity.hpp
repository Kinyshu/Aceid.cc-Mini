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

#ifndef CENTITY_HPP
#define CENTITY_HPP

#include "../interfaces/IEntity.hpp"
#include "../math/Vec3_tpl.hpp"
#include "../math/QuatT_tpl.hpp"
#include "../math/Matrix34_tpl.hpp"

enum EEntityProxy {

	ENTITY_PROXY_RENDER,
	ENTITY_PROXY_PHYSICS,
	ENTITY_PROXY_SCRIPT,
	ENTITY_PROXY_SOUND,
	ENTITY_PROXY_AI,
	ENTITY_PROXY_AREA,
	ENTITY_PROXY_BOIDS,
	ENTITY_PROXY_BOID_OBJECT,
	ENTITY_PROXY_CAMERA,
	ENTITY_PROXY_FLOWGRAPH,
	ENTITY_PROXY_SUBSTITUTION,
	ENTITY_PROXY_TRIGGER,
	ENTITY_PROXY_ROPE,
	ENTITY_PROXY_ENTITYNODE,
	ENTITY_PROXY_USER,
	ENTITY_PROXY_LAST
};

class CRenderProxy {
public:

	void SetHUDSilhouettesParams(float r = 0.f, float g = 0.f, float b = 0.f, float a = 0.f) {

		this->flagLimit |= 0x80018;
		__vtbl< void, 44 >(this, r, g, b, a);
	}

	unsigned __int32 GetFlags() { return *(unsigned __int32*)((uintptr_t)this + 0xA0); }
	__int32 GetRenderFlags() { return *(unsigned __int32*)((uintptr_t)this + 0xA4); }

public:

	void ToggleSilhouettes(int r = 0, int g = 0, int b = 0, int a = 0) {
		this->SetHUDSilhouettesParams(static_cast<float>(r) / 255.f, static_cast<float>(g) / 255.f,
			static_cast<float>(b) / 255.f, static_cast<float>(a) / 255.f);
	}

private:
	char pad_0x0000[0x24]; //0x0000
	__int32 flagLimit; //0x0024 
	char pad_0x002C[0x70]; //0x002C
	__int32 flagAllMap; //0x009C 
};

class CSkeletonPose {
public:
	int GetJointIDByName(const char* name) { 
		return __vtbl< int, 3 >(this, name); 
	}

	QuatT_tpl<float> GetAbsJointByID(int nJointID) {
		return __vtbl< QuatT_tpl<float>&, 7 >(this, nJointID);
	}
};

class CCharInstance {
public:
	CSkeletonPose* GetSkeletonPose() { 
		return __vtbl< CSkeletonPose*, 5 >(this); 
	}
};

class CEntity
	: IEntity {
public:

	const Matrix34_tpl<float>& GetWorldTM() {
		return __vtbl< Matrix34_tpl<float>&, 23 >(this);
	}

	CRenderProxy* GetEntityRenderProxy(EEntityProxy proxy = EEntityProxy::ENTITY_PROXY_RENDER) {
		return __vtbl< CRenderProxy*, 59 >(this, proxy);
	}

	CCharInstance* GetCharacter(int nSlot) { 
		return __vtbl< CCharInstance*, 83 >(this, nSlot); 
	}

	ACEID_API CREATE_FUNCTOR(Vec3_tpl< float >, m_vPos, 0x70);
};

#endif // !CENTITY_HPP
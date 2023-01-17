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

#ifndef CRENDERER_HPP
#define CRENDERER_HPP

#include "../interfaces/IRenderer.hpp"
#include "../structures/SD3DPostEffectsUtils.hpp"

// Поиск конструктора: string: "CryRenderer", 4 xref
/*
	j_memset(v3, 0, 0x14DF00ui64);
	  if ( v3 )
		v4 = sub_140E18110((__int64)v3); xref-> first sub
*/
class CRenderer
	: IRenderer {
public:

public:

	bool WorldToScreen(Vec3_tpl< float > to, Vec3_tpl< float >& out) {

		SProjectToScreen m_pts = SProjectToScreen(to, out);
		this->ProjectToScreenInternal(&m_pts);

		if (out.x < 0.f || out.z > 1.f) {
			return false;
		}

		out.x *= 1920 / 100.f;
		out.y *= 1080 / 100.f;

		return true;
	}

	bool WorldToScreen2(Vec3_tpl< float >& world, Vec3_tpl< float >& screen) {
		auto Transform = [&world, &screen]() -> bool {

			auto matrix = SD3DPostEffectsUtils::GetInstance()->m_pProj;//SSystemGlobalEnvironment::GetInstance()->pRenderer->SetGetCamera(0, 0)->m_Matrix;
			screen.x = matrix.m00 * world.x + matrix.m01 * world.y + matrix.m02 * world.z + matrix.m03;
			screen.y = matrix.m10 * world.x + matrix.m11 * world.y + matrix.m12 * world.z + matrix.m13;
			screen.z = 0.0f;

			float w = matrix.m30 * world.x + matrix.m31 * world.y + matrix.m32 * world.z + matrix.m33;

			if (w < 0.001f) {
				screen.x *= 100000;
				screen.y *= 100000;
				return false;
			}

			screen.x /= w;
			screen.y /= w;

			return true;
		};

		if (Transform()) {

			int w = this->GetWidth(), h = this->GetHeight();

			screen.x = (w / 2.0f) + (screen.x * w) / 2.0f;
			screen.y = (h / 2.0f) - (screen.y * h) / 2.0f;

			return true;
		}

		return false;
	}


	ACEID_API CREATE_FUNCTOR(Vec3_tpl<float>, m_vCameraPos, 0x1740);
};

#endif // !CRENDERER_HPP
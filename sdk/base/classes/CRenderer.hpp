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
	bool WorldToScreen(Vec3_tpl< float > to, Vec3_tpl< float >& out) {

		SProjectToScreen m_pts = SProjectToScreen(to, out);
		this->ProjectToScreenInternal(&m_pts);

		if (out.x < 0.f || out.z > 1.f) {
			return false;
		}

		out.x *= this->GetWidth() / 100.f;
		out.y *= this->GetHeight() / 100.f;

		return true;
	}

	ACEID_API CREATE_FUNCTOR(IDXGISwapChain*, m_pSwapChain, 0x14CF00); // 44 8B C7 8B D6 48 8B 01 FF 50 40 80 BB ? ? ? ? ? 
};

#endif // !CRENDERER_HPP
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

#ifndef IRENDERER_HPP
#define IRENDERER_HPP

#include "../classes/CCamera.hpp"
#include "../math/Vec3_tpl.hpp"

interface IRenderer {

	struct SProjectToScreen {

		SProjectToScreen() { }
		SProjectToScreen(Vec3_tpl<float> to, Vec3_tpl<float>& out)
			: ptx(to.x), pty(to.y), ptz(to.z), sx(&out.x), sy(&out.y), sz(&out.z) { }

		float ptx;
		float pty;
		float ptz;
		float* sx;
		float* sy;
		float* sz;
	};

	CCamera* SetGetCamera(const CCamera* pCamera, bool bSet) {
		return __ivtbl< CCamera* >(this, data::SetGetCamera, pCamera, bSet);
	}

	int GetWidth() { 
		return __ivtbl< int >(this, data::GetWidth);
	}

	int GetHeight() {
		return __ivtbl< int >(this, data::GetHeight);
	}

	bool ProjectToScreenInternal(SProjectToScreen* proj) {
		return __vtbl< bool, 112 >(this, proj);
	}

};

#endif // !IRENDERER_HPP
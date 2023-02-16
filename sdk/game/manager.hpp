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

#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <chrono>
#include <time.h>
#include "rmi.hpp"

namespace manager {

	using Clock = std::chrono::steady_clock;
	std::chrono::time_point<std::chrono::steady_clock> start = Clock::now(), now;
	std::chrono::milliseconds duration;

	bool join(int ms) {

		while (true) {

			now = Clock::now();
			duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);

			if (duration.count() >= ms) {

				start = Clock::now();
				return true;
			}

			return false;
		}
	}

	bool GetTeam(CActor* source, CActor* target) {
		return source->m_teamId != target->m_teamId || source->m_teamId == 0;
	}

	bool buildRWITrajectory(Vec3_tpl<float> at, Vec3_tpl<float> to) {

		ray_hit m_hit;
		return !SSystemGlobalEnvironment::GetInstance()->pPhysicalWorld->RayWorldIntersection(to, at - to, 257, 1034, &m_hit, 1);
	}

	bool worldToScreen(Vec3_tpl<float> to, Vec3_tpl<float>& out) {

		IRenderer::SProjectToScreen pts(to, out);
		SSystemGlobalEnvironment::GetInstance()->pRenderer->ProjectToScreenInternal(&pts);

		if (out.x < 0.f || out.z > 1.f)
			return false;

		out.x *= SSystemGlobalEnvironment::GetInstance()->pRenderer->GetWidth() / 100.0f;
		out.y *= SSystemGlobalEnvironment::GetInstance()->pRenderer->GetHeight() / 100.0f;

		return true;
	}

	float calculateFov(Vec3_tpl<float> to) {

		Vec3_tpl<float> out;

		if (!worldToScreen(to, out))
			return 9999.9f;

		float cx = static_cast<float>(SSystemGlobalEnvironment::GetInstance()->pRenderer->GetWidth() / 2);
		float cy = static_cast<float>(SSystemGlobalEnvironment::GetInstance()->pRenderer->GetHeight() / 2);

		float px = out.x > cx ? out.x - cx : cx - out.x;
		float py = out.y > cy ? out.y - cy : cy - out.y;

		return static_cast<float>(sqrt(px * px + py * py));
	}
}

#endif // !MANAGER_HPP
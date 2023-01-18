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

#ifndef CTX_HPP
#define CTX_HPP

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <shlobj.h>
#include <experimental/filesystem>
#pragma comment(lib, "shell32.lib")

namespace ctx {

	bool ui, ui_buffer;
	bool gui_created;
	bool gui_scripts_created;

	bool gui_tabs[3] = { true };

	bool recoil;
	bool recoil_settings;

	float r_attack = 0.f;
	float r_decay = 0.f;
	float r_decay_delay = 0.f;
	float r_max = 0.f;
	float r_random = 0.f;
	float r_smooth = 0.f;

	bool spread;
	bool spread_settings;

	float s_attack = 0.f;
	float s_decay = 0.f;
	float s_decay_delay = 0.f;
	float s_max = 0.f;
	float s_min = 0.f;
	float s_inverted = 0.f;

	bool flashbang;
	bool sway;
	bool shutter;
	bool fastChange;

	bool damage;
	int damageMultiplier = 1;

	bool infiniteAmmo;

	bool aimbot;
	float fov = 22.5f;
	int bone;
	bool ignoreFov;
	bool drawFov;
	bool autoShoot;
	
	bool trigger;
	bool checkScope;
	float sleep;

	bool absoluteHeadshot;

	bool silhouettes;
	bool weapons;
	bool riggidBody;

	bool fp_fov;
	float fp_fov_value = 60.f;
}

#endif // !CTX_HPP

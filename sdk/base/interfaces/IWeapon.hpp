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

#ifndef IWEAPON_HPP
#define IWEAPON_HPP

interface IWeapon {

	void StartFire() {
	 __vtbl< void, 11 >(this);
	}

	void StopFire() {
		__vtbl< void, 12 >(this);
	}

	int GetCurrentFireMode() {
		return __vtbl< int, 30 >(this);
	}
};

#endif // !IWEAPON_HPP
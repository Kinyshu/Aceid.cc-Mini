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

#ifndef STDAFX_HPP
#define STDAFX_HPP

#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>

#include <iostream>
#include <d3d11.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
//#include "../web/web.hpp"

#define xorstr(s) s // SUPER IMPLEMENTATION OF XORSTR

#include "../includes/termcolor/termcolor.hpp"

#include "../ctx/ctx.hpp"
#include "../ctx/data.hpp" // offsets here

//#include "../includes/hooklib/HookLib.h"
#include "../sdk/sdk.hpp"

#include "../directx/hook/handler.hpp"
#include "../directx/hook/hook.hpp"

//#pragma comment(lib, "zydis.lib")
//#pragma comment(lib, "hooklib.lib")
#pragma comment(lib, "d3d11.lib")

#endif // !STDAFX_HPP
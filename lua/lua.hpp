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
*/
#pragma once

#ifndef LUA_HPP
#define LUA_HPP

#include <map>
#include <algorithm>

namespace lua {

	namespace str {

		bool contains(std::string script, std::string str) {
			return script.find(str) != std::string::npos;
		}

		std::string rtrim(std::string str, std::string find) {
			std::string buffer;
			std::string::size_type pos = str.find(find);
			if (pos != std::string::npos) { buffer = str.substr(pos); }
			return buffer;
		}

		std::string ltrim(std::string str, std::string find) {
			std::string buffer;
			std::string::size_type pos = str.find(find);
			for (auto it = 0; it != pos; it++) { buffer += str[it]; }
			return buffer;
		}

		std::string trim(std::string str, std::string first, std::string last) {
			std::string buffer = str;
			std::string::size_type fst = buffer.find(first);
			buffer = str.substr(fst);
			std::string::size_type lst = buffer.find(last) + 1;
			buffer = str.substr(fst, lst);
			return buffer;
		}

		std::string trim(std::string str, std::string first, std::string last, int offsetf, int offsets) {
			std::string buffer = str;
			std::string::size_type fst = buffer.find(first) + offsetf;
			buffer = str.substr(fst);
			std::string::size_type lst = buffer.find(last) + offsets;
			buffer = str.substr(fst, lst);
			return buffer;
		}

		std::vector < std::string > findAll(std::string& str, std::string first, std::string second) {
			std::string string = str;
			std::vector < std::string > vector;

			while (true) {

				auto first_symbol = string.find(first);
				auto second_symbol = string.find(second);
				if (second_symbol == 0 ||
					second_symbol == std::string::npos) {
					break;
				}

				auto t = trim(string, first, second);
				vector.push_back(t);
				string = string.substr(second_symbol + 1);
			}

			return vector;
		}
	}

	std::string FindCallback(std::string script, std::string first, std::string second) {
		return str::trim(script, first, second, 1, 0);
	}

	std::vector < std::string > findScripts(std::string& script) {
		auto code = str::rtrim(script, "Aceid");
		return str::findAll(code, "Aceid.", ")");
	}

	std::map< std::string, EFlowchartState > Functor;
	std::map< std::string, EFlowchartState > Callbacks =
	{
		{ "Lobby", eFS_Lobby },
		{ "LoadingLobby", eFS_LoadingLobby },
		{ "LoadingLevel", eFS_LoadingLevel },
		{ "Ingame", eFS_Ingame },
		{ "PostGame", eFS_PostGame }
	};

	class CLuaListener
		: public IGameFrameworkListener {
	public:
		void OnPreRender() {
			auto gEnv = SSystemGlobalEnvironment::GetInstance();
			auto pGame = reinterpret_cast<CGame*>(gEnv->pGame);

			auto m_currentState = pGame->m_pFlowchartManager->m_currentState;
			for (auto it : Functor) {
				if (it.second == m_currentState) {
					gEnv->pScriptSystem->ExecuteBuffer(it.first.c_str(), it.first.size());
				}
			}
		};
	};
}

#endif // !LUA_HPP
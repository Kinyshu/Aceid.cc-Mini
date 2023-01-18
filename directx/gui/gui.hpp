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

#ifndef GUI_HPP
#define GUI_HPP

#include "../managers/images.hpp"

namespace gui {

	char luaBuffer[8196];
	std::string luaCode;

	CImagesManager* pImgMgr;
	const char* bone[4] = { u8" Голова", u8" Шея", u8" Тело" };

	bool InBox(float x, float y, float w, float h) {
		return ImGui::GetMousePos().x >= x && ImGui::GetMousePos().x <= x + w
			&& ImGui::GetMousePos().y >= y && ImGui::GetMousePos().y <= y + h;
	}

	void DrawTab(ImVec2 position, ImVec2 size, std::string name, bool& variable) {

		ImColor color;
		if (InBox(position.x, position.y, size.x, size.y)) {
			if (ImGui::IsMouseClicked(0)) {

				for (auto i = 0; i != 3; i++) {
					ctx::gui_tabs[i] = 0;
				}

				variable = !variable;
			}

			color = ImColor(40, 40, 40);
		}
		else {
			color = ImColor(35, 35, 35);
		}

		if (variable) {
			color = ImColor(45, 45, 45);
		}

		ImGui::GetWindowDrawList()->AddRectFilled(CALC(position.x, position.y, size.x, size.y), color);
		ImGui::GetWindowDrawList()->AddImage(pImgMgr->get(name), CALC(position.x + (size.x / 2) - 15.f, position.y + (size.y / 2) - 15.f, 30.f, 30.f));
	}

	void Create(ID3D11Device* pDevice) {
		if (ctx::gui_created == false) {
			
			pImgMgr = new CImagesManager();
			pImgMgr->init(pDevice);

			ImGui::SetNextWindowPos({ 10.f, 10.f });
			ImGui::SetNextWindowSize({ 400.f, 550.f });

			ctx::gui_created = true;
		}
	}

	void CreateScripts() {
		if (ctx::gui_scripts_created == false) {

			ImGui::SetNextWindowSize({ 700.f, 370.f });
			ImGui::SetNextWindowPos({ 530.f, 15.f });

			ctx::gui_scripts_created = true;
		}
	}

	void Render() {

		auto w = 1920;
		auto h = 1080;

		if (SSystemGlobalEnvironment::GetInstance()->pRenderer) {
			w = SSystemGlobalEnvironment::GetInstance()->pRenderer->GetWidth();
			h = SSystemGlobalEnvironment::GetInstance()->pRenderer->GetWidth();
		}

		ImGui::Begin(xorstr("##Main"), 0, ImGuiWindowFlags_NoTitleBar |
			ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings |
			ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);
		{

			ImVec2 position = ImGui::GetWindowPos();

			ImGui::GetWindowDrawList()->AddRectFilled(CALC(position.x, position.y, 400.f, 45.f), ImColor(35, 35, 35));
			ImGui::GetWindowDrawList()->AddRectFilled(CALC(position.x, position.y + 45.f, 400.f, 505.f), ImColor(25, 25, 25), 12.f,
				ImDrawFlags_::ImDrawFlags_RoundCornersBottomLeft | ImDrawFlags_::ImDrawFlags_RoundCornersBottomRight);

			ImGui::GetWindowDrawList()->AddImage(pImgMgr->get("LOGO"), CALC(position.x + 35.f, position.y + 6.f, 180.f, 30.f));

			DrawTab(ImVec2(position.x + 250.f, position.y), ImVec2(50.f, 45.f), "WEAPONS", ctx::gui_tabs[0]);
			DrawTab(ImVec2(position.x + 300.f, position.y), ImVec2(50.f, 45.f), "AIMING", ctx::gui_tabs[1]);
			DrawTab(ImVec2(position.x + 350.f, position.y), ImVec2(50.f, 45.f), "VISUALS", ctx::gui_tabs[2]);

			ImVec2 size = ImGui::GetWindowSize();
			ImGui::GetWindowDrawList()->AddImage(pImgMgr->get("BG_LOGO"), CALC(position.x + size.x / 2 - 100.f, position.y + size.y / 2 - 100.f, 200.f, 200.f),
				ImVec2(0,0), ImVec2(1, 1), ImColor(255, 255,255, 55));

			ImGui::SetCursorPos({ 15.f, 60.f });
			ImGui::BeginChild("##MainChild", { 370.f, 470.f });
			{
			
				if (ctx::gui_tabs[0] == true) { /* Weapons */

					ImGui::Checkbox(xorstr(u8"Отдача"), &ctx::recoil);
					if (ctx::recoil) {
						ImGui::Checkbox(xorstr(u8"Настроить отдачу"), &ctx::recoil_settings);
						if (ctx::recoil_settings) {

							ImGui::SetCursorPosX(15.f);
							ImGui::Text(xorstr(u8"Attack:"));
							ImGui::SetCursorPosX(15.f);
							ImGui::SetNextItemWidth(340.f);
							ImGui::SliderFloat(xorstr(u8"##R_ATTACK"), &ctx::r_attack, 0.f, 100.f);

							ImGui::SetCursorPosX(15.f);
							ImGui::Text(xorstr(u8"Decay:"));
							ImGui::SetCursorPosX(15.f);
							ImGui::SetNextItemWidth(340.f);
							ImGui::SliderFloat(xorstr(u8"##R_DECAY"), &ctx::r_decay, 0.f, 100.f);

							ImGui::SetCursorPosX(15.f);
							ImGui::Text(xorstr(u8"Decay delay:"));
							ImGui::SetCursorPosX(15.f);
							ImGui::SetNextItemWidth(340.f);
							ImGui::SliderFloat(xorstr(u8"##R_DECAY_DELAY"), &ctx::r_decay_delay, 0.f, 100.f);

							ImGui::SetCursorPosX(15.f);
							ImGui::Text(xorstr(u8"Max:"));
							ImGui::SetCursorPosX(15.f);
							ImGui::SetNextItemWidth(340.f);
							ImGui::SliderFloat(xorstr(u8"##R_MAX"), &ctx::r_max, 0.f, 100.f);

							ImGui::SetCursorPosX(15.f);
							ImGui::Text(xorstr(u8"Random:"));
							ImGui::SetCursorPosX(15.f);
							ImGui::SetNextItemWidth(340.f);
							ImGui::SliderFloat(xorstr(u8"##R_RANDOM"), &ctx::r_random, 0.f, 100.f);

							ImGui::SetCursorPosX(15.f);
							ImGui::Text(xorstr(u8"Smooth:"));
							ImGui::SetCursorPosX(15.f);
							ImGui::SetNextItemWidth(340.f);
							ImGui::SliderFloat(xorstr(u8"##R_SMOOTH"), &ctx::r_smooth, 0.f, 100.f);

							ImGui::Separator();
						}
						ImGui::Separator();
					}
					ImGui::Checkbox(xorstr(u8"Разброс"), &ctx::spread);
					if (ctx::spread) {
						ImGui::Checkbox(xorstr(u8"Настроить разброс"), &ctx::spread_settings);
						if (ctx::spread_settings) {

							ImGui::SetCursorPosX(15.f);
							ImGui::Text(xorstr(u8"Attack:"));
							ImGui::SetCursorPosX(15.f);
							ImGui::SetNextItemWidth(340.f);
							ImGui::SliderFloat(xorstr(u8"##S_ATTACK"), &ctx::s_attack, 0.f, 100.f);

							ImGui::SetCursorPosX(15.f);
							ImGui::Text(xorstr(u8"Decay:"));
							ImGui::SetCursorPosX(15.f);
							ImGui::SetNextItemWidth(340.f);
							ImGui::SliderFloat(xorstr(u8"##S_DECAY"), &ctx::s_decay, 0.f, 100.f);

							ImGui::SetCursorPosX(15.f);
							ImGui::Text(xorstr(u8"Decay delay:"));
							ImGui::SetCursorPosX(15.f);
							ImGui::SetNextItemWidth(340.f);
							ImGui::SliderFloat(xorstr(u8"##S_DECAY_DELAY"), &ctx::s_decay_delay, 0.f, 100.f);

							ImGui::SetCursorPosX(15.f);
							ImGui::Text(xorstr(u8"Max:"));
							ImGui::SetCursorPosX(15.f);
							ImGui::SetNextItemWidth(340.f);
							ImGui::SliderFloat(xorstr(u8"##S_MAX"), &ctx::s_max, 0.f, 100.f);

							ImGui::SetCursorPosX(15.f);
							ImGui::Text(xorstr(u8"Random:"));
							ImGui::SetCursorPosX(15.f);
							ImGui::SetNextItemWidth(340.f);
							ImGui::SliderFloat(xorstr(u8"##S_MIN"), &ctx::s_min, 0.f, 100.f);

							ImGui::SetCursorPosX(15.f);
							ImGui::Text(xorstr(u8"Smooth:"));
							ImGui::SetCursorPosX(15.f);
							ImGui::SetNextItemWidth(340.f);
							ImGui::SliderFloat(xorstr(u8"##S_INVERTED"), &ctx::s_inverted, 0.f, 100.f);

							ImGui::Separator();
						}
						ImGui::Separator();
					}

					ImGui::Checkbox(xorstr(u8"Отключить увод"), &ctx::sway);
					ImGui::Checkbox(xorstr(u8"Отключить затвор"), &ctx::shutter);
					ImGui::Checkbox(xorstr(u8"Быстрая смена оружия"), &ctx::fastChange);
				}

				if (ctx::gui_tabs[1] == true) { /* Aiming */
					ImGui::Checkbox(xorstr(u8"Настроить аимбот"), &ctx::aimbot);
					if (ctx::aimbot) {

						ImGui::SetCursorPosX(15.f);
						ImGui::Text(xorstr(u8"Кость:"));

						ImGui::SetCursorPosX(15.f);
						ImGui::SetNextItemWidth(340.f);
						ImGui::ListBox(xorstr(u8""), &ctx::bone, bone, 3);

						ImGui::SetCursorPosX(15.f);
						ImGui::Checkbox(xorstr(u8"Рисовать FOV"), &ctx::drawFov);

						ImGui::SetCursorPosX(15.f);
						ImGui::Checkbox(xorstr(u8"Игнорировать FOV"), &ctx::ignoreFov);

						ImGui::SetCursorPosX(15.f);
						ImGui::Text(xorstr(u8"FOV наводки:"));

						ImGui::SetCursorPosX(15.f);
						ImGui::SetNextItemWidth(340.f);
						ImGui::SliderFloat(xorstr(u8"##AIMBOT"), &ctx::fov, 0.f, 360.f);

						ImGui::SetCursorPosX(15.f);
						ImGui::Checkbox(xorstr(u8"Автоматический выстрел"), &ctx::autoShoot);

						ImGui::Separator();
					}
					ImGui::Checkbox(xorstr(u8"Настроить триггер-бот"), &ctx::trigger);
					if (ctx::trigger) {

						ImGui::SetCursorPosX(15.f);
						ImGui::Checkbox(xorstr(u8"Проверять прицел"), &ctx::checkScope);

						ImGui::SetCursorPosX(15.f);
						ImGui::Text(xorstr(u8"Задержка перед выстрелом:"));

						ImGui::SetCursorPosX(15.f);
						ImGui::SetNextItemWidth(340.f);
						ImGui::SliderFloat(xorstr(u8"##TRIGGER"), &ctx::sleep, 0.f, 600.f);

						ImGui::Separator();
					}
				}

				if (ctx::gui_tabs[2] == true) { /* Visuals */
					ImGui::Checkbox(xorstr(u8"Силуэты"), &ctx::silhouettes);
					ImGui::Checkbox(xorstr(u8"Отключить эффект световой гранаты"), &ctx::flashbang);
					ImGui::Checkbox(xorstr(u8"Настроить FOV от первого лица"), &ctx::fp_fov);
					if (ctx::fp_fov) {

						ImGui::SetCursorPosX(15.f);
						ImGui::Text(xorstr(u8"Значение FOV:"));
						ImGui::SetCursorPosX(15.f);
						ImGui::SetNextItemWidth(340.f);
						ImGui::SliderFloat(xorstr(u8"##FOV"), &ctx::fp_fov_value, 60.f, 120.f);
						ImGui::Separator();
					}
				}
			}
			ImGui::EndChild();
		}
		ImGui::End();

		CreateScripts();

		ImGui::Begin("##Scripts", 0, ImGuiWindowFlags_NoTitleBar |
			ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings |
			ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground);
		{
			ImVec2 position = ImGui::GetWindowPos();

			ImGui::GetWindowDrawList()->AddRectFilled(CALC(position.x, position.y, 700.f, 45.f), ImColor(35, 35, 35));
			ImGui::GetWindowDrawList()->AddRectFilled(CALC(position.x, position.y + 45.f, 700.f, 370.f), ImColor(25, 25, 25), 12.f,
				ImDrawFlags_::ImDrawFlags_RoundCornersBottomLeft | ImDrawFlags_::ImDrawFlags_RoundCornersBottomRight);

			ImGui::GetWindowDrawList()->AddImage(pImgMgr->get("LOGO_SCRIPTS"), CALC(position.x + 35.f, position.y + 6.f, 185.f, 35.f));

			ImGui::SetCursorPos({ 15.f, 60.f });
			ImGui::BeginChild("##ScriptsChild", { 670.f, 310.f });
			{
				ImGui::Text(u8"Информацию про LUA скриптинг вы можете найти на https://aceid.cc/lua");
				ImGui::InputTextMultiline("##Script", luaBuffer, 8196, { 660.f, 240.f }, ImGuiInputTextFlags_::ImGuiInputTextFlags_AllowTabInput);
				if (ImGui::Button(u8"Выполнить скрипт", { 200.f, 30.f })) {
					luaCode = luaBuffer;
					if (luaCode.empty() == false) {

						SSystemGlobalEnvironment::GetInstance()
							->pScriptSystem
							->ExecuteBuffer(luaCode.c_str(), luaCode.size());
					}
				}
			}
			ImGui::EndChild();
		}
		ImGui::End();

		ImGui::GetBackgroundDrawList()->AddText({ 10.f, 15.f }, ImColor(255, 255, 255), std::string("ID: " + usermgr::user_id + "\nNAME: " + usermgr::username + "\n").c_str());
	}
}

#endif // !GUI_HPP
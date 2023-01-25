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

#ifndef VISUALS_HPP
#define VISUALS_HPP

class CVisualListener :
	public IGameFrameworkListener {
public:

	void OnPreRender() {

		auto gEnv = SSystemGlobalEnvironment::GetInstance();
		{
			if (ctx::ui && !ctx::ui_buffer) {
				gEnv->pConsole->ShowConsole(true, 1);
				ctx::ui_buffer = true;
			}
			else if (!ctx::ui && ctx::ui_buffer) {
				gEnv->pConsole->ShowConsole(false, 0);
				ctx::ui_buffer = false;
			}
		}

		if (gEnv->pScriptSystem) {
			if (ctx::luaExecution) {
				if (ctx::luaCode.empty() == false) {
					SSystemGlobalEnvironment::GetInstance()
						->pScriptSystem
						->ExecuteBuffer(ctx::luaCode.c_str(), ctx::luaCode.size());
				}
				ctx::luaExecution = false;
			}
		}

		auto pGame = gEnv->pGame;
		if (!pGame) {
			return;
		}

		auto pFramework = pGame->GetIGameFramework();
		if (!pFramework) {
			return;
		}

		if (ctx::flashbang) {
			gEnv->p3DEngine->SetPostEffectParam(xorstr("Flashbang_Active"), 0.f, true);
		}

		if (ctx::fp_fov) {
			reinterpret_cast<CGame*>(gEnv->pGame)->m_pCVars->cl_fov = ctx::fp_fov_value;
		}

		reinterpret_cast<CGame*>(gEnv->pGame)->m_pCVars->g_ingame_afk_timeout = 86300;
		reinterpret_cast<CGame*>(gEnv->pGame)->m_pCVars->g_gameroom_afk_timeout = 86580;

		IActor* pPlayer = nullptr;
		if (pFramework->GetClientActorInternal(&pPlayer) == false) {
			return;
		}

		if (!pFramework->GetIActorSystem()) {
			return;
		}

		auto pItemProxy = pPlayer->GetCurrentItem();

		auto m_actors = pFramework->GetIActorSystem()->m_actors;
		if (m_actors.empty() == true) {
			return;
		}

		for (auto it : m_actors) {

			if (!it.second) {
				continue;
			}

			auto pActor = it.second;
			if (pActor) {

				if (pActor != reinterpret_cast<CActor*>(pPlayer)) {

					if (manager::GetTeam(reinterpret_cast<CActor*>(pPlayer), pActor)) {

						auto proxy = reinterpret_cast<CEntity*>(reinterpret_cast<IActor*>(pActor)->m_pEntity)->GetEntityRenderProxy();
						if (proxy) {
							if (ctx::silhouettes) {

								Vec3_tpl<float> position, m_position;

								position = pActor->GetBonePositionByName("Bip01 Head");
								m_position = gEnv->pRenderer->SetGetCamera(0, false)->m_Matrix.GetTranslation();

								if (manager::buildRWITrajectory(m_position, position)) {
									proxy->ToggleSilhouettes(0, 255, 0, 0);
								}
								else {
									proxy->ToggleSilhouettes(255, 0, 0, 0);
								}

								if (reinterpret_cast<IActor*>(pActor)->IsDead()) {
									proxy->ToggleSilhouettes(255, 255, 0, 0);
								}
							}
						}
					}
				}
			}
		}
	}
};

#endif // !VISUALS_HPP
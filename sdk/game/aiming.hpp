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

#ifndef AIMING_HPP
#define AIMING_HPP


class CAimingListener :
	public IGameFrameworkListener {
public:

	void OnPreRender() {

		auto gEnv = SSystemGlobalEnvironment::GetInstance();
		auto pGame = gEnv->pGame;
		if (!pGame) {
			return;
		}

		auto pFramework = pGame->GetIGameFramework();
		if (!pFramework) {
			return;
		}

		IActor* pPlayer = nullptr;
		if (pFramework->GetClientActorInternal(&pPlayer) == false) {
			return;
		}

		if (pPlayer == nullptr) {
			return;
		}

		if (pPlayer->IsDead() == true) {
			return;
		}

		auto pItemProxy = pPlayer->GetCurrentItem();
		if (pItemProxy == nullptr) {
			return;
		}

		auto m_weaponExt = reinterpret_cast<CItemProxy*>(pItemProxy)->m_weaponExt;
		if (m_weaponExt == nullptr) {
			return;
		}

		auto pSettings = reinterpret_cast<IWeaponGeneral*>(m_weaponExt)->GetSettings();
		if (pSettings == nullptr) {
			return;
		}

		// Не обновлено. Проверка на основное и дополнительное оружие.
		// if (pSettings->m_fireparams->ammo_type_class == nullptr) {
		// 	 return;
		// }

		// if (!strstr(pSettings->m_fireparams->ammo_type_class->GetName(), ("bullet"))
		// 	 || strstr(pSettings->m_fireparams->ammo_type_class->GetName(), ("bullet_arl")))
		// 	 return;

		if (!pFramework->GetIActorSystem()) {
			return;
		}

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

						if (ctx::aimbot) {

							if (reinterpret_cast<IActor*>(pActor)->IsDead()) {
								continue;
							}

							if (strstr(reinterpret_cast<IActor*>(pActor)->m_pEntity->GetName(), xorstr("Turret"))) {
								continue;
							}

							static std::string target;

							int identifier, m_identifier;
							Vec3_tpl<float> position, m_position;

							if (ctx::bone == 0) {
								target = "Bip01 Head";
							}
							else if (ctx::bone == 1) {
								target = "Bip01 Neck";
							}
							else if (ctx::bone == 2) {
								target = "Bip01 Spine";
							}

							position = pActor->GetBonePositionByName(target);
							m_position = gEnv->pRenderer->SetGetCamera(nullptr, false)->m_Matrix.GetTranslation();

							if (manager::buildRWITrajectory(m_position, position)) {

								if (manager::calculateFov(position) <= ctx::fov || ctx::ignoreFov) {

									reinterpret_cast<CItemProxy::CItemBox*>(reinterpret_cast<IWeaponGeneral*>(reinterpret_cast<CItemProxy*>(pItemProxy)->m_weaponExt)->GetItemBox())->m_fireTarget = position;
									if (ctx::autoShoot) {
										pItemProxy->GetIWeapon()->StartFire();
										pItemProxy->GetIWeapon()->StopFire();
									}
								}
							}
						}
					}
				}
			}
		}
	}
};

#endif // !AIMING_HPP
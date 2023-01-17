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

#ifndef WEAPON_HPP
#define WEAPON_HPP


class CWeaponListener :
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

		reinterpret_cast<CItemProxy::CItemBox*>(reinterpret_cast<IWeaponGeneral*>(m_weaponExt)->GetItemBox())->m_fireTarget = Vec3_tpl<float>(0, 0, 0);

		auto pSettings = reinterpret_cast<IWeaponGeneral*>(m_weaponExt)->GetSettings();
		if (pSettings == nullptr) {
			return;
		}

		if (pSettings->m_fireparams->ammo_type_class == nullptr) {
			return;
		}

		auto pParameters = reinterpret_cast<IWeaponGeneral*>(m_weaponExt)->GetParameters();
		if (pParameters == nullptr) {
			return;
		}

		if (ctx::recoil) {
			pParameters->m_stats.SetValue(EGameStatType::eGS_RclAtt, ctx::r_attack);
			pParameters->m_stats.SetValue(EGameStatType::eGS_RclDec, ctx::r_decay);
			pParameters->m_stats.SetValue(EGameStatType::eGS_RclDecDelay, ctx::r_decay_delay);
			pParameters->m_stats.SetValue(EGameStatType::eGS_RclMax, ctx::r_max);
			pParameters->m_stats.SetValue(EGameStatType::eGS_RclRnd, ctx::r_random);
			pParameters->m_stats.SetValue(EGameStatType::eGS_RclSmth, ctx::r_smooth);
		}

		if (ctx::spread) {
			pParameters->m_stats.SetValue(EGameStatType::eGS_SprdAtt, ctx::s_attack);
			pParameters->m_stats.SetValue(EGameStatType::eGS_SprdDec, ctx::s_decay);
			pParameters->m_stats.SetValue(EGameStatType::eGS_SprdDecDelay, ctx::s_decay_delay);
			pParameters->m_stats.SetValue(EGameStatType::eGS_SprdMax, ctx::s_max);
			pParameters->m_stats.SetValue(EGameStatType::eGS_SprdMin, ctx::s_min);
			pParameters->m_stats.SetValue(EGameStatType::eGS_SprdInverted, ctx::s_inverted);
		}

		if (ctx::sway) {
			pParameters->m_swayCurr = { 0.f, 0.f };
		}

		if (ctx::shutter) {
			pParameters->m_stats.SetValue(EGameStatType::eGS_BoltAction, 0.f);
			pParameters->m_stats.SetValue(EGameStatType::eGS_BoltActionDuration, 0.f);
			pParameters->m_stats.SetValue(EGameStatType::eGS_ZoomedBoltActionDuration, 0.f);
		}

		if (ctx::fastChange) {
			pParameters->m_stats.SetValue(EGameStatType::eGS_SelectDuration, 0.f);
			pParameters->m_stats.SetValue(EGameStatType::eGS_SelectDurationBuff, 0.f);
			pParameters->m_stats.SetValue(EGameStatType::eGS_DeselectDuration, 0.f);
			pParameters->m_stats.SetValue(EGameStatType::eGS_DeselectDurationBuff, 0.f);
			pParameters->m_stats.SetValue(EGameStatType::eGS_InSlotSelectDuration, 0.f);
			pParameters->m_stats.SetValue(EGameStatType::eGS_InSlotDeselectDuration, 0.f);
		}

		if (ctx::trigger) {
			auto pWorldQuery = reinterpret_cast<CGameObject*>(pPlayer->m_pGameObject)->GetWorldQuery();
			if (pWorldQuery) {

				auto m_lookAtEntityId = pWorldQuery->m_lookAtEntityId;
				if (m_lookAtEntityId == 0) {
					return;
				}

				if (auto pActor = pFramework->GetIActorSystem()->GetActor(m_lookAtEntityId)) {

					if (pActor == nullptr) {
						return;
					}

					if (!manager::GetTeam(reinterpret_cast<CActor*>(pPlayer), pActor)) {
						return;
					}

					if (ctx::checkScope && reinterpret_cast<IWeaponGeneral*>(m_weaponExt)->GetCurrState() == IWeaponGeneral::EWeaponStates::eWS_IdleZoomed
						|| !ctx::checkScope) {

						if (manager::join(ctx::sleep)) {
							pItemProxy->GetIWeapon()->StartFire();
							pItemProxy->GetIWeapon()->StopFire();
						}
					}
				}
			}
		}
	}
};

#endif // !WEAPON_HPP
#pragma once

#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include "../../vmt/vmt.hpp"

class CActionsListener
	: public IGameFrameworkListener {
public:

	void OnPreRender() {

		auto gEnv = SSystemGlobalEnvironment::GetInstance();
		auto pGame = reinterpret_cast<CGame*>(gEnv->pGame);

		auto m_pFlowchartManager = pGame->m_pFlowchartManager;
		if (m_pFlowchartManager) {

			switch (m_pFlowchartManager->m_currentState) {
			case EFlowchartState::eFS_Ingame:			
				if (this->HookUpdated == false) {

					pDispatchRMI = nullptr;
					pDispatchRMI = new CVMTHandler(reinterpret_cast<std::uintptr_t**>(gEnv->pGame->GetIGameFramework()->GetClientChannel()));
					DispatchRMI_Original = pDispatchRMI->hook(21, DispatchRMI_Hook);

					this->HookUpdated = true;
				}
				break;

			case EFlowchartState::eFS_LoadingLobby:			
				this->HookUpdated = false;
				break;
			}
		}
		
		if (this->HookInitialized == false) {
			auto gEnv = SSystemGlobalEnvironment::GetInstance();
			auto pGame = reinterpret_cast<CGame*>(gEnv->pGame);

			pDispatchRMI = new CVMTHandler(reinterpret_cast<std::uintptr_t**>(gEnv->pGame->GetIGameFramework()->GetClientChannel()));
			DispatchRMI_Original = pDispatchRMI->hook(21, DispatchRMI_Hook);

			auto RayWorldIntersection_Pointer = new CVMTHandler(reinterpret_cast<std::uintptr_t**>(gEnv->pPhysicalWorld));
			RayWorldIntersection_Original = RayWorldIntersection_Pointer->hook(34, RayWorldIntersection_Hook);

			this->HookInitialized = true;
		}
	}

	void OnActionEvent(const SActionEvent& event) { }

private:
	bool HookUpdated = false;
	bool HookInitialized = false;

	CVMTHandler* pDispatchRMI = nullptr;
};

#endif // !ACTIONS_HPP
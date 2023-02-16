#pragma once

#ifndef ACTIONS_HPP
#define ACTIONS_HPP

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

					unhook(DispatchRMI_Original);

					std::uintptr_t* NetChannel = nullptr;
					NetChannel = reinterpret_cast<std::uintptr_t*>(gEnv->pGame->GetIGameFramework()->GetClientChannel());
					NetChannel = reinterpret_cast<std::uintptr_t*>(NetChannel[0]);

					DispatchRMI_Original = CreateHook< DispatchRMI_Using >(reinterpret_cast<void*>(NetChannel[21]), DispatchRMI_Hook);

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

			std::uintptr_t* NetChannel = nullptr;
			NetChannel = reinterpret_cast<std::uintptr_t*>(gEnv->pGame->GetIGameFramework()->GetClientChannel());
			NetChannel = reinterpret_cast<std::uintptr_t*>(NetChannel[0]);

			DispatchRMI_Original = CreateHook< DispatchRMI_Using >(reinterpret_cast<void*>(NetChannel[21]), DispatchRMI_Hook);

			this->HookInitialized = true;
		}
	}

	void OnActionEvent(const SActionEvent& event) { }

private:
	bool HookUpdated = false;
	bool HookInitialized = false;
};

#endif // !ACTIONS_HPP
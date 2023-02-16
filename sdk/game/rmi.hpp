#pragma once

#ifndef RMI_HPP
#define RMI_HPP

struct SClientGameHitInfoEx {

    SClientGameHitInfoEx() { }
    SClientGameHitInfoEx(EntityId targetId, int material, int type, int partId, Vec3_tpl<float> pos, float damageReduction, CActor* m_pActor)
        : targetId(targetId), material(material), type(type), partId(partId), pos(pos), damageReduction(damageReduction) {
        physCounter = m_pActor ? *(unsigned __int8*)(reinterpret_cast<std::uintptr_t>(m_pActor) + 0xce4) : 0;
    }

    EntityId targetId;
    int material;
    int type;
    int partId;
    Vec3_tpl<float> pos;
    float damageReduction;
    unsigned __int8 physCounter;
};

struct SClientGameProjectilesInfo {

    SClientGameProjectilesInfo(EntityId projectileId, std::vector< SClientGameHitInfoEx > hitInfos)
        : projectileId(projectileId), hitInfos(hitInfos) {}

    EntityId projectileId;
    std::vector< SClientGameHitInfoEx > hitInfos;
};

struct SClientGameMultiHitInfo {

    Vec3_tpl<float> shootPosition;
    int predictionHandle;
    Vec3_tpl<float> velocity;
    unsigned __int8 physCounter;
    std::vector< SClientGameProjectilesInfo > projectiles;
    unsigned __int8 fireCounter;
    float spreadMax;
    bool b;
    CTimeValue previousTime;
    CTimeValue nextTime;
    unsigned int ui;
    int ammoCount;
    Vec3_tpl<float> direction;
};

ACEID_API CREATE_STATIC_HOOK(void, DispatchRMI,
    WITH_ARGUMENTS
    (
        class CNetChannel* pNetChannel,
        IGameObject::CRMIBodyImpl< SClientGameMultiHitInfo >** pBody
    )
) {

    auto Message = (*pBody);
    if (Message != nullptr) {
        auto pMessageDef = Message->pMessageDef;
        if (pMessageDef != nullptr) {
               
            if (pMessageDef->description == std::string("RMI:CItemProxy:SvRequestShootHit")) {

                auto gEnv = SSystemGlobalEnvironment::GetInstance();
                if (gEnv == nullptr) {
                    return DispatchRMI_Original(pNetChannel, pBody);
                }

                IActor* pPlayer = nullptr;
                if (gEnv->pGame->GetIGameFramework()->GetClientActorInternal(&pPlayer) == false) {
                    return DispatchRMI_Original(pNetChannel, pBody);
                }

                IItemProxy* m_pItemProxy = pPlayer->GetCurrentItem();
                if (m_pItemProxy == nullptr) {
                    return DispatchRMI_Original(pNetChannel, pBody);
                }

                if (ctx::wallshot) {
                    if (!strstr(m_pItemProxy->m_pEntity->GetName(), "kn")) {
                        if (Message->m_params.projectiles.empty() == false) {

                            for (auto it = Message->m_params.projectiles.begin();
                                it != Message->m_params.projectiles.end(); it++) {

                                if (it->hitInfos.empty() == false) {
                                    auto begin = it->hitInfos.begin();
                                    it->hitInfos.insert(begin, SClientGameHitInfoEx(pPlayer->m_entityId, 1, 6, 13,
                                        gEnv->pRenderer->SetGetCamera(0, 0)->m_Matrix.GetTranslation(), -1.f, reinterpret_cast<CActor*>(pPlayer)));
                                }
                                else {
                                    it->hitInfos.push_back(SClientGameHitInfoEx(pPlayer->m_entityId, 1, 6, 13,
                                        gEnv->pRenderer->SetGetCamera(0, 0)->m_Matrix.GetTranslation(), -1.f, reinterpret_cast<CActor*>(pPlayer)));
                                }
                            }
                        }
                    }
                }
            }
        }

    }

    return DispatchRMI_Original(pNetChannel, pBody);
}

ACEID_API CREATE_STATIC_HOOK(int, RayWorldIntersection,
    WITH_ARGUMENTS
    (
        IPhysicalWorld* pPhysicalWorld,
        IPhysicalWorld::SRWIParams& rp,
        const char* pNameTag,
        int iCaller
    )
) {

    if (ctx::wallshot) {
        rp.objtypes = 0x10;
    }

    return RayWorldIntersection_Original(pPhysicalWorld, rp, pNameTag, iCaller);
}
#endif // !RMI_HPP
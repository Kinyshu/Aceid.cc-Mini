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

#ifndef CITEMPROXY_HPP
#define CITEMPROXY_HPP

#include "../interfaces/IItemView.hpp"
#include "../interfaces/IItemBox.hpp"
#include "../interfaces/IItemEdit.hpp"
#include "../interfaces/IFireMode.hpp"
#include "../interfaces/IItemProxy.hpp"

#include "CWeaponGeneral.hpp"
#include "CGameObjectExtensionHelper.hpp"

class CItemProxy
	: CGameObjectExtensionHelper<CItemProxy, IItemProxy, 64>, IWeapon {
public:

	class CItemBox 
		: IItemBox, IItemEdit {
	public:
		//CItemProxy* m_pItem;
		//unsigned int m_ownerId;
		//Vec3_tpl<float> m_fireTarget; // 20
		//class CEntityRender* m_render;

		ACEID_API CREATE_FUNCTOR(Vec3_tpl<float>, m_fireTarget, 0x20);
	};

	struct CMountableItemBox 
		: public CItemBox {

		bool m_used;
		unsigned int m_hostId;
		Vec3_tpl<float> m_mountDir;
		float m_minPitch;
		float m_maxPitch;
		float m_yawRange;
	};


	class CItemView 
		: IItemView {

		struct SGeometry {
			CryStringT<char> name;
			Vec3_tpl<float> position;
			Vec3_tpl<float> angles; // Ang3
			float scale;
		};

		struct SAnimation {

			CryStringT<char> name;
			CryStringT<char> camera_helper;
			float speed;
			float blend;
			bool camera_pos;
			bool camera_rot;
			bool camera_follow;
			bool camera_reorient;
		};

		struct SAction {

			std::vector<SAnimation, std::allocator<SAnimation>> animation[9];
			bool children;
			int duration;
		};

		CItemProxy* m_pItem;
	};

	class CAIFireModeProxy 
		: IFireMode {
		class CWeaponGeneral* m_pWeapon;
	};


	struct SDeferredAttachment {

		int id;
		CryStringT<char> material;
		CryStringT<char> name;
	};
	using L_DEFFERED_ATTACH_LIST = std::list<CItemProxy::SDeferredAttachment, std::allocator<CItemProxy::SDeferredAttachment>>;

	ACEID_API CREATE_FUNCTOR(CWeaponGeneral*, m_weaponExt, 0x30);
	ACEID_API CREATE_FUNCTOR(CItemView*, m_itemView, 0x38);
	ACEID_API CREATE_FUNCTOR(CItemBox*, m_itemBox, 0x40);
	ACEID_API CREATE_FUNCTOR(bool, m_isWeaponEditor, 0x48);
	ACEID_API CREATE_FUNCTOR(bool, m_isSelectable, 0x49);
	ACEID_API CREATE_FUNCTOR(EntityId, m_id, 0x4C);
	ACEID_API CREATE_FUNCTOR(CryStringT<char>, m_displayName, 0x50);
	ACEID_API CREATE_FUNCTOR(CryStringT<char>, m_statisticsName, 0x60);
	ACEID_API CREATE_FUNCTOR(CAIFireModeProxy*, m_aIFireModeProxy, 0x70);
	ACEID_API CREATE_FUNCTOR(int, m_serverAmmoCount, 0x90);
	ACEID_API CREATE_FUNCTOR(int, m_serverUbAmmoCount, 0x94);
	ACEID_API CREATE_FUNCTOR(L_DEFFERED_ATTACH_LIST, m_deferredAttachList, 0x98);
};

#endif // !CITEMPROXY_HPP
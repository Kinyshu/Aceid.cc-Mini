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

#ifndef IPHYSICALWORLD_HPP
#define IPHYSICALWORLD_HPP

#include "../math/Vec3_tpl.hpp"

#include "../structures/ray_hit.hpp"
#include "../structures/SCollisionClass.hpp"

interface IPhysicalWorld {

	struct SRWIParams {

		void* pForeignData;
		int iForeignData;
		int(__fastcall* OnEvent)(const void*);
		Vec3_tpl<float> org;
		Vec3_tpl<float> dir;
		int objtypes;
		unsigned int flags;
		ray_hit* hits;
		int nMaxHits;
		ray_hit_cached* phitLast;
		int nSkipEnts;
		interface IPhysicalEntity** pSkipEnts;
		SCollisionClass collclass;
	};

	int RayWorldIntersection(SRWIParams& rp, const char* pNameTag, int iCaller) { return __ivtbl< int >(this, data::RayWorldIntersection, rp, pNameTag, iCaller); }
	int RayWorldIntersection(const Vec3_tpl<float>& org, const  Vec3_tpl<float>& dir, int objtypes, unsigned int flags, ray_hit* hits, int nMaxHits, IPhysicalEntity** pSkipEnts = 0, int nSkipEnts = 0, void* pForeignData = 0, int iForeignData = 0, const char* pNameTag = "", ray_hit_cached* phitLast = 0, int iCaller = 4) {

		SRWIParams rp;
		::memset(&rp, 0, sizeof SRWIParams);
		{
			rp.org = org;
			rp.dir = dir;
			rp.objtypes = objtypes;
			rp.flags = flags;
			rp.hits = hits;
			rp.nMaxHits = nMaxHits;
			rp.pForeignData = pForeignData;
			rp.iForeignData = iForeignData;
			rp.phitLast = phitLast;
			rp.pSkipEnts = pSkipEnts;
			rp.nSkipEnts = nSkipEnts;
		}

		return this->RayWorldIntersection(rp, pNameTag, iCaller);
	}
};

#endif // !IPHYSICALWORLD_HPP

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

#ifndef CCAMERA_HPP
#define CCAMERA_HPP

#include "../math/Matrix34_tpl.hpp"

template <typename T>
struct Plane_tpl {
	Vec3_tpl<T> n;
	T d;
};

class CCamera {
public:
	struct ScissorInfo {

		unsigned __int16 x1;
		unsigned __int16 y1;
		unsigned __int16 x2;
		unsigned __int16 y2;
	};

public:
	Matrix34_tpl<float> m_Matrix;
	float m_fov;
	int m_Width;
	int m_Height;
	float m_ProjectionRatio;
	float m_PixelAspectRatio;
	Vec3_tpl<float> m_edge_nlt;
	Vec3_tpl<float> m_edge_plt;
	Vec3_tpl<float> m_edge_flt;
	float m_asymL;
	float m_asymR;
	float m_asymB;
	float m_asymT;
	Vec3_tpl<float> m_cltp;
	Vec3_tpl<float> m_crtp;
	Vec3_tpl<float> m_clbp;
	Vec3_tpl<float> m_crbp;
	Vec3_tpl<float> m_cltn;
	Vec3_tpl<float> m_crtn;
	Vec3_tpl<float> m_clbn;
	Vec3_tpl<float> m_crbn;
	Vec3_tpl<float> m_cltf;
	Vec3_tpl<float> m_crtf;
	Vec3_tpl<float> m_clbf;
	Vec3_tpl<float> m_crbf;
	Plane_tpl<float> m_fp[6];
	unsigned int m_idx1[6];
	unsigned int m_idy1[6];
	unsigned int m_idz1[6];
	unsigned int m_idx2[6];
	unsigned int m_idy2[6];
	unsigned int m_idz2[6];
	float m_zrangeMin;
	float m_zrangeMax;
	int m_nPosX;
	int m_nPosY;
	int m_nSizeX;
	int m_nSizeY;
	interface IVisArea* m_pPortal;
	ScissorInfo m_ScissorInfo;
	void* m_pMultiCamera;
	Vec3_tpl<float> m_OccPosition;
	int m_JustActivated;
};

#endif // !CCAMERA_HPP
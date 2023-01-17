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

#ifndef IITEMVIEW_HPP
#define IITEMVIEW_HPP

interface IItemView {

	virtual void Function0() = 0;
	virtual void Function1() = 0;

	/*
	void (__fastcall *~IItemView)(IItemView *this);
	  void (__fastcall *EnableSound)(IItemView *this, bool);
	  bool (__fastcall *IsSoundEnabled)(IItemView *this);
	  IEntitySoundProxy *(__fastcall *GetSoundProxy)(IItemView *this, bool);
	  void (__fastcall *StopSound)(IItemView *this, unsigned int);
	  void (__fastcall *Quiet)(IItemView *this);
	  ISound *(__fastcall *GetISound)(IItemView *this, unsigned int);
	  void (__fastcall *SetActionSuffix)(IItemView *this, const char *, const char *);
	  void (__fastcall *PlayLayer)(IItemView *this, const char *, int, bool);
	  void (__fastcall *RestoreLayers)(IItemView *this);
	  void (__fastcall *SetDefaultIdleAnimation)(IItemView *this, int, const char *);
	  void (__fastcall *PlayAnimation)(IItemView *this, const char *, int, bool, unsigned int);
	  void (__fastcall *EnableAnimations)(IItemView *this, bool);
	  void (__fastcall *StopLayer)(IItemView *this, const char *, int, bool);
	  void (__fastcall *ResetAnimation)(IItemView *this, int, unsigned int);
	  void (__fastcall *UpdateFPView)(IItemView *this, float);
	  bool (__fastcall *FilterView)(IItemView *this, SViewParams *);
	  void (__fastcall *PostFilterView)(IItemView *this, SViewParams *);
	  Matrix34_tpl<float,XMVec4> *(__fastcall *GetEffectWorldTM)(IItemView *this, Matrix34_tpl<float,XMVec4> *result, unsigned int);
	  void (__fastcall *SetEffectWorldTM)(IItemView *this, unsigned int, const Matrix34_tpl<float,XMVec4> *);
	  IParticleEmitter *(__fastcall *GetEffectEmitter)(IItemView *this, unsigned int);
	  unsigned int (__fastcall *AttachEffect)(IItemView *this, int, unsigned int, bool, const char *, const char *, const Vec3_tpl<float> *, const Vec3_tpl<float> *, float, bool);
	  void (__fastcall *SpawnEffect)(IItemView *this, int, const char *, const char *, const Vec3_tpl<float> *, const Vec3_tpl<float> *, float);
	  unsigned int (__fastcall *AttachLight)(IItemView *this, int, unsigned int, bool, float, const Vec3_tpl<float> *, const float, const char *, float, const char *, const Vec3_tpl<float> *, const Vec3_tpl<float> *, const char *, float);
	  void (__fastcall *EnableLight)(IItemView *this, bool, unsigned int);
	  unsigned int (__fastcall *AttachLightEx)(IItemView *this, int, unsigned int, bool, bool, bool, IRenderNode *, float, const Vec3_tpl<float> *, const float, const char *, float, const char *, const Vec3_tpl<float> *, const Vec3_tpl<float> *, const char *, float);
	  void (__fastcall *SetLightRadius)(IItemView *this, float, unsigned int);
	  Vec3_tpl<float> *(__fastcall *GetSlotHelperPos)(IItemView *this, Vec3_tpl<float> *result, int, const char *, bool, bool);
	  const Matrix33_tpl<float> *(__fastcall *GetSlotHelperRotation)(IItemView *this, int, const char *, bool, bool);
	  void (__fastcall *DrawSlot)(IItemView *this, int, bool, bool);
	  void (__fastcall *SetViewMode)(IItemView *this, int);
	  int (__fastcall *GetViewMode)(IItemView *this);
	  void (__fastcall *ApplyViewLimit)(IItemView *this, unsigned int, bool);
	  void (__fastcall *ForceSkinning)(IItemView *this, bool);
	  float (__fastcall *GetNearFov)(IItemView *this);
	  const char *(__fastcall *GetDofMask)(IItemView *this);
	  const char *(__fastcall *GetBlurMask)(IItemView *this);
	  int (__fastcall *GetSkinsCount)(IItemView *this);
	  const char *(__fastcall *GetSkinName)(IItemView *this, int);
	  void (__fastcall *SetSkin)(IItemView *this, const char *);
	  void (__fastcall *SetActionSuffix)(CItemProxy::CItemView *this, const char *);
	  bool (__fastcall *SetGeometry)(CItemProxy::CItemView *this, int, const char *, const Vec3_tpl<float> *, const Ang3_tpl<float> *, float, bool);
	*/
};

#endif // !IITEMVIEW_HPP

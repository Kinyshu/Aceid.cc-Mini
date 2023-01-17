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

#ifndef IITEMEDIT_HPP
#define IITEMEDIT_HPP

interface IItemEdit {

	struct SItemHelper {

		const char* name;
		const char* bone;
		int slot;
	};


	virtual void Function0() = 0;
	virtual void Function1() = 0;

	/*
	  void (__fastcall *~IItemEdit)(IItemEdit *this);
	  void (__fastcall *BindToEditor)(IItemEdit *this, bool);
	  void (__fastcall *SetViewFile)(IItemEdit *this, XmlNodeRef);
	  void (__fastcall *SetViewFile)(IItemEdit *this, const char *);
	  void (__fastcall *SetWeaponSettings)(IItemEdit *this, const char *);
	  bool (__fastcall *GetHelperPos)(IItemEdit *this, const char *, QuatT_tpl<float> *, bool);
	  void (__fastcall *SetHelperPos)(IItemEdit *this, const char *, const QuatT_tpl<float> *);
	  bool (__fastcall *IsHelperUsed)(IItemEdit *this, const char *);
	  bool (__fastcall *IsAttHelperUsed)(IItemEdit *this, const char *);
	  unsigned int (__fastcall *GetHelpersCount)(IItemEdit *this);
	  const char *(__fastcall *GetHelperName)(IItemEdit *this, unsigned int);
	  const char *(__fastcall *GetHelperBone)(IItemEdit *this, const char *);
	  int (__fastcall *GetBoneHelperCount)(IItemEdit *this);
	  bool (__fastcall *GetBoneHelper)(IItemEdit *this, int, IItemEdit::SItemHelper *);
	  bool (__fastcall *SetBoneHelper)(IItemEdit *this, int, const IItemEdit::SItemHelper *);
	  const char *(__fastcall *GetSlotGeometry)(IItemEdit *this, int);
	  void (__fastcall *SetSlotGeometry)(IItemEdit *this, int, const char *);
	  void (__fastcall *SetViewMode)(IItemEdit *this, EViewMode);
	  const char *(__fastcall *GetIKPoseLayer)(IItemEdit *this, const char *);
	  const char *(__fastcall *GetIKPoseRootAnim)(IItemEdit *this, const char *);
	  int (__fastcall *GetIKPosePriority)(IItemEdit *this, const char *);
	  void (__fastcall *SetupIkPose)(IItemEdit *this, const char *, const char *, const char *, int);
	  void (__fastcall *RemoveIkPose)(IItemEdit *this, const char *);
	  int (__fastcall *GetIKPosesCount)(IItemEdit *this);
	  const char *(__fastcall *GetIKPoseName)(IItemEdit *this, int);
	  void (__fastcall *PlayIKPose)(IItemEdit *this, const char *);
	  void (__fastcall *StopIKPose)(IItemEdit *this, const char *);
	  int (__fastcall *GetLayersCount)(IItemEdit *this);
	  const char *(__fastcall *GetLayerName)(IItemEdit *this, int);
	  int (__fastcall *GetLayerId)(IItemEdit *this, const char *);
	  void (__fastcall *SetLayer)(IItemEdit *this, const char *, const char *, int);
	  void (__fastcall *RemoveLayer)(IItemEdit *this, const char *);
	  int (__fastcall *GetLayerBonesCount)(IItemEdit *this, const char *);
	  const char *(__fastcall *GetLayerBoneName)(IItemEdit *this, const char *, int);
	  bool (__fastcall *IsLayerStatic)(IItemEdit *this, const char *);
	  const char *(__fastcall *GetLayerAnimation)(IItemEdit *this, const char *);
	  bool (__fastcall *GetZoomParams)(IItemEdit *this, float *, char *, unsigned __int64, bool *, bool *, bool *, bool *, char *, unsigned __int64);
	  void (__fastcall *SetZoomParams)(IItemEdit *this, float, const char *, bool, bool, bool, bool);
	  void (__fastcall *RemoveZoomParams)(IItemEdit *this);
	  void (__fastcall *LoadReplay)(IItemEdit *this, const char *);
	  void (__fastcall *PlayReplay)(IItemEdit *this);
	  void (__fastcall *SetMaterial)(IItemEdit *this, const char *);
	  void (__fastcall *AddMaterial)(IItemEdit *this, const char *, const char *, const char *);
	  int (__fastcall *GetMaterialCount)(IItemEdit *this);
	  const char *(__fastcall *GetMaterialName)(IItemEdit *this, int);
	  const char *(__fastcall *GetFPMaterialFile)(IItemEdit *this, int);
	  const char *(__fastcall *GetTPMaterialFile)(IItemEdit *this, int);
	  void (__fastcall *RemoveMaterial)(IItemEdit *this, int);
	  bool (__fastcall *AttachToHelper)(IItemEdit *this, const char *, const char *);
	  unsigned int (__fastcall *GetCommonHelpersCount)(IItemEdit *this);
	  const char *(__fastcall *GetCommonHelperName)(IItemEdit *this, unsigned int);
*/
};

#endif // !IITEMEDIT_HPP

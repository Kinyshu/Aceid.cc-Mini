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

#ifndef IITEMBOX_HPP
#define IITEMBOX_HPP

interface IItemBox {

	virtual void Function0() = 0;
	virtual void Function1() = 0;

	/*
	void (__fastcall *~IItemBox)(IItemBox *this);
	  unsigned int (__fastcall *GetOwnerId)(IItemBox *this);
	  bool (__fastcall *IsOwnerFP)(IItemBox *this);
	  IEntity *(__fastcall *GetOwner)(IItemBox *this);
	  CPlayer *(__fastcall *GetOwnerPlayer)(IItemBox *this);
	  void (__fastcall *SetParentId)(IItemBox *this, unsigned int);
	  void (__fastcall *Physicalize)(IItemBox *this, bool, bool);
	  void (__fastcall *Drop)(IItemBox *this, float, bool, bool);
	  void (__fastcall *PickUp)(IItemBox *this, unsigned int);
	  bool (__fastcall *CanPickUp)(IItemBox *this, unsigned int);
	  bool (__fastcall *CanDrop)(IItemBox *this);
	  bool (__fastcall *IsNoDrop)(IItemBox *this);
	  bool (__fastcall *IsCurrentItem)(IItemBox *this);
	  bool (__fastcall *IsMountable)(IItemBox *this);
	  bool (__fastcall *IsMounted)(IItemBox *this);
	  bool (__fastcall *IsRippable)(IItemBox *this);
	  bool (__fastcall *IsRippedOff)(IItemBox *this);
	  void (__fastcall *MountAt)(IItemBox *this, const Vec3_tpl<float> *);
	  void (__fastcall *MountAtEntity)(IItemBox *this, unsigned int, const Vec3_tpl<float> *, const Ang3_tpl<float> *);
	  Vec3_tpl<float> *(__fastcall *GetMountedAngleLimits)(IItemBox *this, Vec3_tpl<float> *result);
	  Vec3_tpl<float> *(__fastcall *GetMountedDir)(IItemBox *this, Vec3_tpl<float> *result);
	  void (__fastcall *SetMountedAngleLimits)(IItemBox *this, float, float, float);
	  void (__fastcall *ResetCharacterAttachment)(IItemBox *this, int, const char *);
	  void (__fastcall *SetCharacterAttachmentLocalTM)(IItemBox *this, int, const char *, const Matrix34_tpl<float,XMVec4> *);
	  bool (__fastcall *AttachToHand)(IItemBox *this, bool, bool);
	  bool (__fastcall *AttachToBack)(IItemBox *this, bool);
	  void (__fastcall *ReAttachAccessories)(IItemBox *this);
	  void (__fastcall *RemoveAllAccessories)(IItemBox *this);
	  unsigned int (__fastcall *GetAccessoriesCount)(IItemBox *this);
	  unsigned int (__fastcall *GetAccessoryId)(IItemBox *this, unsigned int);
	  const char *(__fastcall *GetAccessoryAttachHelper)(IItemBox *this, const char *);
	  const char *(__fastcall *GetAccessoryName)(IItemBox *this, unsigned int);
	  void (__fastcall *SwitchAccessory)(IItemBox *this, const char *);
	  bool (__fastcall *AttachAccessory)(IItemBox *this, const char *, bool, bool, bool, bool);
	  void (__fastcall *AttachAccessoryPlaceHolder)(IItemBox *this, const char *, bool);
	  bool (__fastcall *HasAccessoryParams)(IItemBox *this, const char *);
	  void (__fastcall *RemoveAccessory)(IItemBox *this, const char *);
	  void (__fastcall *RemoveBonusAccessoryAmmo)(IItemBox *this);
	  void (__fastcall *AccessoriesChanged)(IItemBox *this);
	  IItem *(__fastcall *GetAccessory)(IItemBox *this, const char *);
	  IItem *(__fastcall *GetAccessoryPlaceHolder)(IItemBox *this, const char *);
	  bool (__fastcall *IsFP)(IItemBox *this);
	  int (__fastcall *GetScopeAttachment)(IItemBox *this);
	  void (__fastcall *Hide)(IItemBox *this, bool);
	  void (__fastcall *EnterWater)(IItemBox *this, bool);
	  void (__fastcall *Cloak)(IItemBox *this, bool, IMaterial *);
	  void (__fastcall *CloakEnable)(IItemBox *this, bool, bool);
	  void (__fastcall *CloakSync)(IItemBox *this, bool);
	  void (__fastcall *Freeze)(IItemBox *this, bool);
	  void (__fastcall *FrostSync)(IItemBox *this, bool);
	  void (__fastcall *WetSync)(IItemBox *this, bool);
	*/
};

#endif // !IITEMBOX_HPP

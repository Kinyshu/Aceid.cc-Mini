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

#ifndef ITHREADTASKMANAGER_HPP
#define ITHREADTASKMANAGER_HPP

#include "IThreadTask.hpp"
#include "../structures/SThreadTaskParams.hpp"

interface IThreadTaskManager {
public:
	virtual ~IThreadTaskManager();
	virtual void RegisterTask(IThreadTask* pTask, const SThreadTaskParams* options);
	virtual void UnregisterTask(IThreadTask* pTask);
	virtual void SetMaxThreadCount(int nMaxThreads);
	/*
	
	4  int (__fastcall *CreateThreadsPool)(IThreadTaskManager *this, const ThreadPoolDesc *);
	5  bool (__fastcall *DestroyThreadsPool)(IThreadTaskManager *this, const int *);
	6  bool (__fastcall *GetThreadsPoolDesc)(IThreadTaskManager *this, const int, ThreadPoolDesc *);
	7  bool (__fastcall *SetThreadsPoolAffinity)(IThreadTaskManager *this, const int, const unsigned int);
	8  void (__fastcall *MarkThisThreadForDebugging)(IThreadTaskManager *this, const char *, bool);
	
	*/
};

#endif // !ITHREADTASKMANAGER_HPP
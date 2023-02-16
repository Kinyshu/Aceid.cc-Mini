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

#ifndef HELPER_HPP_
#define HELPER_HPP_

#define aceid_api
#define ACEID_API

#define WITH_ARGUMENTS
#define CREATE_VMT_HOOK(TYPE, NAME, CODE, ARGUMENTS)						\
	using NAME##_Using = TYPE(__fastcall*)ARGUMENTS;						\
	NAME##_Using NAME##_Original;											\
	CVMTHandler* NAME##_Pointer = CODE;										\
	TYPE __fastcall NAME##_Hook ARGUMENTS 									\

#define CREATE_VMT_STATIC_HOOK(TYPE, NAME, ARGUMENTS)						\
	using NAME##_Using = TYPE(__fastcall*)ARGUMENTS;						\
	NAME##_Using NAME##_Original;											\
	CVMTHandler* NAME##_Pointer = nullptr;									\
	TYPE __fastcall NAME##_Hook ARGUMENTS 									\

#define CREATE_STATIC_HOOK(TYPE, NAME, ARGUMENTS)							\
	using NAME##_Using = TYPE(__fastcall*)ARGUMENTS;						\
	NAME##_Using NAME##_Original;											\
	TYPE __fastcall NAME##_Hook ARGUMENTS 									\

#define CREATE_FUNCTOR(TYPE, NAME, OFFSET)									\
	TYPE NAME##_GET() {														\
		return *reinterpret_cast< TYPE* >(this + OFFSET);					\
	}																		\
																			\
	void NAME##_SET(TYPE VALUE) {											\
		*reinterpret_cast< TYPE* >(this + OFFSET) = VALUE;					\
	}																		\
																			\
	__declspec(property(get = NAME##_GET, put = NAME##_SET)) TYPE NAME		\

#define CREATE_FUNCTOR_STRUCT(TYPE, NAME, OFFSET)							\
	TYPE* NAME##_GET() {													\
		return &*reinterpret_cast< TYPE* >(this + OFFSET);					\
	}																		\
																			\
	__declspec(property(get = NAME##_GET)) TYPE* NAME						\

using EntityId = unsigned int;

namespace api {

	std::string format(std::string str, ...) {

		char buffer[2048];
		sprintf(buffer, str.c_str());

		return std::string(buffer);
	}
}

template <typename TYPE, std::uintptr_t INDEX, typename ...ARGUMENTS>
__forceinline auto __vtbl(void* __ptr64 pointer, ARGUMENTS... arguments) {
	return ((*reinterpret_cast<TYPE(__thiscall***)(void*, ARGUMENTS...)>(pointer))[INDEX])(pointer, arguments...);
}

template <typename TYPE, typename ...ARGUMENTS>
__forceinline auto __ivtbl(void* __ptr64 pointer, std::uintptr_t INDEX, ARGUMENTS... arguments) {
	return ((*reinterpret_cast<TYPE(__thiscall***)(void*, ARGUMENTS...)>(pointer))[INDEX])(pointer, arguments...);
}

#endif // !HELPER_HPP_

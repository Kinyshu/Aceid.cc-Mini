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

#ifndef ISCRIPTSYSTEM_HPP
#define ISCRIPTSYSTEM_HPP

#include "../classes/CScriptTable.hpp"

enum BreakState {

	bsStepNext,
	bsStepInto,
	bsStepOut,
	bsContinue,
	bsNoBreak
};

interface IScriptSystem {

	virtual void Function0() = 0; //0	
	virtual void Update() = 0; //1
	virtual void SetGCFrequency(const float fRate) = 0; //2
	virtual void SetEnvironment(struct SScriptFuncHandle* scriptFunction, IScriptTable* pEnv) = 0; //3
	virtual IScriptTable* GetEnvironment(SScriptFuncHandle* scriptFunction) = 0; //4
	virtual bool ExecuteFile(const char* sFileName, bool bRaiseError = true, bool bForceReload = false, IScriptTable* pEnv = 0) = 0; //5
	virtual bool ExecuteBuffer(const char* sBuffer, size_t nSize, const char* sBufferDescription = "", IScriptTable* pEnv = 0) = 0; //6
	virtual void UnloadScript(const char* sFileName) = 0; //7
	virtual void UnloadScripts() = 0; //8
	virtual bool ReloadScript(const char* sFileName, bool bRaiseError = true) = 0; //9
	virtual bool ReloadScripts() = 0; //10
	virtual void DumpLoadedScripts() = 0; //11
	virtual IScriptTable* CreateTable(bool bEmpty = false) = 0; //12
	virtual int BeginCall(IScriptTable* pTable, const char* sFuncName) = 0; //13
	virtual int BeginCall(const char* sTableName, const char* sFuncName) = 0; //14
	virtual int BeginCall(const char* sFuncName) = 0; //15
	virtual int BeginCall(SScriptFuncHandle* hFunc) = 0; //16
	virtual bool EndCall() = 0; //17
	virtual bool EndCallAny(struct ScriptAnyValue& any) = 0; //
	virtual bool EndCallAnyN(int n, ScriptAnyValue* anys) = 0; //
	virtual SScriptFuncHandle* GetFunctionPtr(const char* sTableName, const char* sFuncName) = 0; //20
	virtual SScriptFuncHandle* GetFunctionPtr(const char* sFuncName) = 0; //
	virtual SScriptFuncHandle* AddFuncRef(SScriptFuncHandle* f) = 0; //
	virtual bool CompareFuncRef(SScriptFuncHandle* f1, SScriptFuncHandle* f2) = 0; //
	virtual void ReleaseFunc(SScriptFuncHandle* f) = 0; //
	virtual ScriptAnyValue CloneAny(const ScriptAnyValue& any) = 0; //
	virtual void ReleaseAny(const ScriptAnyValue& any) = 0; //
	virtual void PushFuncParamAny(const ScriptAnyValue& any) = 0; //
	virtual void SetGlobalAny(const char* sKey, const ScriptAnyValue& any) = 0; //
	virtual bool GetGlobalAny(const char* sKey, ScriptAnyValue& any) = 0; //
	virtual void SetGlobalToNull(const char* sKey) = 0; //
	virtual IScriptTable* CreateUserData(void* ptr, size_t size) = 0; //
	virtual void ForceGarbageCollection() = 0; //
	virtual int GetCGCount() = 0; //
	virtual void SetGCThreshhold(int nKb) = 0; //
	virtual void Release() = 0; //
	virtual void ShowDebugger(const char* pszSourceFile, int iLine, const char* pszReason) = 0; //
	virtual int AddBreakPoint(const char* sFile, int nLineNumber) = 0; //
	virtual IScriptTable* GetLocalVariables(int nLevel = 0) = 0; //
	virtual IScriptTable* GetCallsStack() = 0; //
	virtual void DumpCallStack() = 0; //
	virtual void DebugContinue() = 0; //
	virtual void DebugStepNext() = 0; //
	virtual void DebugStepInto() = 0; //
	virtual void DebugDisable() = 0; //
	virtual BreakState GetBreakState() = 0; //
	virtual void DumpCombinedCallStack() = 0; //
	virtual void GetMemoryStatistics(interface ICrySizer* pSizer) const = 0; //
	virtual void GetScriptHash(const char* sPath, const char* szKey, unsigned int& dwHash) = 0; //
	virtual void RaiseError(const char* format, ...) = 0; //
	virtual void PostInit() = 0; //
	virtual void LoadScriptedSurfaceTypes(const char* sFolder, bool bReload) = 0; //
	virtual void SerializeTimers(interface ISerialize* pSer) = 0; //
	virtual void ResetTimers() = 0; //
	virtual int GetStackSize() = 0; //
	virtual unsigned int GetScriptAllocSize() = 0; //
	virtual SScriptFuncHandle* CompileBuffer(const char* sBuffer, size_t nSize, const char* sBufferDesc) = 0; //
	virtual int PreCacheBuffer(const char* sBuffer, size_t nSize, const char* sBufferDesc) = 0; //
	virtual int BeginPreCachedBuffer(int iIndex) = 0; //
	virtual void ClearPreCachedBuffer() = 0; //
	virtual void* Allocate(size_t sz) = 0; //
	virtual size_t Deallocate(void* ptr) = 0; //

	ACEID_API CREATE_FUNCTOR(void*, L, 0x10);
};

#endif // !ISCRIPTSYSTEM_HPP

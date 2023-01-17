#pragma once

#ifndef C3DENGINE_HPP
#define C3DENGINE_HPP

class C3DEngine {
public:
	void SetPostEffectParam(const char* pParam, float fValue, bool bForceValue = false) { 
		__ivtbl< void >(this, data::SetPostEffectParam, pParam, fValue, bForceValue);
	}
};

#endif // !C3DENGINE_HPP
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

#ifndef CMASKEDVART_HPP
#define CMASKEDVART_HPP

template <class TVarType, typename TMaskType, TMaskType TMaxMaskValue = 0x7FFFFFFF>
class CMaskedVarT
{
public:
	CMaskedVarT() : m_mask(0) { }
	CMaskedVarT(const TVarType v) { Set(v); }

	operator TVarType () const { return this->Get(); }

	CMaskedVarT& operator += (const TVarType rhs) {
		TVarType  v = this->Get();
		v += rhs;
		this->Set(v);
		return (*this);
	}

	CMaskedVarT& operator -= (const TVarType rhs)
	{
		TVarType  v = this->Get();
		v -= rhs;
		this->Set(v);
		return (*this);
	}

	CMaskedVarT& operator *= (const TVarType rhs)
	{
		TVarType  v = this->Get();
		v *= rhs;
		this->Set(v);
		return (*this);
	}

	CMaskedVarT& operator /= (const TVarType rhs) {

		TVarType  v = this->Get();
		v /= rhs;
		this->Set(v);
		return (*this);
	}

	CMaskedVarT& operator = (const TVarType rhs) {
		Set(rhs);
		return (*this);
	}

private:

	void Set(const TVarType v) {

		UVal		w;
		w.asVarType = v;
		m_val.asMaskType = (w.asMaskType ^ m_mask);
	}

	TVarType Get() const
	{
		UVal  w;
		w.asMaskType = 0;
		if (m_mask > 0) w.asMaskType = (m_val.asMaskType ^ m_mask);
		return w.asVarType;
	}

	union UVal {
		TVarType asVarType;
		TMaskType asMaskType;
	};

	UVal m_val;
	TMaskType m_mask;
};

#endif // !CMASKEDVART_HPP

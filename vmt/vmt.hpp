#pragma once

#ifndef VMT_HPP
#define VMT_HPP

class CVMTHandler {
public:

	class CProtection {
	public:

		template <typename T>
		CProtection(T address, std::size_t size, DWORD protection)
			: address(reinterpret_cast<void*>(address)), size(size), protection(0) {

			VirtualProtect(address, size, protection, &this->protection);
		};

		~CProtection() {
			VirtualProtect(this->address, this->size, this->protection, &this->protection);
		}

	private:

		void* address;
		std::size_t size;
		DWORD protection;
	};

public:

	CVMTHandler(std::uintptr_t** ptr, std::size_t offset = 0u) : ptr(ptr) {
		auto m_pProtection = CProtection(ptr, sizeof std::uintptr_t, PAGE_READWRITE);

		this->optr = *ptr;
		this->size = offset ? offset : this->count();

		this->vft = std::make_unique< std::uintptr_t[] >(this->size);
		memcpy(this->vft.get(), this->optr, this->size * 8);

		*this->ptr = this->vft.get();
	}

	~CVMTHandler() {
		auto m_pProtection = CProtection(ptr, 8, PAGE_READWRITE);
		*this->ptr = this->optr;
	}

	template <typename T>
	T hook(std::size_t index, T function) {
		vft[index] = reinterpret_cast<std::uintptr_t>(function);
		return reinterpret_cast<T>(optr[index]);
	}

	void unhook() {
		auto m_pProtection = CProtection(ptr, 8, PAGE_READWRITE);
		*this->ptr = this->optr;
	}

public:
	std::size_t count() {
		std::size_t size = 0u;

		while (this->optr[size] != 0 && (this->optr[size] >= 0x10000)
			&& (this->optr[size] < 0x000F000000000000)) ++size;

		return size;
	}

private:

	std::size_t size;
	std::uintptr_t** ptr;
	std::uintptr_t* optr;

	std::unique_ptr< std::uintptr_t[] > vft;
};

#endif // !VMT_HPP
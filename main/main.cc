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
#include "stdafx.hpp"

void main() {

	::AllocConsole();
	{
		std::freopen(xorstr("CONIN$"), "r", stdin);
		std::freopen(xorstr("CONOUT$"), "w", stdout);
		std::freopen(xorstr("CONOUT$"), "w", stderr);
	}

	::SetConsoleCP(1251);
	::SetConsoleOutputCP(1251);

	::SetConsoleTitleA(xorstr("Warface"));

	while (true) {

		static std::string input;
		std::system("cls");

		std::cout << termcolor::white << "[" << termcolor::green << "+" << termcolor::white << "] " <<
			xorstr("Aceid.cc -> Mini -> Version 1.0 -> Welcome!\n") << std::endl;

		std::cout << termcolor::white << "[" << termcolor::yellow << "!" << termcolor::white << "] " <<
			xorstr("Запускайте чит в оконном режиме игры!") << std::endl;
		std::cout << termcolor::white << "[" << termcolor::blue << "&" << termcolor::white << "] " <<
			xorstr("Сайт проекта: https://aceid.cc/") << std::endl;
		std::cout << termcolor::white << "[" << termcolor::blue << "&" << termcolor::white << "] " <<
			xorstr("Поддержка: https://qiwi.com/n/KINYSHUACEID\n") << std::endl;

		std::cout << termcolor::white << "[" << termcolor::green << "+" << termcolor::white << "] " <<
			xorstr("Инициализация функционала") << std::endl;

		std::cout << termcolor::white << "\n[" << termcolor::yellow << "!" << termcolor::white << "] " <<
			xorstr("Ожидайте пока не загрузитесь в лобби!") << std::endl;


		std::cout << termcolor::white << "[" << termcolor::green << "+" << termcolor::white << "] " <<
			xorstr("Когда загрузитесь в лобби. Введите 'Continue'!") << std::endl;

		std::cout << termcolor::white << "\n[" << termcolor::blue << "~" << termcolor::white << "] " <<
			xorstr("Ввод: ");

		std::cin >> input;
		if (input == "Continue") {
			break;
		}
		else {
			continue;
		}
	}

	CreateThread(0, 0, LPTHREAD_START_ROUTINE(dxhook::create), 0, 0, 0);
}

int __stdcall DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {

	if (reason == DLL_PROCESS_ATTACH) {
		CreateThread(0, 0, LPTHREAD_START_ROUTINE(main), 0, 0, 0);
	}

	return 1;
}
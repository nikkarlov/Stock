#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>

#include "Generator.h"
#include "GUI.h"

int main() {
#if !_DEBUG
	ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif // !_DEBUG

	try {
		std::srand(std::time(nullptr));
		generator::run();
		GUI gui(1280, 720, "test");

		while (gui.isOpened()) {
			if (gui.pressed()) {
				generator::stock.NextDay();
			}
			gui.Draw(generator::stock);
		}
	}
	catch (...) {
		ShowWindow(GetConsoleWindow(), SW_SHOW);
		std::cerr << "Something went wrong. We are sorry about that :(" << std::endl;
		system("pause");
		return 1;
	}
}
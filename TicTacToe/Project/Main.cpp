#include "Player.h"
#include "Game_Control.h"
#include "TicTacToe.h"
#include <iostream>

using namespace std;

int main() {
	int option;
	Game_Control *gc = new Game_Control();

	while (true) {
		MenuGame();
		cout << "Xin moi nhap lua chon: ";
		cin >> option;
		ClearScreen();
		switch (option) {
		case 0:
			break;
		case 1:
			if (GameMode() == true) {
				ClearScreen();
				gc->BroardSize(3);
				ErrorMessage_3();
			}
			else {
				ErrorMessage_Future();
			}
			break;
		case 2:
			if (GameMode() == true) {
				ClearScreen();
				gc->BroardSize(5);
				ErrorMessage_3();
			}
			else {
				ErrorMessage_Future();
			}
			break;
		case 3:
			if (GameMode() == true) {
				ClearScreen();
				gc->BroardSize(7);
				ErrorMessage_3();
			}
			else {
				ErrorMessage_Future();
			}
			break;
		case 9:
			exit(1);
		default:
			ClearScreen();
			ErrorMessage_1();
		}
	}

	return 0;
}
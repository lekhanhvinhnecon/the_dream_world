#include <string>
#include <iostream>
#include <windows.h>
using namespace std;
void ClearScreen() {
	cout << "\033[2J\033[1;1H";
}
void ErrorMessage_Future() {
	ClearScreen();
	cout << "Message(Future):" << endl;
	cout << "\tTinh nang dang duoc phat trien. Vui long doi trong thoi gian sap toi" << endl;
	cout << "\tBan co muon chon them muc khac?(0.No/1.Yes)" << endl;
	int option;
	do {
		cin >> option;
		if (option != 0 && option != 1) {
			cout << "Phat hien loi - Lua chon khong co trong danh sach!!!" << endl;
			cout << "Vui long nhap lai lua chon." << endl;
		}
	} while (option != 0 && option != 1);
	if (option == 0) {
		exit(1);
	}
	ClearScreen();
}
void ErrorMessage_1() {
	cout << "Message(1):" << endl;
	cout << "\tPhat hien loi - Lua chon khong co trong danh sach!!!" << endl;
	cout << "\tVui long xem lai MenuGame va nhap lai lua chon." << endl;
	cout << endl;
}
void ErrorMessage_2() {
	cout << "Message(2):" << endl;
	cout << "\tPhat hien loi- Vi tri da duoc chon!!!" << endl;
	cout << "\tVui long chon vi tri khac." << endl;
	cout << endl;
}
void ErrorMessage_3() {
	cout << "Ban co muon tiep tuc khong?(0.No/1.Yes)" << endl;
	int option;
	do {
		cin >> option;
		if (option != 0 && option != 1) {
			cout << "Phat hien loi - Lua chon khong co trong danh sach!!!" << endl;
			cout << "Vui long nhap lai lua chon." << endl;
		}
	} while (option != 0 && option != 1);
	if (option == 0) {
		exit(1);
	}
	ClearScreen();
}
void MenuGame() {
	cout << "---------- MenuGame ----------" << endl;
	cout << "0. Huong dan" << endl;
	cout << "1. Caro 3x3" << endl;
	cout << "2. Caro 5x5" << endl;
	cout << "3. Caro 7x7" << endl;
	cout << "9. Thoat tro choi" << endl;
	cout << "------------------------------" << endl;
}
void Light(string str) {
	int i = 0;
	while (true) {
		switch (i % 7) {
		case 0:
			cout << "\033[1;31m" << str;
			break;
		case 1:
			cout << "\033[1;33m" << str;
			break;
		case 2:
			cout << "\033[1;93m" << str;
			break;
		case 3:
			cout << "\033[1;32m" << str;
			break;
		case 4:
			cout << "\033[1;34m" << str;
			break;
		case 5:
			cout << "\033[1;35m" << str;
			break;
		case 6:
			cout << "\033[1;95m" << str;
			break;
		}
		cout << str << endl;
		Sleep(1000);
		i++;
	}
}
bool GameMode() {
	int option;
	do {
		cout << "Vui long chon che do choi (0.PvE/1.PvP): ";
		cin >> option;
		if (option != 0 && option != 1) {
			ClearScreen();
			cout << "Phat hien loi - Lua chon khong co trong danh sach!!!" << endl;
			cout << "Vui long nhap lai lua chon." << endl;
		}
	} while (option != 0 && option != 1);
	if (option == 0) {
		return false;
	}
	else {
		return true;
	}

}
int FuncLab(int height, int width, int size) {
	int data_sub[] = {0,5,10,15,20}, lenght = 5, cheo_huyen, cheo_sac, doc, ngang;
	for (int i = 0; i < lenght-3; i++) {
		cheo_huyen = 1, cheo_sac = 1, doc = 1, ngang = 1;
		for (int j = i+1; j < lenght; j++) {
			// Tinh duong ngang
			if (data_sub[i] == data_sub[j] - ngang) {
				cout << "ngang - i: " << data_sub[i] << ", j:" << data_sub[j] << ", flags: " << ngang << endl;
				ngang++;
				
				if ((data_sub[j] + 1) % size == 0 || (data_sub[i] + 1) % size == 0) {
					cout << "yes" << endl;
					if (ngang < 5) {
						cout << "reset: " << "i: " << data_sub[i] << ", j : " << data_sub[j] << endl;
						ngang = 1;
					}
				}
				if (ngang == 5) {
					cout << "flags: " << ngang << endl ;
					return 1;
				}
			}
			// Tinh duong doc
			if (data_sub[i] == data_sub[j] * doc) {
				cout << "doc - i: " << data_sub[i] << ", j:" << data_sub[j] << ", flags: " << doc << endl;
				doc++;
				if (doc == 5) {
					cout << "flags: " << doc << endl;
					return 1;
				}
			}
			// Tinh duong cheo dau huyen
			if (data_sub[i] == data_sub[j]+(size+1)*2 || data_sub[i] == data_sub[j]+(size+1) || data_sub[i] == data_sub[j]-(size+1)*2 || data_sub[i] == data_sub[j]-(size+1)) {
				cheo_huyen++;
				if (cheo_huyen == 4) {
					return 1;
				}
			}
			// Tinh duong cheo dau sac
			if (data_sub[i] == data_sub[j] + size*2-2 || data_sub[i] == data_sub[j] + size-1 ||  data_sub[i] == data_sub[j] - size+1 || data_sub[i] == data_sub[j] - size*2+2) {
				cheo_sac++;
				cout << "i: " << data_sub[i] << ", j:" << data_sub[j] << endl;
				if (data_sub[j] % size == 0 || data_sub[i] % size == 0) {
					if (cheo_sac < 4) {
						cout << "size: " << "i: " << data_sub[i] << ", j : " << data_sub[j] << endl;
						cheo_sac--;
					}
				}
				if (cheo_sac == 4) {
					return 1;
				}
			}
		}
	}
	return 0;
}
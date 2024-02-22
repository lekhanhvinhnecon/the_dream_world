/*Attention:
	The source code is merged from the files in the project into one file that runs independently.
*/

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Khai bao lop Player 
class Player {
private:
	int luotChoi;
public:
	void Nhap_DuLieu();
	int getLuotChoi();
	bool kiemTra(Player* p[], int n, int key, int size);
};

// Khai bao lop Game_Control ke thua cong khai lop Player
class Game_Control :
    public Player
{
private:
	int data[100];
	int lenght;
public:
	Game_Control();
	void Set(Player* value[], int n);
	void ManHinhCho(int height, int width);
	void VeBanCo(int height, int width, int size);
	void SapXep_MangCon(int data_sub[], int n);
	int Tien_KetQua_3(int data_sub[], int lenght, int size);
	int Tien_KetQua(int data_sub[], int lenght, int size);
	int KetQua(int size);
	void BroardSize(int size);
	void GiaiPhong(Player* value[], int n);
};

// Ham toan cuc 
void ErrorMessage_Future();
void ErrorMessage_1();
void ErrorMessage_2();
void ErrorMessage_3();
void MenuGame();
void Light(std::string str);
bool GameMode();
void ClearScreen();
int FuncLab(int height, int width, int flag);

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
// Player 
void Player::Nhap_DuLieu() {
	std::cin >> luotChoi;
}
int Player::getLuotChoi() {
	return luotChoi;
}
bool Player::kiemTra(Player* p[], int n, int key, int flags) {
	if (key >= flags * flags) {
		return false;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (key == p[i]->getLuotChoi()) {
				return false;
			}
		}
	}

	return true;
} 
// Game_Control
Game_Control::Game_Control() {
	data[0] = -1;
	lenght = 1;
}
void Game_Control::Set(Player* value[], int n) {
	lenght = n;
	for (int i = 0; i < lenght; i++) {
		data[i] = value[i]->getLuotChoi();
	}
}
void Game_Control::SapXep_MangCon(int data_sub[], int n) {
	int temp;
	if (lenght > 1) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (data_sub[i] > data_sub[j]) {
					temp = data_sub[i];
					data_sub[i] = data_sub[j];
					data_sub[j] = temp;
				}
			}
		}
	}
}
void Game_Control::ManHinhCho(int height, int width) {
	int k = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (k < 10) {
				if (i == 0 || i % 6 == 0 || j == 0 || j % 10 == 0) {
					cout << "*";
				}
				else if (i % 3 == 0 && j % 5 == 0) {
					cout << k++;
				}
				else {
					cout << " ";
				}
			}
			else {
				if (i == 0 || i % 6 == 0 || j == 0 || j % 10 == 0) {
					cout << "*";
				}
				else if (i % 3 == 0 && j % 10 == 4) {
					cout << k++; j++;
				}
				else {
					cout << " ";
				}
			}

		}
		cout << endl;
	}
}
void Game_Control::VeBanCo(int height, int width, int size) {
	int viTri = 0, count = 0, player_1[50], player_2[50], count_1 = 0, count_2 = 0; player_1[0] = -1, player_2[0] = -1;
	for (int i = 0; i < lenght; i++) {
		if (i % 2 == 0) {
			player_1[count_1] = data[i];
			count_1++;
		}
		else {
			player_2[count_2] = data[i];
			count_2++;
		}
	}
	SapXep_MangCon(player_1, count_1);
	SapXep_MangCon(player_2, count_2);
	count_1 = 0, count_2 = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || i == 0 || i % 6 == 0 || j % 10 == 0) {
				cout << "*";
			}
			else if (i % 3 == 0 && j % 5 == 0) {
				if (viTri == player_1[count_1]) {
					cout << "\033[1;31mX\033[0m";
					count_1++;
				}
				else if (viTri == player_2[count_2]) {
					cout << "\033[1;34mO\033[0m";
					count_2++;
				}
				else {
					cout << viTri;
					if (viTri > 9) {
						j++;
					}
				}
				viTri++;
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}
int Game_Control::Tien_KetQua_3(int data_sub[], int lenght, int size) {
	int cheo_huyen, cheo_sac, doc, ngang;
	for (int i = 0; i < lenght; i++) {
		cheo_huyen = 0, cheo_sac = 0, doc = 0, ngang = 0;
		for (int j = 0; j < lenght; j++) {
			if (data_sub[i] == 4 || data_sub[i] == 4 - size || data_sub[i] == 4 - size + 2 || data_sub[i] == 4 + size - 2 || data_sub[i] == 4 + size) {
				if (data_sub[i] == data_sub[j] - 1 || data_sub[i] == data_sub[j] + 1) {
					ngang++;
					if ((data_sub[i] + 1) % size == 0 || data_sub[i] % size == 0) {
						ngang = 0;
					}
					if (ngang == 2) {
						return 1;
					}
				}
				else if (data_sub[i] == data_sub[j] - size || data_sub[i] == data_sub[j] + size) {
					doc++;
					if (doc == 2) {
						return 1;
					}
				}
				else if (data_sub[i] == data_sub[j] + size + 1 || data_sub[i] == data_sub[j] - size - 1) {
					cheo_huyen++;
					if (cheo_huyen == 2) {
						return 1;
					}
				}
				else if (data_sub[i] == data_sub[j] + size - 1 || data_sub[i] == data_sub[j] - size + 1) {
					cheo_sac++;
					if (data_sub[i] % 3 == 0 || data_sub[i] % 3 == 2) {
						cheo_sac = 0;
					}
					if (cheo_sac == 2) {
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
int Game_Control::Tien_KetQua(int data_sub[], int lenght, int size) {
	int cheo_huyen, cheo_sac, doc, ngang;
	for (int i = 0; i < lenght; i++) {
		cheo_huyen = 0, cheo_sac = 0, doc = 0, ngang = 0;
		for (int j = 0; j < lenght; j++) {
			if (data_sub[i] == data_sub[j] - 1 || data_sub[i] == data_sub[j] + 1 || data_sub[i] == data_sub[j] - 2 || data_sub[i] == data_sub[j] + 2) {
				ngang++;
				if ((data_sub[j] + 1) % size == 0) {
					if (ngang < 4) {
						ngang--;
					}
				}
				if (ngang == 4) {
					return 1;
				}
			}
			else if (data_sub[i] == data_sub[j] - size || data_sub[i] == data_sub[j] - size * 2 || data_sub[i] == data_sub[j] + size || data_sub[i] == data_sub[j] + size * 2) {
				doc++;
				if (doc == 4) {
					return 1;
				}
			}
			else if (data_sub[i] == data_sub[j] + (size + 1) * 2 || data_sub[i] == data_sub[j] + (size + 1) || data_sub[i] == data_sub[j] - (size + 1) * 2 || data_sub[i] == data_sub[j] - (size + 1)) {
				cheo_huyen++;
				if (cheo_huyen == 4) {
					return 1;
				}
			}
			else if (data_sub[i] == data_sub[j] + size * 2 - 2 || data_sub[i] == data_sub[j] + size - 1 || data_sub[i] == data_sub[j] - size + 1 || data_sub[i] == data_sub[j] - size * 2 + 2) {
				cheo_sac++;
				if (data_sub[j] % size == 0 || data_sub[i] % size == 0) {
					if (cheo_sac < 4) {
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
int Game_Control::KetQua(int size) {
	if (lenght < size * size) {
		int player_1[50], player_2[50], count_1 = 0, count_2 = 0; player_1[0] = -1, player_2[0] = -1;
		for (int i = 0; i < lenght; i++) {
			if (i % 2 == 0) {
				player_1[count_1] = data[i];
				count_1++;
			}
			else {
				player_2[count_2] = data[i];
				count_2++;
			}
		}
		SapXep_MangCon(player_1, count_1);
		SapXep_MangCon(player_2, count_2);
		if (size == 3) {
			if (Tien_KetQua_3(player_1, count_1, size) != 0) {
				return 1;
			}
			else if (Tien_KetQua_3(player_2, count_2, size) != 0) {
				return 2;
			}
			else {
				return 0;
			}
		}
		else {
			if (Tien_KetQua(player_1, count_1, size) != 0) {
				return 1;
			}
			else if (Tien_KetQua(player_2, count_2, size) != 0) {
				return 2;
			}
			else {
				return 0;
			}
		}

	}
	else {
		return 3;
	}
}
void Game_Control::GiaiPhong(Player* value[], int n) {
	for (int i = 0; i < n; i++) {
		delete value[i];
	}
}
void Game_Control::BroardSize(int size) {
	int i = 0, height = size * 5 + size + 1, width = size * 9 + size + 1;
	Player** p = new Player * [size * size];
	while (i < size*size) {
		if (i == 0) {
			ManHinhCho(height, width);
		}
		p[i] = new Player();
		if (i % 2 == 0) {
			cout << "\033[1;31mPlayer X\033[0m: ";
			p[i]->Nhap_DuLieu();
		}
		else {
			cout << "\033[1;34mPlayer O\033[0m: ";
			p[i]->Nhap_DuLieu();
		}
		Set(p, i + 1);
		if (!p[i]->kiemTra(p, i, p[i]->getLuotChoi(), size)) {
			ErrorMessage_2();
		}
		else {
			ClearScreen();
			VeBanCo(height, width, size);
			if (KetQua(size) == 1) {
				cout << "X la nguoi chien thang." << endl;
				break;
			}
			else if (KetQua(size) == 2) {
				cout << "O la nguoi chien thang." << endl;
				break;
			}
			else if (KetQua(size) == 3) {
				cout << "Ket qua hoa." << endl;
				break;
			}
			else {
				i++;
			}
		}
	}
	GiaiPhong(p, i);
}
// Ham toan cuc 
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
	int data_sub[] = { 0,5,10,15,20 }, lenght = 5, cheo_huyen, cheo_sac, doc, ngang;
	for (int i = 0; i < lenght - 3; i++) {
		cheo_huyen = 1, cheo_sac = 1, doc = 1, ngang = 1;
		for (int j = i + 1; j < lenght; j++) {
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
					cout << "flags: " << ngang << endl;
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
			if (data_sub[i] == data_sub[j] + (size + 1) * 2 || data_sub[i] == data_sub[j] + (size + 1) || data_sub[i] == data_sub[j] - (size + 1) * 2 || data_sub[i] == data_sub[j] - (size + 1)) {
				cheo_huyen++;
				if (cheo_huyen == 4) {
					return 1;
				}
			}
			// Tinh duong cheo dau sac
			if (data_sub[i] == data_sub[j] + size * 2 - 2 || data_sub[i] == data_sub[j] + size - 1 || data_sub[i] == data_sub[j] - size + 1 || data_sub[i] == data_sub[j] - size * 2 + 2) {
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

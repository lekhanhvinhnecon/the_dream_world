#include "Game_Control.h"
#include <iostream>
#include "TicTacToe.h"

using namespace std;

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
	GiaiPhong();
}
void Game_Control::GiaiPhong(Player* value[], int n) {
	for (int i = 0; i < n; i++) {
		delete value[i];
	}
}

#include "Player.h"
#include <iostream>
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
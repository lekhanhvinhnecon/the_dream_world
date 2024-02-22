#pragma once
class Player {
private:
	int luotChoi;
public:
	void Nhap_DuLieu();
	int getLuotChoi();
	bool kiemTra(Player* p[], int n, int key, int size);
};

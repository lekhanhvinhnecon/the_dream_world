#pragma once
#include "Player.h"
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


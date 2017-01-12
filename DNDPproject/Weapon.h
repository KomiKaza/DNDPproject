#pragma once
#include "Items.h"

class Weapon :public Items
{
public:
	Weapon(int Damage,CString name,int str,int dex,int hp,int def, int Int,bool enable);
	~Weapon();
	int getDMG();
private:
	int Damage;
};


#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon(int Damage,CString name,int str,int dex,int hp,int def, int Int,bool enable)
{
	setName(name);
	setSTR(str);
	setDEX(dex);
	setHP(hp);
	setDEF(def);
	setINT(Int);
	setEnable(false);
	Items::Items(name,str,dex,hp,def,Int,enable);
	Weapon::Damage=Damage;

}


Weapon::~Weapon(void)
{
}

int Weapon::getDMG()
{
	return Damage;
}
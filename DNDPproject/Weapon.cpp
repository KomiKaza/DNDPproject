#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon(CString name,int str,int dex,int hp,int def, int Int,bool enable)
{
	Weapon::name=name;
	Weapon::enable=enable;
	addSTR=str;
	addDEX=dex;
	addHP=hp;
	addDEF=def;
	addINT=Int;
}


Weapon::~Weapon(void)
{
}
CString Weapon::getName()
{
	return name;
}

bool Weapon::getEnable()
{
	return enable;
}

	int Weapon::getStr()
	{
		return addSTR;
	}

	int Weapon::getDex()
	{
		return addDEX;
	}

	int Weapon::getHp()
	{
		return addHP;
	}

	int Weapon::getDef()
	{
		return addDEF;
	}

	int Weapon::getInt()
	{
		return addINT;
	}

	void Weapon::setEnable(bool enable)
	{
		Weapon::enable=enable;
	}
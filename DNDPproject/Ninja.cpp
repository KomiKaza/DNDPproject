#include "stdafx.h"
#include "Ninja.h"


Ninja::Ninja()
{
	setDef(3);
	setDex(6);
	setInt(2);
	setHp(12);
	setStr(3);
}


Ninja::~Ninja()
{
}

int Ninja::DMG()
{
	return 0;
}

void Ninja::Attack(Monster * enemy)
{

}

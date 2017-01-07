#include "stdafx.h"

#include "Fairy.h"


Fairy::Fairy()
{
	setDef(3);
	setDex(2);
	setInt(3);
	setHp(16);
	setStr(2);
	Magic=1;
}


Fairy::~Fairy()
{
}

int Fairy::DMG()
{
	return getInt() *getDex()+ getStr();
}

void Fairy::Attack(Monster * enemy)
{
	int total=enemy->getHP() -DMG()*(enemy->getTotal() )-Magic;
	enemy->setHP(total);
}





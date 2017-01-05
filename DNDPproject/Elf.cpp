#include "stdafx.h"
#include "Elf.h"


Elf::Elf()
{
	setDef(3);
	setDex(3);
	setInt(6);
	setHp(14);
	setStr(2);
}


Elf::~Elf()
{
}

int Elf::DMG()
{
	return 0;
}

void Elf::Attack(Monster * enemy)
{

}
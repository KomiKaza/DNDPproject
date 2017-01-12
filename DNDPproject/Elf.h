#pragma once
#include "character.h"
class Elf :
	public Character
{
public:
	Elf();
	~Elf();
	int Attack(Monster * enemy,int WeID);
	int DMG();
	CString getStory();
};


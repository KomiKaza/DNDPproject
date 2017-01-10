#pragma once
#include "character.h"
class Elf :
	public Character
{
public:
	Elf();
	~Elf();
	void Attack(Monster * enemy);
	int DMG();
	CString getStory();
};


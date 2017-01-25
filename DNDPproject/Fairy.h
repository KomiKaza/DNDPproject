#pragma once
#include "MagicCharacter.h"
class Fairy :
	public MagicCharacter
{
public:
	Fairy();
	~Fairy();
	int Attack(Monster * enemy,int WeID);
	int DMG();
	CString getStory();
};


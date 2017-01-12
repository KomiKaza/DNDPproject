#pragma once
#include "Character.h"
class Ninja :
	public Character
{
public:
	Ninja();
	~Ninja();
	int Attack(Monster * enemy,int WeID);
	int DMG();
	CString getStory();
};


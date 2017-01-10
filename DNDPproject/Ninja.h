#pragma once
#include "Character.h"
class Ninja :
	public Character
{
public:
	Ninja();
	~Ninja();
	void Attack(Monster * enemy);
	int DMG();
	CString getStory();
};


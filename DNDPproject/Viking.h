#pragma once
#include "Character.h"
class Viking :
	public Character
{
public:
	Viking();
	~Viking();
	void Attack(Monster * enemy);
	int DMG();
};


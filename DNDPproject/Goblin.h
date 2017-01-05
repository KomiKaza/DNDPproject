#pragma once
#include "monster.h"
class Goblin :
	public Monster
{
public:
	Goblin();
	~Goblin(void);
	void Attack(Character * player);
	int getTotal() ;
};


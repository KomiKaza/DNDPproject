#pragma once
#include "monster.h"
class Goblin :
	public Monster
{
public:
	Goblin();
	~Goblin(void);
	int Attack(Character * player);
	int getTotal() ;
};


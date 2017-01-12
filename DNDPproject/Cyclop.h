#pragma once
#include "monster.h"
class Cyclop :
	public Monster
{
public:
	Cyclop(void);
	~Cyclop(void);
	int Attack(Character * player);
	 int getTotal();
};


#pragma once
#include "Monster.h"
class Dragon :
	public Monster
{
public:
	Dragon();
	~Dragon(void);
	int Attack(Character * player);
	int getTotal() ;
};


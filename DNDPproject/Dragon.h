#pragma once
#include "Monster.h"
class Dragon :
	public Monster
{
public:
	Dragon();
	~Dragon(void);
	void Attack(Character * player);
	int getTotal() ;
};


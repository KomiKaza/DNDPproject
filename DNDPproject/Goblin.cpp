#include "stdafx.h"
#include "Goblin.h"
#include "Character.h"

Goblin::Goblin(void)
{
	setAT(12);setDEF(4); setQK(2); setHP(10);
}



Goblin::~Goblin(void)
{
}

int Goblin::Attack(Character * player)
{
	double r=(rand()%180)/100 +0.5;
	int m= (getTotal()*r )-5*player->getDef() ;
	if(m<1)
		m=1;

	player->setHp(player->getHP() -m);
		return m;
}
int Goblin::getTotal()
{
	return (getAT()*getQK());
}

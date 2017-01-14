#include "stdafx.h"
#include "Cyclop.h"
#include "Character.h"

Cyclop::Cyclop(void)
{
		setAT(5);setDEF(9); setQK(2); setHP(150);

}


Cyclop::~Cyclop(void)
{
}

int Cyclop::Attack(Character * player)
{
	int m= (getTotal() )-7*player->getDef() ;
	if(m<1)
		m=0;

	player->setHp(player->getHP() -m);
		return m;
}
int Cyclop::getTotal()
{
	return (getAT()*getQK());
}

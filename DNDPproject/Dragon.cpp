#include "stdafx.h"
#include "Dragon.h"
#include "Character.h"

Dragon::Dragon(void)
{
	setAT(10);
	setDEF(6); 
	setQK(5); 
	setHP(200);
}


Dragon::~Dragon(void)
{
}

int Dragon::Attack(Character * player)
{
	int m= (getTotal() )-6*player->getDef() ;
	if(m<1)
		m=0;

	player->setHp(player->getHP() -m);
		return m;
}
int Dragon::getTotal()
{
	return (getAT()*getQK());
}

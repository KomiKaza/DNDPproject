#include "stdafx.h"
#include "Dragon.h"


Dragon::Dragon(void)
{
	setAT(20);
	setDEF(10); 
	setQK(5); 
	setHP(20);
}


Dragon::~Dragon(void)
{
}

void Dragon::Attack(Character * player)
{
}

int Dragon::getTotal() 
{
	return 0;
}
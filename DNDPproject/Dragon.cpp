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

int Dragon::Attack(Character * player)
{
	return 2;
}

int Dragon::getTotal() 
{
	return 0;
}
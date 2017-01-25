#include "stdafx.h"

#include "Fairy.h"


Fairy::Fairy()
{
	setDef(3);
	setDex(2);
	setInt(3);
	setHp(16);
	setStr(2);
	setMagic(1);
	setLoc(4,9);
	setWeapon0(new Weapon(0,L"White Magic",0,5,0,0,10,false)); //
	setWeapon1(new Weapon(0,L"Armour Magic",0,0,0,10,0,false));//
	setWeapon2(new Weapon(0,L"Heal Magic",0,0,2,0,0,false)); //
}


Fairy::~Fairy()
{
}

int Fairy::DMG()
{
	return getInt() *getDex();
}

int Fairy::Attack(Monster * enemy,int WeID)
{
	int total;
	switch(WeID)
	{
	case 0:
	total=DMG()-enemy->getDEF();
	if(total<1)
		total=0;
	enemy->setHP(enemy->getHP()-total-getMagic());
	return total;
	break;
	case 1:
		total=DMG()+getWeapon0()->getDex()*getWeapon0()->getInt()*0.55-enemy->getDEF();
	if(total<1)
		total=0;
	enemy->setHP(enemy->getHP()-total-getMagic());
	return total;
	break;
	case 2:
		setDef(getDef()+0.5*getWeapon0()->getInt());
		break;
	case 3:
		setHp(getHP()+0.25*getWeapon2()->getInt()+getWeapon2()->getHp());
		break;
	}
	return 0;
}

CString Fairy::getStory()
{
		setStoryBegin(L"Wow, look at those shiny wings!\r\n");
		setStoryBegin(getStoryBegin()+L"You woke up as ");
		setStoryBegin(getStoryBegin()+getName());
		setStoryBegin(getStoryBegin()+L" the fairy\r\n in the Goblin Valley!\r\n");
		setStoryBegin(getStoryBegin()+L"Although it looks like the most peaceful place \r\n on earth,\r\n");
		setStoryBegin(getStoryBegin()+L"filled with evergreen trees and fluffy clouds,\r\n ");
		setStoryBegin(getStoryBegin()+L"the most cruel creatures \r\n");
		setStoryBegin(getStoryBegin()+L"- THE GOBLINS - \r\n");
		setStoryBegin(getStoryBegin()+L"live here and they are ruining others lives!\r\n");
		setStoryBegin(getStoryBegin()+L"They stole the Barbie house of the princess of\r\n");
		setStoryBegin(getStoryBegin()+L"the valley and she won't stop crying!\r\n Help her find it.\r\n");
		return getStoryBegin();

}




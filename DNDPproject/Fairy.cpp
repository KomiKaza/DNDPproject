#include "stdafx.h"

#include "Fairy.h"


Fairy::Fairy()
{
	setDef(3);
	setDex(2);
	setInt(3);
	setHp(16);
	setStr(2);
	Magic=1;
	setLoc(4,9);
	setWeapon0(new Weapon(L"White Magic",0,5,0,0,10,false)); //
	setWeapon1(new Weapon(L"Armour Magic",0,0,0,10,0,false));//
	setWeapon2(new Weapon(L"Heal Magic",0,0,2,0,0,false)); //
}


Fairy::~Fairy()
{
}

int Fairy::DMG()
{
	return getInt() *getDex()+ getStr();
}

void Fairy::Attack(Monster * enemy)
{
	int total=enemy->getHP() -DMG()*(enemy->getTotal() )-Magic;
	enemy->setHP(total);
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




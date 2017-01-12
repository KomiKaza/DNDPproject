#include "stdafx.h"
#include "Viking.h"


Viking::Viking()
{
	setDef(3);
	setDex(2);
	setInt(2);
	setHp(13);
	setStr(6);
	setLoc(0,4);
	setWeapon0(new Weapon(2,L"Spear",7,0,0,0,0,false)); //
	setWeapon1(new Weapon(5,L"Sword",9,4,0,0,0,false));  //
	setWeapon2(new Weapon(9,L"Axe",14,4,0,0,0,false));  //
}


Viking::~Viking()
{
}

int Viking::DMG()
{
	return getStr()*getDex();
}

int Viking::Attack(Monster * enemy,int WeID)
{
	int total;
		switch(WeID)
	{
	case 0:
	total=DMG()-enemy->getDEF();
	if(total<1)
		total=0;
	enemy->setHP(enemy->getHP()-total);
	break;

	case 1:
		total=DMG()+getWeapon0()->getDMG()-enemy->getDEF();
	if(total<1)
		total=0;
	enemy->setHP(enemy->getHP()-total);
	break;

	case 2:
	total=DMG()+getWeapon1()->getDMG()-enemy->getDEF();
	if(total<1)
		total=0;
	enemy->setHP(enemy->getHP()-total);
	break;

	case 3:
	total=DMG()+getWeapon2()->getDMG()-enemy->getDEF();
	if(total<1)
		total=0;
	enemy->setHP(enemy->getHP()-total);
	break;
	}
return total;
}

CString Viking::getStory()
{
		setStoryBegin(L"Look at those muscles!\r\n");
		setStoryBegin(getStoryBegin()+L"You woke up as ");
		setStoryBegin(getStoryBegin()+getName());
		setStoryBegin(getStoryBegin()+L" the Viking!\r\n");
		setStoryBegin(getStoryBegin()+L"There's a storm and you are on an ancient ship.\r\n");
		setStoryBegin(getStoryBegin()+L"You just landed on a long shore.\r\n");
		setStoryBegin(getStoryBegin()+L"A pigeon lands on your shoulder and you \r\n");
		setStoryBegin(getStoryBegin()+L"receive a letter that informs you that there's \r\n");
		setStoryBegin(getStoryBegin()+L"a treasure box in the middle of the desert!\r\n");
		setStoryBegin(getStoryBegin()+L"As you are a greedy person,\r\n");
		setStoryBegin(getStoryBegin()+L"you have to find that box!\r\n");
		return getStoryBegin();
}



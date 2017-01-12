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
	setWeapon0(new Weapon(0,L"Spear",7,0,0,0,0,false)); //
	setWeapon1(new Weapon(0,L"Sword",9,4,0,0,0,false));  //
	setWeapon2(new Weapon(0,L"Axe",14,4,0,0,0,false));  //
}


Viking::~Viking()
{
}

int Viking::DMG()
{
	return 0;
}

int Viking::Attack(Monster * enemy,int WeID)
{
	return 0;
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



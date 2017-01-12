#include "stdafx.h"
#include "Ninja.h"


Ninja::Ninja()
{
	setDef(3);
	setDex(6);
	setInt(2);
	setHp(12);
	setStr(3);
	setLoc(5,0);
	setWeapon0(new Weapon(1,L"Shurikan",2,6,0,0,0,false));  //
	setWeapon1(new Weapon(2,L"Nunchaka",4,8,0,0,0,false)); //
	setWeapon2(new Weapon(8,L"Katana",11,11,0,0,0,false)); //
}


Ninja::~Ninja()
{
}

int Ninja::DMG()
{
	return getDex()*getStr();
}

int Ninja::Attack(Monster * enemy,int WeID)
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

CString Ninja::getStory()
{

		setStoryBegin(L"Hello ");
		setStoryBegin(getStoryBegin()+getName());
		setStoryBegin(getStoryBegin()+L",\r\n");
		setStoryBegin(getStoryBegin()+L"we are honored to inform you that you are\r\n");
		setStoryBegin(getStoryBegin()+L"the greatest ninja on earth! You're sitting in a\r\n");
		setStoryBegin(getStoryBegin()+L"beautiful ancient temple, drink your\r\n protein shake,\r\n");
		setStoryBegin(getStoryBegin()+L"watching the cherry trees bloom outside\r\n the window,\r\n");
		setStoryBegin(getStoryBegin()+L"when suddenly you hear that your beloved \r\n teacher\r\n");
		setStoryBegin(getStoryBegin()+L"Master Splinter is fighting the evils and needs\r\n");
		setStoryBegin(getStoryBegin()+L"your assistance! He informs you that he's\r\n");
		setStoryBegin(getStoryBegin()+L"in a middle of a desert,\r\n");
		setStoryBegin(getStoryBegin()+L"go and find him!\r\n");
		return getStoryBegin();
}
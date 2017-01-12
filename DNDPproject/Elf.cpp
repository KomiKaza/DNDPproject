#include "stdafx.h"
#include "Elf.h"


Elf::Elf()
{
	setDef(3);
	setDex(3);
	setInt(6);
	setHp(14);
	setStr(2);
	setLoc(9,4);
	setWeapon0(new Weapon(4,L"Dagger",4,4,0,0,0,false)); //
	setWeapon1(new Weapon(5,L"Sword",6,6,0,0,0,false)); //
	setWeapon2(new Weapon(6,L"Long Bow",8,12,0,0,0,false));  //
}


Elf::~Elf()
{
}

int Elf::DMG()
{
	return getDex()*getStr() -1 +getInt()/3;
}

int Elf::Attack(Monster * enemy,int WeID)
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

CString Elf::getStory()
{
		setStoryBegin(L" Lucky you, you woke up as ");
		setStoryBegin(getStoryBegin()+getName());
		setStoryBegin(getStoryBegin()+L" the elf\r\n");
		setStoryBegin(getStoryBegin()+L"in a flying castle! This is the place where\r\n");
		setStoryBegin(getStoryBegin()+L"magic happens and doors are  opened \r\n when you say ");
		setStoryBegin(getStoryBegin()+L"Alohomora.\r\n But life cannot be perfect and your\r\n");
		setStoryBegin(getStoryBegin()+L"little elf sister got kidnapped! \r\n");
		setStoryBegin(getStoryBegin()+L"As a  responsible brother you\r\n");
		setStoryBegin(getStoryBegin()+L"should find her!\r\n");
		return getStoryBegin();

}
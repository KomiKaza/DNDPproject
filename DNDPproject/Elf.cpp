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
	setWeapon0(new Weapon(L"Dagger",4,4,0,0,0,false)); //
	setWeapon1(new Weapon(L"Sword",6,6,0,0,0,false)); //
	setWeapon2(new Weapon(L"Long Bow",8,12,0,0,0,false));  //
}


Elf::~Elf()
{
}

int Elf::DMG()
{
	return 0;
}

void Elf::Attack(Monster * enemy)
{

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
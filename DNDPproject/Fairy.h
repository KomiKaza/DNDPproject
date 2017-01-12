#pragma once
#include "character.h"
class Fairy :
	public Character
{
public:
	Fairy();
	~Fairy();
	int Attack(Monster * enemy,int WeID);
	int DMG();
	int getMagic() {return Magic;};
	CString getStory();
private:
	int Magic;
};


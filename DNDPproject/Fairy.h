#pragma once
#include "character.h"
class Fairy :
	public Character
{
public:
	Fairy();
	~Fairy();
	void Attack(Monster * enemy);
	int DMG();
	int getMagic() {return Magic;};
	CString getStory();
private:
	int Magic;
};


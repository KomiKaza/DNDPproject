#pragma once
#include "Character.h"
class MagicCharacter :
	public Character
{
public:
	MagicCharacter(){};
	virtual ~MagicCharacter() {};
	virtual int Attack(Monster * enemy,int WeID) =0; //need to create Monster first...
	virtual int DMG()  =0;//damage of each character
	virtual CString getStory()=0;
	int getMagic() { return Magic;}
	void setMagic(int magic){Magic=magic;};
	private:
	int Magic;
};


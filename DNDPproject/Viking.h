#pragma once
#include "Character.h"
class Viking :
	public Character
{
public:
	Viking();
	~Viking();
	int Attack(Monster * enemy,int WeID);
	int DMG();
	CString getStory();
};


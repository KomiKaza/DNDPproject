#pragma once
#include "Character.h"

class CharacterFactory
{
public:
	CharacterFactory(void){};
	~CharacterFactory(void){};
	virtual Character * createCharacter()=0;
};


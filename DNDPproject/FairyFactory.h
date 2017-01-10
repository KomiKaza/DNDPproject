#pragma once
#include "characterfactory.h"
#include "Fairy.h"

class FairyFactory :
	public CharacterFactory
{
public:
	~FairyFactory(void){};
	Character * createCharacter() { return new Fairy(); };
	static FairyFactory* getInstance() {
	static FairyFactory* instance = new FairyFactory();
		return instance;
	}
private:
	FairyFactory(){};
};


#pragma once
#include "characterfactory.h"
#include "Ninja.h"
class NinjaFactory :
	public CharacterFactory
{
public:
	~NinjaFactory(void){};
	Character * createCharacter() { return new Ninja(); }
	static NinjaFactory* getInstance() {
	static NinjaFactory* instance = new NinjaFactory();
		return instance;
	}
private:
	NinjaFactory(){};
};




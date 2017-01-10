#pragma once
#include "characterfactory.h"
#include "Viking.h"
class VikingFactory :
	public CharacterFactory
{
public:
	~VikingFactory(void){};
	Character * createCharacter() { return new Viking(); }
	static VikingFactory* getInstance() {
	static VikingFactory* instance = new VikingFactory();
		return instance;
	}
private:
	VikingFactory(){};
};


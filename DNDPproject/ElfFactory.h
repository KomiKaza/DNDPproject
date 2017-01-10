#pragma once
#include "characterfactory.h"
#include "Elf.h"
class ElfFactory :
	public CharacterFactory
{
public:
	~ElfFactory(void){};
	Character * createCharacter() { return new Elf(); }
	static ElfFactory* getInstance() {
	static ElfFactory* instance = new ElfFactory();
		return instance;
	}
private:
	ElfFactory(){};
};


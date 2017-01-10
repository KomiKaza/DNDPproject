#pragma once
#include <iostream>
#include "Monster.h"
#include "Weapon.h"
#include "StdAfx.h"
using namespace std;


class Character 
{
public:
	Character() {foodAmount=0; charName=""; StoryBegin="";};
	virtual ~Character() {};
	int getStr() {return STR;};
	int getDex() {return DEX;};
	int getHP() {return HP;};
	int getDef() {return DEF;};
	int getInt() {return INT;};
	int getFood() {return foodAmount;};
	CString getName() {return charName;};
	CString getStoryBegin() {return StoryBegin;};
	int getX() {return Location->x;};
	int getY() {return Location->y;};
	Weapon * getWeapon0() {return Weapon0;};
	Weapon * getWeapon1() {return Weapon1;};
	Weapon * getWeapon2() {return Weapon2;};
	void setWeapon0(Weapon * weapon){Weapon0=weapon;};
	void setWeapon1(Weapon * weapon){Weapon1=weapon;};
	void setWeapon2(Weapon * weapon){Weapon2=weapon;};
	void setFood(int foodAmount) {Character::foodAmount=foodAmount;};
	void setDex(int DEX) {Character::DEX=DEX;};
	void setInt(int INT) {Character::INT=INT;};
	void setStr(int STR) {Character::STR=STR;};
	void setHp(int HP) {Character::HP=HP;};
	void setDef(int DEF) {Character::DEF=DEF;};
	void setLoc(int x,int y){Location=new CPoint(x,y);};
	void setLocX(int x){Location->x=x;};
	void setLocY(int y){Location->y=y;};
	void setName(CString charName) {Character::charName=CString(_T("")); Character::charName=charName; };
	void setStoryBegin(CString story) {StoryBegin=story; };
	void goEast(){Location->x++;};
	void goWest(){Location->x--;};
	void goNorth(){Location->y++;};
	void goSouth(){Location->y--;};
	virtual void Attack(Monster * enemy) =0; //need to create Monster first...
	virtual int DMG()  =0;//damage of each character
	virtual CString getStory()=0;
	 CString getWeaponsST()
	{
		CString story;
		if(Weapon0->getEnable() ||Weapon1->getEnable() ||Weapon2->getEnable() )
		{
		story="Weapons: \r\n";
		if(Weapon0->getEnable())
		story+=Weapon0->getName();
		story+="\r\n";	
		if(Weapon1->getEnable())
		story+=Weapon1->getName();
		story+="\r\n";
		if(Weapon2->getEnable())
		story+=Weapon2->getName();
		story+="\r\n";
		}
		return story;
	}
	 //void Serialize(CArchive& archive)
	 //{
		//     CObject::Serialize( archive );

  //  // now do the stuff for our specific class
  //  if(archive.IsStoring())
		//archive << STR<<DEX<<HP<<DEF<<INT<<charName;
  //  else
  //      archive >> STR>>DEX>>HP>>DEF>>INT>>charName;
	 //} ;

private:
	int STR;
	int DEX;
	int HP;
	int DEF;
	int INT;
	CString charName,StoryBegin;
	int foodAmount;
	CPoint * Location;
	Weapon * Weapon0,* Weapon1,* Weapon2;
};
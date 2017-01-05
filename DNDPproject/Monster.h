#pragma once
#include <iostream>
using namespace std;

class Character;
class Monster {
public:
	Monster() {ATTACK=10; DEFFENCE=8; QUICK=4; HP=20;};
	virtual ~Monster(){};
	virtual void Attack(Character * player) {};
	void setHP(int HP) {Monster::HP=HP; };
	void setDEF(int DEFFENCE) {Monster::DEFFENCE=DEFFENCE; };
	void setQK(int QUICK) {Monster::QUICK=QUICK; };
	void setAT(int ATTACK) {Monster::ATTACK=ATTACK; };
	int getHP() {return HP; };
	int getAT() {return ATTACK; };
	int getDEF() {return DEFFENCE; };
	int getQK() {return QUICK; };
	virtual int getTotal() {return (100-DEFFENCE*QUICK)/100;};

private:
	int ATTACK;
	int DEFFENCE;
	int QUICK;
	int HP;
};
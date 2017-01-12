#include "stdafx.h"
#include "Items.h"


Items::Items(CString name,int str,int dex,int hp,int def, int Int,bool enable)
{
	Items::name=name;
	Items::enable=enable;
	addSTR=str;
	addDEX=dex;
	addHP=hp;
	addDEF=def;
	addINT=Int;
}
Items::Items()
{
	name="";
	enable=false;
	addSTR=0;
	addDEX=0;
	addHP=0;
	addDEF=0;
	addINT=0;
}


Items::~Items(void)
{
}
CString Items::getName()
{
	return name;
}

bool Items::getEnable()
{
	return enable;
}

	int Items::getStr()
	{
		return addSTR;
	}

	int Items::getDex()
	{
		return addDEX;
	}

	int Items::getHp()
	{
		return addHP;
	}

	int Items::getDef()
	{
		return addDEF;
	}

	int Items::getInt()
	{
		return addINT;
	}

	void Items::setEnable(bool enable)
	{
		Items::enable=enable;
	}

		void Items::setName(CString name)
	{
		Items::name=name;
	}

			void Items::setSTR(int str)
	{
		Items::addSTR=str;
	}

				void Items::setDEX(int dex)
	{
		Items::addDEX=dex;
	}



			void Items::setHP(int hp)
	{
		Items::addHP=hp;
	}

			void Items::setDEF(int def)
	{
		Items::addDEF=def;
	}

			void Items::setINT(int Int)
	{
		Items::addINT=Int;
	}

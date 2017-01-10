#pragma once
class Weapon
{
public:
	Weapon(CString name,int str,int dex,int hp,int def, int Int,bool enable);
	~Weapon();
	CString getName();
	int getStr();
	int getDex();
	int getHp();
	int getDef();
	int getInt();
	bool getEnable();
	void setEnable(bool enable);

private:
	CString name;
	int addSTR;
	int addDEX;
	int addHP;
	int addDEF;
	int addINT;
	bool enable;
};


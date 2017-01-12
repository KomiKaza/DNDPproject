#pragma once
class Items
{
public:
	Items(CString name,int str,int dex,int hp,int def, int Int,bool enable);
	Items();
	~Items(void);
	CString getName();
	int getStr();
	int getDex();
	int getHp();
	int getDef();
	int getInt();
	bool getEnable();
	void setEnable(bool enable);
	void setName(CString name);
	void setSTR(int str);
	void setDEX(int dex);
	void setHP(int hp);
	void setDEF(int def);
	void setINT(int Int);
	private:
	CString name;
	int addSTR;
	int addDEX;
	int addHP;
	int addDEF;
	int addINT;
	bool enable;
};


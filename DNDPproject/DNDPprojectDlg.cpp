/*
#########################################################################  Final Project ################################################################################################
This program was created and designed by:
Shahaf Wagner -  204559272
Victoria Shakaley - 311292437
Lecturer: Doctor Michael Kiperberg
*/

// DNDPprojectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DNDPproject.h"
#include "DNDPprojectDlg.h"
#include "afxdialogex.h"
#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <iomanip>
#pragma comment( lib, "Winmm.lib" )





#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void InitializeGlobals();

// CAboutDlg dialog used for App About

//intalize variables
CString name=CString(_T(""));
CString msg=CString(_T("")); 
CString SDialog=CString(_T("")); 
bool newName=false;
int ClassSelect=0;
Character * me;
CPoint * Location;
int MsgAns;
int WeID=0,damage,backDamaged;
bool monster[10];
bool Restart=false; //check if we just restarted the game
bool * foods=new bool[6];
bool * activeEnemy=new bool[6];
Monster * enemy;
CString monName;
int battleid;
bool afterBattle=false;
bool west=false,east=false,north=false,south=false;

//end intalize

class CAboutDlg : public CDialogEx
{ 
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};



CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDNDPprojectDlg dialog

void CDNDPprojectDlg::Battle(int monstertype)
{
	CString battleLog;
	switch(monstertype)
	{
	case 0:
		CEast.EnableWindow(true);east=true;
		CWest.EnableWindow(true); west=true;
		CNorth.EnableWindow(true);north=true;
		CSouth.EnableWindow(true);south=true;
		break;
	case 1:
		CEast.EnableWindow(true);east=true;
		CWest.EnableWindow(true); west=true;
		CNorth.EnableWindow(true);north=true;
		CSouth.EnableWindow(true);south=true;
		break;
	case 2:
		CEast.EnableWindow(true);east=true;
		CWest.EnableWindow(true); west=true;
		CNorth.EnableWindow(true);north=false;
		CSouth.EnableWindow(true);south=true;
		break;
	case 3:
		CEast.EnableWindow(true);east=true;
		CWest.EnableWindow(true); west=true;
		CNorth.EnableWindow(true);north=true;
		CSouth.EnableWindow(true);south=true;
		break;
	case 4:
		CEast.EnableWindow(true);east=true;
		CWest.EnableWindow(true); west=true;
		CNorth.EnableWindow(true);north=true;
		CSouth.EnableWindow(true);south=false;
		break;
	case 5:
		CEast.EnableWindow(true);east=false;
		CWest.EnableWindow(true); west=true;
		CNorth.EnableWindow(true);north=true;
		CSouth.EnableWindow(true);south=true;
		break;
	}
	//now add the battle...
	//while(enemy->getHP() >0 && me->getHP() >0)
	//{
	//	//do action
	//}
}


void CDNDPprojectDlg::checkLocation()
{
	CBitmap CenterPix;//creating bitmap
	SDialog="";
	CString Temp,Temp0,a;
	switch((me->getX())*10 +(me->getY()))
	{
	case 0:
		if (me->getWeapon0()->getName()=="White Magic" && !me->getWeapon2()->getEnable())
		{
		SDialog="You found a book that gives \r\nyou the ability to use Heal Magic";
		me->getWeapon2()->setEnable(true);
		RBow.EnableWindow(true);
				Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		}
		else
{		
	SDialog="You are in a neighborhood of the local\r\n residents. ";
		CenterPix.LoadBitmapW(BIT_0);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
				}
		break;

	case 1:
		SDialog="You are in a neighborhood of the local \r\n residents. ";
		CenterPix.LoadBitmapW(ID01);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		break;
	case 2:
		SDialog="Oh no, a storm is hitting the beach!\r\n Consider if you want to continue via\r\n the beach,  or you wan to go to \r\n rice fields which are in the east  \r\n direction.";
		CenterPix.LoadBitmapW(ID02);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		break;

	case 3:
		CenterPix.LoadBitmapW(ID03);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You are at the beach. You can hear the \r\n Vikings partying hard on their ships!";
		break;

	case 4:
		SDialog="You are sorrounded by beautiful palm tress,\r\n although the sky gets darker.";
		CenterPix.LoadBitmapW(BIT_PIRATE);//load image
       pView.SetBitmap(CenterPix );//post image
		break;

	case 5:
		SDialog="A sharp noise is frightening you!\r\n Its a branch that was cracked by the wind.\r\n You can consider to continue to the north-\r\n maybe the weather is not so \r\n crazy there!";
		CenterPix.LoadBitmapW(BIT_5);//load image
       pView.SetBitmap(CenterPix );//post image
		break;

	case 6:
		SDialog="A pastoral view is sottounding you.\r\n Theres a calm wind.";
		CenterPix.LoadBitmapW(BIT_6);//load image
       pView.SetBitmap(CenterPix );//post image
		break;

	case 7:
		SDialog="Be careful - theres a river in the north\r\n direction!";
		CenterPix.LoadBitmapW(BIT_7);//load image
       pView.SetBitmap(CenterPix );//post image
		break;

	case 8:
		CenterPix.LoadBitmapW(ID0809);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="Oh no, youre drawning in the river!\r\n Go to the south or the east direction\r\n as soon as you can! ";
		break;

	case 9:
		CenterPix.LoadBitmapW(ID0809);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
SDialog="Oh no, youre drawning in the river!\r\n Go to the south or the east direction\r\n as soon as you can! ";
break;

	case 10:
		CenterPix.LoadBitmapW(ID0010);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You are in a neighborhood of the local\r\n residents. ";
		break;

	case 11:
		CenterPix.LoadBitmapW(ID1121);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="Intersection!\r\n You are in the borderline ofa small village,\r\n the beach and beautiful rice field.\r\n Let your intuiotion lead you.";
		break;

	case 12:
		if (me->getWeapon0()->getName()=="Spear" && !me->getWeapon0()->getEnable())
		{
		SDialog="You found a Spear ";
		me->getWeapon0()->setEnable(true);
		RWand.EnableWindow(true);
		}
		else if(me->getWeapon0()->getName()=="Dagger" && !me->getWeapon2()->getEnable())
		{
		SDialog="You found a Long Bow";
		me->getWeapon2()->setEnable(true);
		RBow.EnableWindow(true);
		}
		else
		{
			SDialog="Skys getting cloudy";
			CenterPix.LoadBitmapW(ID1222);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
			}

				Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		break;

	case 13:
		SDialog="The storm is getting stronger!\r\n Find a safe place.";
		CenterPix.LoadBitmapW(ID1323);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		break;	

	case 14:
		CenterPix.LoadBitmapW(ID1424);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You are in the borderline\r\n between the village and the beach.";
		break;	

	case 15:
		CenterPix.LoadBitmapW(ID1516);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You see the beach in the west\r\n direction- \r\n did you bring your swimsuit?";
		break;

	case 16:
		CenterPix.LoadBitmapW(ID1516);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You see the beach in the west\r\n direction- \r\n did you bring your swimsuit?";
		break;

	case 17:
		SDialog="A strange noise comes from \r\n the east direction- \r\ncheck what is it!";
		CenterPix.LoadBitmapW(ID17);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		break;

	case 18:
		if(me->getWeapon0()->getName()=="Dagger")
		{
			SDialog="You found your elf sister!!! \r\n Good job! \r\n you have won the game!";
			CenterPix.LoadBitmapW(IDElfsister);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
			DoEvents();
			gameOver(1);
		}
		else
		{
		SDialog="Although the view is fantastic,\r\n theres a dangerous river in the\r\n west diretion! Be careful.";
		CenterPix.LoadBitmapW(ID1819);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		break;

	case 19:
		if (me->getWeapon0()->getName()=="Shurikan" && !me->getWeapon1()->getEnable())
		{
			CenterPix.LoadBitmapW(IDNunchaka);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You found a Nunchaka!";
		me->getWeapon1()->setEnable(true);
		RSword.EnableWindow(true);
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		}
		else
		{
		SDialog="Although the view is fantastic,\r\n theres a dangerous river in the\r\n west diretion! Be careful.";
		CenterPix.LoadBitmapW(ID1819);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		break;

	case 20:
		CenterPix.LoadBitmapW(ID20);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You see some houses on the horizon.";
		break;

	case 21:
		CenterPix.LoadBitmapW(ID1121);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="Intersection!\r\n You are in the borderline ofa small village,\r\n the beach and beautiful rice field.\r\n Let your intuiotion lead you.";
		break;

	case 22:
		CenterPix.LoadBitmapW(ID22);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You see something shining in \r\n the west direction- Go there!";
		break;

	case 23:
		CenterPix.LoadBitmapW(ID1323);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="The storm is getting stronger!\r\n Find a safe place.";
		break;	

	case 24:
		CenterPix.LoadBitmapW(ID1424);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You are in the borderline\r\n between the village and the beach.";
		break;	

	case 25:
		SDialog="Any direction you will choose\r\n will bring you to a new \r\nadventure!";
		break;

	case 26:
		SDialog="A strange noise comes from\r\n the north direction- \r\ncheck what is it!";
		break;

	case 27:
		if(activeEnemy[0])
		{
	PlaySound(L"Sound/giant.wav",NULL,SND_FILENAME|SND_ASYNC); 
		DoEvents();
		SDialog="You are facing the evil goblin\r\n now!\r\n Show him what you've got!";
		enemy=new Goblin();
		monName="Goblin";
		gameOver(2);
		activeEnemy[0]=false;
		battleid=0;
		afterBattle=true;
		CenterPix.LoadBitmapW(IDGOBLIN);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		else
		{
		SDialog="There is a dead Goblin body in here.";	
		CenterPix.LoadBitmapW(IDDeadgo);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		break;

	case 28:
		if(activeEnemy[1])
		{
	PlaySound(L"Sound/giant.wav",NULL,SND_FILENAME|SND_ASYNC); 
		DoEvents();
		SDialog="You are facing the evil goblin\r\n now!\r\n Show him what you've got!";
		enemy=new Goblin();
		monName="Goblin";
		gameOver(2);
		activeEnemy[1]=false;
		battleid=1;
		afterBattle=true;
		CenterPix.LoadBitmapW(IDGOBLIN);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		else
		{
		SDialog="There is a dead Goblin body in here.";	
		CenterPix.LoadBitmapW(IDDeadgo);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		break;

	case 29:
		SDialog="You are in the hills zone \r\n and you're not as fit \r\nas you remembered!\r\n(you lose 2 HP)";
		me->setHp(me->getHP() -2);
a.Format(_T("%d"), me->getHP());
		CHp.SetWindowTextW(a);
		CenterPix.LoadBitmapW(ID2939);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		break;

	case 30:
		if(!me->getItem(1)->getEnable())
		{
		SDialog="You Found a pair of boots!";
		me->getItem(1)->setEnable(true);
		me->setDef(me->getDef()+me->getItem(1)->getDef());
		me->setDex(me->getDex()+me->getItem(1)->getDex());
		me->setInt(me->getInt()+me->getItem(1)->getInt());
		me->setStr(me->getStr()+me->getItem(1)->getStr());
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		}
		else
		{
		SDialog="You are on a walkway.\r\n Where is it going to lead you?";
		
		CenterPix.LoadBitmapW(ID30);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		break;

	case 31:
		SDialog="You are in a rice field.\r\n The wind is becoming stronger and \r\n you start feeling tired.";
		break;

	case 32:
		SDialog="You'ew becoming hungry! \r\n You have to find some food";
		break;

	case 33:
		SDialog="You can choose to continue to the\r\n beach in the west direction,\r\n or to a village in the north\r\n direction.";
		break;

	case 34:
		CenterPix.LoadBitmapW(ID3_4);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="The people of the village are very \r\n nice- they offer you to get some \r\n rest at one of the houses  \r\n which is in the north \r\n direction.";
		break;

	case 35:
		if(foods[0])
		{
		SDialog="A meal was coocked for you!";
		me->setFood(me->getFood() +1);
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		CEat.EnableWindow(true);
		foods[0]=false;
		}
		else
			SDialog="All the food is gone :(";
		break;

	case 36:
		SDialog="A nice farmer advised you to \r\n turn northward.";
		break;

	case 37:
		CenterPix.LoadBitmapW(ID3738);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You are in the Goblins Valley! \r\n Things can turn either very good,\r\n or very bad now.";
		break;

	case 38:
		CenterPix.LoadBitmapW(ID3738);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You are in the Goblins Valley! \r\n Things can turn either very good,\r\n or very bad now.";
		break;

	case 39:
		SDialog="You are in the hills zone \r\n and you're not as fit \r\nas you remembered!\r\n(you lose 2 HP)";
		me->setHp(me->getHP() -2);
a.Format(_T("%d"), me->getHP());
		CHp.SetWindowTextW(a);//I Should add a fitness count later..(29+39)
		break;

	case 40:
		CenterPix.LoadBitmapW(ID40);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You are sorrunded by beautiful,\r\n blooming cherry trees.\r\n It seems like nothing can\r\n disturb you here.";
		break;

	case 41:
		SDialog="You are in a rice field.\r\n The wind is becoming stronger and\r\b you start feeling tired.";
		break;

	case 42:
		CenterPix.LoadBitmapW(ID42);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You hear some strange noise from\r\n the north direction.\r\n Go check it out.";
		break;

	case 43:
		SDialog="Oh no!\r\n You're in a dangerous zone!";
		break;

	case 44:
		if(!me->getItem(2)->getEnable())
		{
			CenterPix.LoadBitmapW(IDGloves);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You Found a pair of gloves!";
		me->getItem(2)->setEnable(true);
		me->setDef(me->getDef()+me->getItem(2)->getDef());
		me->setDex(me->getDex()+me->getItem(2)->getDex());
		me->setInt(me->getInt()+me->getItem(2)->getInt());
		me->setStr(me->getStr()+me->getItem(2)->getStr());
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		}
		else
		SDialog="The people of the village are very \r\n nice- they offer you to get some \r\n rest at one of the houses  \r\n which is in the north \r\n direction.";
		break;

	case 45:
		if(foods[1])
		{
		SDialog="A meal was coocked for you!";
		me->setFood(me->getFood() +1);
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		CEat.EnableWindow(true);
		foods[1]=false;
		}
		else
			SDialog="All the food is gone :(";

		break;

	case 46:
		SDialog="You are annoying the goblins!\r\n Here they come!";
		break;

	case 47:
		SDialog="You are annoying the goblins!\r\n Here they come!";
		break;

	case 48:
		CenterPix.LoadBitmapW(ID49);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="The goblins live houses made of chocolate-\r\n You can eat as much as your belly\r\n lets you!";
		break;

	case 49:
		SDialog="You're on the top of the highest hill \r\n in the Goblins valley!\r\n Take a photo for your'e\r\n Instagram.";
		CenterPix.LoadBitmapW(BIT_FAIRY);//load image
       pView.SetBitmap(CenterPix );//post image
		break;

	case 50:
		SDialog="Look how beautiful the temple you're now in!\r\n Exit the temple and check out the beautiful\r\n gardens that sorround it!";
		CenterPix.LoadBitmapW(BIT_NINJA);//load image
       pView.SetBitmap(CenterPix );//post image
		break;

	case 51:
		CenterPix.LoadBitmapW(ID5161);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You are in a rice field.\r\n You've heard that something is happening\r\n horthern of you- Go there!";
		break;

	case 52:
		if(foods[2])
		{
		SDialog="A local festival is taking place!\r\n This is your opportunity to\r\n have some good time!";
		me->setFood(me->getFood() +1);
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		CEat.EnableWindow(true);
		foods[2]=false;
		}
		else
			SDialog="All the food is gone :(";
		CenterPix.LoadBitmapW(ID5253);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		break;

	case 53:
		/*if(foods[3])
		{
		SDialog="A local festival is taking place!\r\n This is your opportunity to\r\n have some good time!";
		me->setFood(me->getFood() +1);
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		CInvetory.SetWindowTextW(Temp);
		CEat.EnableWindow(true);
		foods[3]=false;
		}
		else
			SDialog="All the food is gone :(";*/
		SDialog="There's a forest in your north \r\n direction.\r\n Who may hide there?";
		CenterPix.LoadBitmapW(ID5363);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		break;

	case 54:
		CenterPix.LoadBitmapW(ID5458);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="Please meet the trolls!\r\n They are hiding in the\r\n forests, \r\nwaiting for a victim! ";
		break;

	case 55:
		CenterPix.LoadBitmapW(ID55);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="Every diretion you will \r\n pick will lead you\r\n to a new adventure";
		break;

	case 56:
		if (me->getWeapon0()->getName()=="Shurikan" && !me->getWeapon0()->getEnable())
		{
		SDialog="You found a Shurikan ";
		me->getWeapon0()->setEnable(true);
		RWand.EnableWindow(true);
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		}
		else if(me->getWeapon0()->getName()=="White Magic" && !me->getWeapon2()->getEnable())
		{
			CenterPix.LoadBitmapW(IDWhiteMagic);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You found a book that gives \r\nyou the ability to use White Magic";
		me->getWeapon0()->setEnable(true);
		RWand.EnableWindow(true);
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		}
		else
		{
		SDialog="The view here is amazing!";
		CenterPix.LoadBitmapW(ID5657);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		break;

	case 57:
		CenterPix.LoadBitmapW(ID5657);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You are on a hill and there's \r\n a desert on the horizon!";
		break;

	case 58:
		SDialog="You're sorrounded by squirrels \r\n and evergreen trees! \r\n Enjoy the moment";
		break;

	case 59:
		CenterPix.LoadBitmapW(ID5969);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="What a pastoral view!\r\n A valley is in your west direction\r\n and a desert is in your \r\neast direction.\r\n Where will you go?";
		break;

	case 60:
		CenterPix.LoadBitmapW(ID6062);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="The clouds are gathering above\r\n your head.\r\n You need to find a safe place";
		break;

	case 61:
		CenterPix.LoadBitmapW(ID5161);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You are in a rice field.\r\n You've heard that something is happening\r\n horthern of you- Go there!";
		break;

	case 62:
		if (me->getWeapon0()->getName()=="Spear" && !me->getWeapon1()->getEnable())
		{
		SDialog="You found a Sword ";
		me->getWeapon1()->setEnable(true);
		RSword.EnableWindow(true);
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		CenterPix.LoadBitmapW(IDSWORD);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		else if(me->getWeapon0()->getName()=="Dagger" && !me->getWeapon0()->getEnable())
		{
		SDialog="You found a Sword ";
		me->getWeapon0()->setEnable(true);
		RWand.EnableWindow(true);
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		CenterPix.LoadBitmapW(IDSWORD);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		else
		{
		SDialog="The clouds are gathering above\r\n your head.\r\n You need to find a safe place";
		CenterPix.LoadBitmapW(ID6062);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		break;

	case 63:
		CenterPix.LoadBitmapW(ID5363);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="There's a forest in your north \r\n direction.\r\n Who may hide there?";
		break;

	case 64:
		SDialog="Please meet the trolls!\r\n They are hiding in the\r\n forests, \r\nwaiting for a victim! ";
		break;

	case 65:
		CenterPix.LoadBitmapW(ID65);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You see a desert on \r\nthe horizon!";
		break;

	case 66: 
		CenterPix.LoadBitmapW(ID66);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="A poisonous snake is accompanying\r\n you!\r\n Be carfel";
		break;

	case 67:
		CenterPix.LoadBitmapW(ID67);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="It's so hot in here!\r\n You have to find a water\r\n source.";
		break;

	case 68:
		CenterPix.LoadBitmapW(ID68);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You are in a borderline!";
		break;

	case 69:
		if(activeEnemy[2])
		{
	PlaySound(L"Sound/giant.wav",NULL,SND_FILENAME|SND_ASYNC); 
		DoEvents();
		SDialog="It's a trap!\r\n You have to defeat the Syclop now!";
		enemy=new Cyclop();
		monName="Cyclop";
		gameOver(2);
		activeEnemy[2]=false;
		battleid=2;
		afterBattle=true;
		CenterPix.LoadBitmapW(IDCYCLOP);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		else
		{
		SDialog="There is a dead Syclop body in here.";
		CenterPix.LoadBitmapW(IDDeadCyc);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		break;

	case 70:
		CenterPix.LoadBitmapW(ID7083);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You're in a village.\r\n There is some weird voice from the east..";
		break;

	case 71:
		CenterPix.LoadBitmapW(ID7181);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You see a small village\r\n in your north direction.\r\n Maybe the locals can provide\r\n you some food.";
		break;

	case 72:
		if(foods[4])
		{
		SDialog="You are in a village and the nice\r\n locals made your favorite food\r\n for you- sushi!";
		me->setFood(me->getFood() +1);
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		CEat.EnableWindow(true);
		foods[4]=false;
		}
		else
			SDialog="The locals ate all\r\n  the food :(";
		CenterPix.LoadBitmapW(ID7282);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		break;

	case 73:
		CenterPix.LoadBitmapW(ID7384);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="Oops!\r\n You fell into a river!\r\n To your luck, it's \r\n not that deep";
		break;

	case 74:
		CenterPix.LoadBitmapW(ID74);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You are sorrounded by a \r\nbeatiful waterfall";
		break;

	case 75:
		CenterPix.LoadBitmapW(ID75);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You've been too hasty and\r\n now you're drowning in a waterfall!";
		break;

	case 76:
		if (me->getWeapon0()->getName()=="White Magic" && !me->getWeapon1()->getEnable())
		{
			CenterPix.LoadBitmapW(IDArmourMa);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You found a book that gives \r\nyou the ability to use Armour Magic";
		me->getWeapon1()->setEnable(true);
		RSword.EnableWindow(true);
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		}
		else if(me->getWeapon0()->getName()=="Spear" && !me->getWeapon2()->getEnable())
		{
			CenterPix.LoadBitmapW(IDAxe);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You found an Axe ";
		me->getWeapon2()->setEnable(true);
		RBow.EnableWindow(true);
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		}
		else
		{
		SDialog="Nothing to look at \r\nexcept for endless dunes";
		CenterPix.LoadBitmapW(ID7677);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		break;

	case 77:
		CenterPix.LoadBitmapW(ID7677);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="Nothing to look at \r\nexcept for endless dunes";
		break;

	case 78:
		if(activeEnemy[3])
		{
	PlaySound(L"Sound/giant.wav",NULL,SND_FILENAME|SND_ASYNC); 
		DoEvents();
		SDialog="It's a trap!\r\n You have to defeat the Syclop now!";
		enemy=new Cyclop();
		monName="Cyclop";
		gameOver(2);
		activeEnemy[3]=false;
		battleid=3;
		afterBattle=true;
		CenterPix.LoadBitmapW(IDCYCLOP);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		else
		{
		SDialog="There is a dead Syclop body in here.";
		CenterPix.LoadBitmapW(IDDeadCyc);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		break;

	case 79:
		if(me->getWeapon0()->getName()=="Spear")
		{
			CenterPix.LoadBitmapW(IDTresure);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
			SDialog="Your have found the tresure chest!\r\n You won the game ,\r\nGood job!";
			DoEvents();
			gameOver(1);
		}
		else
			if(me->getWeapon0()->getName()=="Shurikan")
			{
				CenterPix.LoadBitmapW(IDSplinter);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
				SDialog="This is Master Spliner!\r\n Good job!\r\n You won the game!";
				DoEvents();
				gameOver(1);
			}
			else
			{
		SDialog="Heres you opportunity to \r\ntake a nap under the palmtrees\r\nwhat is the weird voice\r\n coming from the north...";
		CenterPix.LoadBitmapW(ID78);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
			}
		break;

	case 80:
		if(activeEnemy[4])
		{
			PlaySound(L"Sound/dragon.wav",NULL,SND_FILENAME|SND_ASYNC); 
			DoEvents();
		SDialog="It's a trap!\r\n You have to defeat the dragon now!";
		enemy=new Dragon();
		monName="Dragon";
		gameOver(2);
		activeEnemy[4]=false;
		battleid=4;
		afterBattle=true;
		CenterPix.LoadBitmapW(IDDRAGON);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		else
		{
		SDialog="There is a dead dragon body in here.";
		CenterPix.LoadBitmapW(IDDeadDr);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		//need to add if already defeated the dragon
		//Battle(2);
		break;

	case 81:
		SDialog="You see a small village\r\n in your north direction.\r\n Maybe the locals can provide\r\n you some food.";
		break;

	case 82:
		if(foods[5])
		{
		SDialog="You are in a village and the nice\r\n locals made your favorite food\r\n for you- sushi!";
		me->setFood(me->getFood() +1);
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		CEat.EnableWindow(true);
		foods[5]=false;
		}
		else
			SDialog="The locals ate all\r\n  the food :(";
		break;

	case 83:
		if(!me->getItem(0)->getEnable())
		{
		SDialog="You Found an helmet!";
		me->getItem(0)->setEnable(true);
		me->setDef(me->getDef()+me->getItem(0)->getDef());
		me->setDex(me->getDex()+me->getItem(0)->getDex());
		me->setInt(me->getInt()+me->getItem(0)->getInt());
		me->setStr(me->getStr()+me->getItem(0)->getStr());
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		}
		else
		SDialog="You're in a village.\r\n Will something interesting \r\nhappen here?";
		break;

	case 84:
		CenterPix.LoadBitmapW(ID8485);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="Oops!\r\n You fell into a river!\r\n To your luck, it's \r\b not that deep";
		break;

	case 85:
		CenterPix.LoadBitmapW(ID8485);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="There's a waterfall in your \r\nwest direcion, \r\nbe aware";
		break;

	case 86:
		CenterPix.LoadBitmapW(ID8687);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="Wow!\r\n look at the beautiful \r\nview of the colorful dunes!";
		break;

	case 87:
		CenterPix.LoadBitmapW(ID8687);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="Wow!\r\n look at the beautiful \r\nview of the colorful dunes!";
		break;

	case 88:
		CenterPix.LoadBitmapW(ID88);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="A beautiful oasis is \r\nsorroundind you!\r\n Drink water and eat\r\n some dates.";
		break;

	case 89:
		SDialog="Evil goblins!\r\n Show the who's the boss!";
		break;

	case 90:
		if(me->getWeapon0()->getName()=="White Magic")
		{
			CenterPix.LoadBitmapW(IDBarbie);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
			SDialog="Your have found the Barbie house!\r\n You won the game ,\r\nGood job!";
			DoEvents();
			gameOver(1);
		}
		else
		SDialog="What a pastoral view!\r\n A valley is in your west direction\r\n and a desert is in your \r\neast direction.\r\n Where will you go?";
		break;

	case 91:
		if(activeEnemy[5])
		{
		PlaySound(L"Sound/dragon.wav",NULL,SND_FILENAME|SND_ASYNC); 
		DoEvents();
		SDialog="It's a trap!\r\n You have to defeat the dragons now!";
		enemy=new Dragon();
		monName="Dragon";
		gameOver(2);
		activeEnemy[5]=false;
		battleid=5;
		afterBattle=true;
		CenterPix.LoadBitmapW(IDDRAGON);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		else
		{
		SDialog="There is a dead dragon body in here.";
		CenterPix.LoadBitmapW(IDDeadDr);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		break;

	case 92:
		CenterPix.LoadBitmapW(ID92);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You hear some strange noises\r\n from your south direction.";
		break;

	case 93:
		CenterPix.LoadBitmapW(ID93);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="There's a river in your\r\n west direction, be careful ";
		break;

	case 94:
		SDialog="You are in a magical flying\r\n castle!\r\n Post a picture of the view\r\n in your Snapchat and\r\n continue the journey!";
		CenterPix.LoadBitmapW(BIT_ELF);//load image
       pView.SetBitmap(CenterPix );//post image
		break;

	case 95:
		SDialog="What a nice view...";
		CenterPix.LoadBitmapW(ID94);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		break;

	case 96:
		SDialog="What a nice view...";
		CenterPix.LoadBitmapW(ID94);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
	   break;

	case 97: 
		CenterPix.LoadBitmapW(ID9798);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="Its hot and sweaty \r\nand you're becoming tired";
		break;

	case 98:
		CenterPix.LoadBitmapW(ID9798);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="Its hot and sweaty \r\nand you're becoming tired";
		break;

	case 99:
		if (me->getWeapon0()->getName()=="Shurikan" && !me->getWeapon2()->getEnable())
		{
			CenterPix.LoadBitmapW(IDKatana);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You found a Katana!";
		me->getWeapon2()->setEnable(true);
		RBow.EnableWindow(true);
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		}
		else if(me->getWeapon0()->getName()=="Dagger" && !me->getWeapon0()->getEnable())
		{
			CenterPix.LoadBitmapW(IDDagger);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		SDialog="You found an Dagger ";
		me->getWeapon0()->setEnable(true);
		RWand.EnableWindow(true);
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
		Temp0+=Temp;
		CInvetory.SetWindowTextW(Temp0);
		}
		else
		{
		SDialog="Sand everywhere!\r\n Nothing to see here.";
		CenterPix.LoadBitmapW(ID99);//load image  MAYBE I SHOULD CHANGE PICTURE
       pView.SetBitmap(CenterPix );//post image
		}
		break;

	default:
		break;
	}
	if(afterBattle)
	{
		afterBattle=false;
		Sleep(2000);
		PlaySound(L"Sound/theme.wav",NULL,SND_FILENAME|SND_ASYNC); 
	}
a.Format(_T("%d"), me->getHP());
		CHp.SetWindowTextW(a);
		a.Format(_T("%d"), me->getDef());
		CDef.SetWindowTextW(a);
		a.Format(_T("%d"), me->getStr());
		CStr.SetWindowTextW(a);
		a.Format(_T("%d"), me->getInt());
		CInt.SetWindowTextW(a);
		a.Format(_T("%d"), me->getDex());
		CDex.SetWindowTextW(a);
	Output.SetWindowTextW(SDialog);//meanwhile
}


void CDNDPprojectDlg::afterLoad()
{
	//////////////////
	PlaySound(L"Sound/theme.wav",NULL,SND_FILENAME|SND_ASYNC); 

		CRestart.EnableWindow(true);
		newName=false;
		msg="";
		Dialog.SetWindowTextW(msg);


		CEast.EnableWindow(true);east=true;
		CWest.EnableWindow(true); west=true;
		CNorth.EnableWindow(true);north=true;
		CSouth.EnableWindow(true);south=true;
CGo.EnableWindow(false);
Dialog.SetReadOnly(true);

//CBitmap CenterPix;//creating bitmap
		RHands.SetCheck(true);
		CSaveG.EnableWindow(true);

CString a;
a.Format(_T("%d"), me->getHP());
		CHp.SetWindowTextW(a);
		a.Format(_T("%d"), me->getDef());
		CDef.SetWindowTextW(a);
		a.Format(_T("%d"), me->getStr());
		CStr.SetWindowTextW(a);
		a.Format(_T("%d"), me->getInt());
		CInt.SetWindowTextW(a);
		a.Format(_T("%d"), me->getDex());
		CDex.SetWindowTextW(a);

Output.SetWindowTextW(SDialog);
Cweapon.SetWindowTextW(L"Weapons:");
RHands.SetWindowTextW(L"Hands");
RBow.EnableWindow(me->getWeapon2()->getEnable());
RSword.EnableWindow(me->getWeapon1()->getEnable());
RWand.EnableWindow(me->getWeapon0()->getEnable());
RHands.EnableWindow(true);

name=me->getName();
CName.SetWindowTextW(name);

	CNorth.EnableWindow(false);north=false;
	CEast.EnableWindow(false);east=false;
	CWest.EnableWindow(false);west=false;
	CSouth.EnableWindow(false);south=false;

	if  (me->getY() <9){
		CNorth.EnableWindow(true);north=true;}
	if (me->getY()>0){
		CSouth.EnableWindow(true);south=true;}
	if(me->getX()<9){
		CEast.EnableWindow(true);east=true;}
	if(me->getX()>0){
		CWest.EnableWindow(true);west=true;}

CString Temp,Temp0;
Temp="";
		Temp0=me->getWeaponsST();

		if(!(me->getFood() ||me->getWeapon0()->getEnable()||me->getWeapon1()->getEnable()||me->getWeapon2()->getEnable() ||me->getItem(0)->getEnable()||me->getItem(1)->getEnable() ||me->getItem(2)->getEnable())   )
		{
Temp0="You have nothing \r\n";//AFTER IL ADD ITEMS NEED TO CHANGE
		}
else if(me->getFood())
{
		Temp.Format(_T("%d"), me->getFood());
		Temp+=" x Food(+2 HP)";
			CEat.EnableWindow(true);
					Temp0+=Temp;

}
		CInvetory.SetWindowTextW(Temp0);


	checkLocation();
RWand.SetWindowTextW(me->getWeapon0()->getName());
RSword.SetWindowTextW(me->getWeapon1()->getName());
RBow.SetWindowTextW(me->getWeapon2()->getName());
	////////////////////
}

CDNDPprojectDlg::CDNDPprojectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDNDPprojectDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	afterload=false;
	characterFactory=NinjaFactory::getInstance();
}

CDNDPprojectDlg::CDNDPprojectDlg(bool * food,int classSelect,Character *m,CWnd* pParent)
		: CDialogEx(CDNDPprojectDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	me=m;
	afterload=true;
	foods=food;
	ClassSelect=ClassSelect;
	characterFactory=NinjaFactory::getInstance();
}

void CDNDPprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, CE_OUTPUT, Output);
	DDX_Control(pDX, CE_DIALOG, Dialog);
	DDX_Control(pDX, IDC_START, BtnStart);
	DDX_Control(pDX, CE_HP, CHp);
	DDX_Control(pDX, CE_STR, CStr);
	DDX_Control(pDX, CE_INT, CInt);
	DDX_Control(pDX, CE_DEX, CDex);
	DDX_Control(pDX, CE_DEF, CDef);
	DDX_Control(pDX, IDC_WEAPONS, Cweapon);
	DDX_Control(pDX, RAD_HANDS, RHands);
	DDX_Control(pDX, RAD_WAND, RWand);
	DDX_Control(pDX, RAD_SWORD, RSword);
	DDX_Control(pDX, RAD_BOW, RBow);


	DDX_Control(pDX, IDC_GO, CGo);
	DDX_Control(pDX, IDC_NORTH, CNorth);
	DDX_Control(pDX, IDC_WEST, CWest);
	DDX_Control(pDX, IDC_EAST, CEast);
	DDX_Control(pDX, IDC_SOUTH, CSouth);
	DDX_Control(pDX, IDC_PVIEW, pView);
	DDX_Control(pDX, CE_NAME, CName);
	DDX_Control(pDX, CE_INVETORY, CInvetory);
	DDX_Control(pDX, IDC_RESTART, CRestart);
	DDX_Control(pDX, IDC_SAVE, CSaveG);
	DDX_Control(pDX, IDC_EAT, CEat);
	DDX_Control(pDX, IDC_ACTION, CAction);
}


BEGIN_MESSAGE_MAP(CDNDPprojectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_QUIT, &CDNDPprojectDlg::OnBnClickedQuit)
	ON_BN_CLICKED(IDC_START, &CDNDPprojectDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_GO, &CDNDPprojectDlg::OnBnClickedGo)
	ON_BN_CLICKED(RAD_HANDS, &CDNDPprojectDlg::OnBnClickedHands)
	ON_BN_CLICKED(RAD_WAND, &CDNDPprojectDlg::OnBnClickedWand)
	ON_BN_CLICKED(RAD_SWORD, &CDNDPprojectDlg::OnBnClickedSword)
	ON_BN_CLICKED(RAD_BOW, &CDNDPprojectDlg::OnBnClickedBow)
	ON_BN_CLICKED(IDC_NORTH, &CDNDPprojectDlg::OnBnClickedNorth)
	ON_BN_CLICKED(IDC_SOUTH, &CDNDPprojectDlg::OnBnClickedSouth)
	ON_BN_CLICKED(IDC_EAST, &CDNDPprojectDlg::OnBnClickedEast)
	ON_BN_CLICKED(IDC_WEST, &CDNDPprojectDlg::OnBnClickedWest)
	ON_BN_CLICKED(IDC_RESTART, &CDNDPprojectDlg::OnBnClickedRestart)
	ON_BN_CLICKED(IDC_HELP, &CDNDPprojectDlg::OnBnClickedHelp)
	ON_BN_CLICKED(IDC_SAVE, &CDNDPprojectDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_LOAD, &CDNDPprojectDlg::OnBnClickedLoad)
	ON_BN_CLICKED(IDC_EAT, &CDNDPprojectDlg::OnBnClickedEat)
	ON_BN_CLICKED(IDC_ACTION, &CDNDPprojectDlg::OnBnClickedAction)
	ON_BN_CLICKED(ID_STOPMUSIC, &CDNDPprojectDlg::OnBnClickedStopmusic)
END_MESSAGE_MAP()


// CDNDPprojectDlg message handlers

BOOL CDNDPprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//////////////////////






	///////////////////

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}

	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDNDPprojectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}


}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDNDPprojectDlg::OnPaint()
{
	if(afterload && !Restart)
	afterLoad();
	Restart=false;
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDNDPprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDNDPprojectDlg::OnBnClickedQuit()
{
	PostQuitMessage(0);
	// TODO: Add your control notification handler code here
}



void CDNDPprojectDlg::OnBnClickedStart()
{
Dialog.SetReadOnly(false);
BtnStart.EnableWindow(false);
msg="Enter your name here!";
Dialog.SetWindowTextW(msg);
Dialog.SetFocus();
Dialog.SetSel(0,-1,false);
newName=true;
CGo.EnableWindow(true);
PlaySound(L"Sound/theme.wav",NULL,SND_FILENAME|SND_ASYNC); 


SDialog="The Pizza you ate yesterday \r\n";
SDialog+="was not that innocent! it \r\n";
SDialog+="consisted of poisonous \r\n";
SDialog+="cheese that made you wake \r\n";
SDialog+="up as one of the next \r\n";
SDialog+="characters. Choose the \r\n";
SDialog+="one that will help you\r\n";
SDialog+="complete the journey and \r\n";
SDialog+="get back to your real shape! \r\n";
SDialog+="Before we begin \r\n\r\n";
SDialog+="Please write your Name\r\n\r\n";
SDialog+="and then select a class :\r\n\r\n";
SDialog+="each class has different stats of:\r\n";
SDialog+="HP   STR   INT   DEX   DEF\r\n";
SDialog+=" \r\nclick GO! \r\n when youre finsih \r\n \r\n \r\n";
Output.SetWindowTextW(SDialog+L"You Selected Ninja \r\n High DEX low INT \r\n");
Cweapon.SetWindowTextW(L"Class:");
RHands.EnableWindow(true);
RHands.SetCheck(true);
RHands.SetWindowTextW(L"Ninja");
RBow.EnableWindow(true);
RBow.SetWindowTextW(L"Fairy");
RSword.EnableWindow(true);
RSword.SetWindowTextW(L"Elf");
RWand.EnableWindow(true);
RWand.SetWindowTextW(L"Viking");

CBitmap CenterPix;//creating bitmap
	  CenterPix.LoadBitmapW(BIT_BEGIN);//load image
       pView.SetBitmap(CenterPix );//post image


}


void CDNDPprojectDlg::OnBnClickedGo()
{
	if(newName)
	{
		CRestart.EnableWindow(true);
		newName=false;
		Dialog.GetWindowTextW(name);
		msg="";
		Dialog.SetWindowTextW(msg);

//SDialog=L""+name+L" \r\n";

		CEast.EnableWindow(true);east=true;
		CWest.EnableWindow(true); west=true;
		CNorth.EnableWindow(true);north=true;
		CSouth.EnableWindow(true);south=true;
CGo.EnableWindow(false);
Dialog.SetReadOnly(true);

		RHands.SetCheck(true);
		RBow.SetCheck(false);
		RSword.SetCheck(false);
		RWand.SetCheck(false);

me=characterFactory->createCharacter();
me->setName(name);


CSaveG.EnableWindow(true);
checkLocation();

	CNorth.EnableWindow(false);north=false;
	CEast.EnableWindow(false);east=false;
	CWest.EnableWindow(false);west=false;
	CSouth.EnableWindow(false);south=false;

	if  (me->getY() <9){
		CNorth.EnableWindow(true);north=true;}
	if (me->getY()>0){
		CSouth.EnableWindow(true);south=true;}
	if(me->getX()<9){
		CEast.EnableWindow(true);east=true;}
	if(me->getX()>0){
		CWest.EnableWindow(true);west=true;}

CString a;
a.Format(_T("%d"), me->getHP());
		CHp.SetWindowTextW(a);
		a.Format(_T("%d"), me->getDef());
		CDef.SetWindowTextW(a);
		a.Format(_T("%d"), me->getStr());
		CStr.SetWindowTextW(a);
		a.Format(_T("%d"), me->getInt());
		CInt.SetWindowTextW(a);
		a.Format(_T("%d"), me->getDex());
		CDex.SetWindowTextW(a);

Output.SetWindowTextW(me->getStory());
Cweapon.SetWindowTextW(L"Weapons:");
RHands.SetWindowTextW(L"Hands");
RBow.EnableWindow(false);
RSword.EnableWindow(false);
RWand.EnableWindow(false);
RWand.SetWindowTextW(me->getWeapon0()->getName());
RSword.SetWindowTextW(me->getWeapon1()->getName());
RBow.SetWindowTextW(me->getWeapon2()->getName());


CName.SetWindowTextW(name);
CInvetory.SetWindowTextW(L"You have nothing \r\n");
	}
	// TODO: Add your control notification handler code here
}


void CDNDPprojectDlg::OnBnClickedHands()
{
	if(newName)
	{
	characterFactory=NinjaFactory::getInstance();
	ClassSelect=0;
	// TODO: Add your control notification handler code here
Output.SetWindowTextW(SDialog+L"You Selected Ninja \r\n High DEX low INT \r\n");
Dialog.SetFocus();
Dialog.SetSel(0,-1,false);

	}
	else WeID=0;

}


void CDNDPprojectDlg::OnBnClickedWand()
{
		if(newName)
	{
	ClassSelect=1;
	characterFactory=VikingFactory::getInstance();
	// TODO: Add your control notification handler code here
	Output.SetWindowTextW(SDialog+L"You Selected Viking \r\n High STR low INT \r\n");
	Dialog.SetFocus();
Dialog.SetSel(0,-1,false);

		}
		else WeID=1;
}


void CDNDPprojectDlg::OnBnClickedSword()
{
		if(newName)
	{
	ClassSelect=2;
	characterFactory=ElfFactory::getInstance();
	// TODO: Add your control notification handler code here
		Output.SetWindowTextW(SDialog+L"You Selected Elf \r\n High INT low STR \r\n");
		Dialog.SetFocus();
Dialog.SetSel(0,-1,false);

		}
		else WeID=2;
}


void CDNDPprojectDlg::OnBnClickedBow()
{
		if(newName)
	{
	ClassSelect=3;
	// TODO: Add your control notification handler code here
		characterFactory=FairyFactory::getInstance();
		Output.SetWindowTextW(SDialog+L"You Selected Fairy \r\n High HP low  DEX \r\n");
		Dialog.SetFocus();
Dialog.SetSel(0,-1,false);

		}
		else WeID=3;
}


void CDNDPprojectDlg::OnBnClickedNorth()
{
	me->goNorth();
if(me->getY() ==9){
	CNorth.EnableWindow(false);north=east;}
if(me->getY() >0){
	CSouth.EnableWindow(true);south=true;}

checkLocation();
}


void CDNDPprojectDlg::OnBnClickedSouth()
{
	me->goSouth();
	if(me->getY() ==0){
		CSouth.EnableWindow(false);south=false;}
if(me->getY() <9){
	CNorth.EnableWindow(true);north=true;}

checkLocation();
}


void CDNDPprojectDlg::OnBnClickedEast()
{
	me->goEast();
if(me->getX() ==9){
	CEast.EnableWindow(false);east=false;}
if(me->getX() >0){
	CWest.EnableWindow(true);west=true;}

checkLocation();
}


void CDNDPprojectDlg::OnBnClickedWest()
{
me->goWest();
if(me->getX() ==0){
	CWest.EnableWindow(false);west=false;}
if(me->getX() <9){
	CEast.EnableWindow(true);east=true;}

checkLocation();
}


void CDNDPprojectDlg::OnBnClickedRestart()
{
MsgAns = MessageBox(L"You are in the middle of a game. Are you sure?", 
L"Start Over?", MB_YESNOCANCEL|MB_ICONINFORMATION);
if(MsgAns==IDYES)
{
characterFactory=NinjaFactory::getInstance();
	Restart=true;
InitializeGlobals(); 
name="";
CName.SetWindowTextW(L"");
OnBnClickedStart();
CDef.SetWindowTextW(L"");
CDex.SetWindowTextW(L"");
CInt.SetWindowTextW(L"");
CStr.SetWindowTextW(L"");
CHp.SetWindowTextW(L"");
CNorth.EnableWindow(false);north=false;
CEast.EnableWindow(false);east=false;
CWest.EnableWindow(false);west=false;
CSouth.EnableWindow(false);south=false;
CRestart.EnableWindow(false);
CSaveG.EnableWindow(false);
RHands.SetCheck(true);
		RBow.SetCheck(false);
		RSword.SetCheck(false);
		RWand.SetCheck(false);
		for(int i=0;i<6;++i)
			foods[i]=true;
		me->setFood(0);
		for(int i=0;i<6;++i)
			activeEnemy[i]=true;
		CEat.EnableWindow(false);
		CInvetory.SetWindowTextW(L"");
		CAction.EnableWindow(false);
}

}

void InitializeGlobals()
{
name="";
msg=""; 
SDialog="";
newName=false;
ClassSelect=0;
for(int i=0;i<10;i++)
monster[i]=false;
delete me;
delete Location;
}



void CDNDPprojectDlg::OnBnClickedHelp()
{
	CString HelpText=CString(_T(""));
	HelpText="The object of this game is to complet your'e character mission.";
HelpText+=" in this game you will gain exprience,items such as :\n" ;
HelpText+=" weapons,armour,potions and even spells.";
HelpText+=" \n at the game you have few main buttons: \n"; 
HelpText+="At the begning of the game you will have to choose between";
HelpText+="the classes available, each one has its own unique ability and storyline"; 
HelpText+="you should choose a name and then click go. \n when the story begins"; 
HelpText+="you will have weapons to choose from (you beging with nothing but your hands)\n";
HelpText+="as you move on , you will get new weapons to use, and also items to make you stronger.\n";
HelpText+="there is also a special item called potion , which will increase your hp-HitPoints\n";
HelpText+="in a battle you should choose each turn a weapon and click the action button to use it against youre enemy\n";
HelpText+="in the main map you can move to each side of the map using the : NORTH,WEST ,EAST , SOUTH button\n Good Luck!";

MessageBox((LPCTSTR)HelpText, L"Dungeon and Dragons 1.0 - Help");
}


void CDNDPprojectDlg::OnBnClickedSave()
{
	SaveDialog dlg(foods,ClassSelect,me);
dlg.DoModal();
//pSaveName = ( CEdit * ) GetDlgItem( IDC_SaveName );
//pSavePassword = ( CEdit * ) GetDlgItem( IDC_SavePassword );
//bool success;
}


void CDNDPprojectDlg::OnBnClickedLoad()
{
	DLGLoad dlg;
	dlg.DoModal();
}


void CDNDPprojectDlg::OnBnClickedEat()
{
	CString a,Temp0;
	me->setHp(me->getHP() +2);
	me->setFood(me->getFood() -1);
	if (me->getFood() <1 && !me->getWeapon0()->getEnable()&& !me->getWeapon1()->getEnable()&& !me->getWeapon2()->getEnable())
	{
		CEat.EnableWindow(false);
		CInvetory.SetWindowTextW(L"You have nothing \r\n");//AFTER IL ADD ITEMS NEED TO CHANGE
	}
	else
	{
		a.Format(_T("%d"), me->getFood());
		a+=" x Food(+2 HP)";
		Temp0=me->getWeaponsST();
		if(me->getFood())
			Temp0+=a;
			CInvetory.SetWindowTextW(Temp0);
	}
	if(me->getFood() <1 )
		CEat.EnableWindow(false);
	
	a.Format(_T("%d"), me->getHP());
		CHp.SetWindowTextW(a);

}

void CDNDPprojectDlg::gameOver(int id)
{
CNorth.EnableWindow(false);north=false;
CEast.EnableWindow(false);east=false;
CWest.EnableWindow(false);west=false;
CSouth.EnableWindow(false);south=false;
CSaveG.EnableWindow(false);

BtnStart.EnableWindow(false);

if(id==2)
{
	CAction.EnableWindow(true);
}
else
{
RHands.SetCheck(false);
RBow.EnableWindow(false);
RSword.EnableWindow(false);
RWand.EnableWindow(false);
RHands.EnableWindow(false);
RBow.SetCheck(false);
RSword.SetCheck(false);
RWand.SetCheck(false);
	CEat.EnableWindow(false);
	CString Text=CString(_T(""));
	if (id==1)
	Text="Good Job you have won the game!!!";
	else
		Text="You lost the battle, game over!!!";

MessageBox((LPCTSTR)Text, L"Dungeon and Dragons 1.0 - Won");
}
}


void CDNDPprojectDlg::OnBnClickedAction()
{
	CString Damaged;
	damage=me->Attack(enemy,WeID);
	switch(WeID)
	{
	case 0:
		Damaged="Hands";
		break;
		
	case 1:
		Damaged=me->getWeapon0()->getName();
		break;

	case 2:
		Damaged=me->getWeapon1()->getName();
		break;

	case 3:
		Damaged=me->getWeapon2()->getName();
		break;
	}
	PlaySound(L"Sound/sword.wav",NULL,SND_FILENAME|SND_ASYNC); 
	SDialog.Format(_T("You done %d damage, using %s,\r\n %s has %d HP left"), damage,Damaged,monName,enemy->getHP());
	Output.SetWindowTextW(SDialog);
	DoEvents();
	if(enemy->getHP() <1)
	{
		Won();
		return;
	}
	NextAttack();
	if(me->getHP() <1)
	{
		Died();
		return;
	}
}

void CDNDPprojectDlg::NextAttack()
{
	CAction.EnableWindow(false);
	DoEvents();
	Sleep(2000);
	backDamaged=enemy->Attack(me);
	if(monName=="Dragon")
	PlaySound(L"Sound/dragon.wav",NULL,SND_FILENAME|SND_ASYNC); 
	else
	PlaySound(L"Sound/giant.wav",NULL,SND_FILENAME|SND_ASYNC); 
		DoEvents();
	SDialog.Format(_T("%s attacked you and did %d damage,\r\n enemy has %d HP left"), monName,backDamaged,enemy->getHP());
	Output.SetWindowTextW(SDialog);
	updateHP();
		CAction.EnableWindow(true);
	DoEvents();
}

void CDNDPprojectDlg::Won()
{
		Sleep(2000);
		SDialog="You have Won the Battle! enjoy the exp,\r\n you can pass";
		Output.SetWindowTextW(SDialog);
		delete enemy;
		CAction.EnableWindow(false);
		Battle(battleid);
		me->LevelUp();
		updateHP();
		DoEvents();
		return;
}

void CDNDPprojectDlg::Died()
{
		Sleep(2000);
		SDialog="You Lost the Battle, Game Over";
		Output.SetWindowTextW(SDialog);
		delete enemy;
		gameOver(0);
		CAction.EnableWindow(false);
		DoEvents();
		return;
}

void CDNDPprojectDlg::updateHP()
	{
		CString a;
		a.Format(_T("%d"), me->getHP());
		CHp.SetWindowTextW(a);
		a.Format(_T("%d"), me->getDef());
		CDef.SetWindowTextW(a);
		a.Format(_T("%d"), me->getStr());
		CStr.SetWindowTextW(a);
		a.Format(_T("%d"), me->getInt());
		CInt.SetWindowTextW(a);
		a.Format(_T("%d"), me->getDex());
		CDex.SetWindowTextW(a);
}

bool CDNDPprojectDlg::DoEvents()
{
    MSG msg;
    while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
        {
            return FALSE;
        }
        if (!AfxGetApp()->PreTranslateMessage(&msg))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
        }
    }
    return TRUE;
}

void CDNDPprojectDlg::OnBnClickedStopmusic()
{
	PlaySound( NULL, NULL, 0 );
	// TODO: Add your control notification handler code here
}

BOOL CDNDPprojectDlg::PreTranslateMessage(MSG * pMsg)
{
	CDNDPprojectDlg m;
	int x=(int)pMsg->wParam;
	if(pMsg->message==WM_KEYDOWN)
	{
		switch(x)
		{
		case VK_UP:
			if(north)
				OnBnClickedNorth();
		break;
		case VK_DOWN:
			if(south)
				OnBnClickedSouth();
			break;

		case VK_RIGHT:
			if(east)
				OnBnClickedEast();
			break;

		case VK_LEFT:
			if(west)
				OnBnClickedWest();
			break;

			default:
				break;

		}

	}
    return  __super::PreTranslateMessage(pMsg);



}


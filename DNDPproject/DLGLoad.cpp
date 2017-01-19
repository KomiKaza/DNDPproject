// DLGLoad.cpp : implementation file
//

#include "stdafx.h"
#include "DNDPproject.h"
#include "DLGLoad.h"
#include "afxdialogex.h"
#include <fstream>
#include "DNDPprojectDlg.h"
#include <iostream>
#include <string>
#include "Character.h"
#include "Fairy.h"
#include "Elf.h"
#include "Ninja.h"
#include "Viking.h"



// DLGLoad dialog

IMPLEMENT_DYNAMIC(DLGLoad, CDialogEx)

DLGLoad::DLGLoad(CDNDPprojectDlg * dlg,CWnd* pParent /*=NULL*/)
	: CDialogEx(DLGLoad::IDD, pParent)
{
	DLGLoad::dlg=dlg;
}

DLGLoad::~DLGLoad()
{
}

void DLGLoad::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LOADNAME, CLoadName);
	DDX_Control(pDX, IDC_PASSNAME, CLoadPass);
}


BEGIN_MESSAGE_MAP(DLGLoad, CDialogEx)
	ON_BN_CLICKED(ID_LOADGAME, &DLGLoad::OnBnClickedLoadgame)
	ON_BN_CLICKED(IDCANCELLOAD, &DLGLoad::OnBnClickedCancelload)
END_MESSAGE_MAP()


// DLGLoad message handlers


void DLGLoad::OnBnClickedLoadgame()
{
CString problem;
std::string passwd,nm;
int hp, dex, def, str, INt, locX,locY,foodI;
CString CharacterName; 
CString pass; 
Character *me;
int ClassSelect;
int try1;
int *foods =new int[7];
int *enable=new int[6];
int * monsters=new int[10];
CLoadName.GetWindowText(CharacterName);
CharacterName +=".gam";

std::ifstream ReadStuff;
ReadStuff.open(CharacterName);

//Detect if successful or not to keep program from crashing on failed load 
if(!ReadStuff) 
{ 
problem = "Can not find the file you typed in. Try a different name?"; 
MessageBox(problem, L"Error! Character Could Not Be Loaded."); return;
}

else
{ 
CLoadPass.GetWindowText(pass);
std::getline(ReadStuff, passwd);

if(pass == passwd.c_str())
{ 

getline(ReadStuff, nm); 
ReadStuff >> hp;
ReadStuff >> def;
ReadStuff >> INt;
ReadStuff >> str;
ReadStuff >> dex;

ReadStuff >> locX;
ReadStuff >> locY;
ReadStuff >> ClassSelect;

ReadStuff >>foodI;

ReadStuff >> foods[0];
ReadStuff >> foods[1];
ReadStuff >> foods[2];
ReadStuff >> foods[3];
ReadStuff >> foods[4];
ReadStuff >> foods[5];
ReadStuff >> foods[6];


ReadStuff >> monsters[0];
ReadStuff >> monsters[1];
ReadStuff >> monsters[2];
ReadStuff >> monsters[3];
ReadStuff >> monsters[4];
ReadStuff >> monsters[5];


ReadStuff >> enable[0];
ReadStuff >> enable[1];
ReadStuff >> enable[2];

ReadStuff >> enable[3];
ReadStuff >> enable[4];
ReadStuff >> enable[5];



ReadStuff.close();

MessageBox(L"Your character was loaded successfully!",
L"Character Loaded Successfully!"); 
CPoint * Location=new CPoint();

switch(ClassSelect){
	case 0:
		me=new Ninja();
		break;
	case 1:
		me=new Viking();
		break;
	case 2:
		me=new Elf();
		break;
	case 3:
		me=new Fairy();
		break;
	default:
		me=new Ninja();
}
me->setLocX(locX);
me->setLocY(locY);
me->setDef(def);
me->setDex(dex);
me->setHp(hp);
me->setInt(INt);
me->setStr(str);
CString cstr(nm.c_str());
me->setName(cstr);
me->setFood(foodI);
me->getWeapon0()->setEnable(enable[0]?true:false);
me->getWeapon1()->setEnable(enable[1]?true:false);
me->getWeapon2()->setEnable(enable[2]?true:false);
me->getItem(0)->setEnable(enable[3]?true:false);
me->getItem(1)->setEnable(enable[4]?true:false);
me->getItem(2)->setEnable(enable[5]?true:false);
bool neFood[7];
bool neMonster[6];
for(int i=0;i<6;++i)
{
	neMonster[i]=monsters[i]?true:false;
	neFood[i]=foods[i]?true:false;
}
	neFood[6]=foods[6]?true:false;

dlg->setBoolFood(neFood);
dlg->setBoolMonster(neMonster);
dlg->setClass(ClassSelect);
dlg->setChar(me);
dlg->Invalidate();
EndDialog( 0 );

}//close if

else 
{ 
problem = "An incorrect password was entered. Re-enter it please."; 
MessageBox(problem, L"Error! Character Could Not Be Loaded."); 
return;
}

}//close else

}


void DLGLoad::OnBnClickedCancelload()
{
EndDialog( 0 );
}

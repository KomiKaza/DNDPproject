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

DLGLoad::DLGLoad(CWnd* pParent /*=NULL*/)
	: CDialogEx(DLGLoad::IDD, pParent)
{

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
bool dagger, sword, bow, mail, armor, healing, fkey;
int ClassSelect;
bool *foods =new bool[6];
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

//Need to convert the string to CString with .c_str()
if(pass == passwd.c_str())
{ 
//Careful! serialization = you must read in exactly the same order as you wrote!
//Have to use getline for nm since name may have spaces in it
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

ReadStuff >>foods[0];
ReadStuff >>foods[1];
ReadStuff >>foods[2];
ReadStuff >>foods[3];
ReadStuff >>foods[4];
ReadStuff >>foods[5];

Character *me;

//
//ReadStuff >> dagger;
//ReadStuff >> sword; ReadStuff >> bow; 
//ReadStuff >> mail; ReadStuff >> armor;
//ReadStuff >> healing; ReadStuff >> fkey;
//
//
//bool giant, dragon, motley, shaman, center, under, HPwest2, HPshaman;
//int CD, CG;
//
//ReadStuff >> giant; W1GiantAlive = giant;
//ReadStuff >> dragon; E1DragonAlive = dragon; 
//ReadStuff >> motley; S2MotleyCrewAlive = motley; 
//ReadStuff >> shaman; FirstTimeInShamanHut = shaman;
//ReadStuff >> center; CENTERFirstTime = center;
//ReadStuff >> under; UNDERDragonPairAlive = under;
//ReadStuff >> HPwest2; FoundHP_West2 = HPwest2;
//ReadStuff >> HPshaman; FoundHP_Shaman = HPshaman;
//ReadStuff >> CD; ConqueredDragons = CD;
//ReadStuff >> CG; ConqueredGiants = CG; 
//
//
//
//CurrentPlayer->setName(nm.c_str());
//CurrentPlayer->setHit(hp);
//CurrentPlayer->setAttack(atk); 
//CurrentPlayer->setDefense(def); 
//CurrentPlayer->setLevel(lvl); 
//CurrentPlayer->setScore(scr);
//CurrentPlayer->setDagger(dagger);
//CurrentPlayer->setSword(sword); 
//CurrentPlayer->setLongBow(bow); 
//CurrentPlayer->setChainMail(mail); 
//CurrentPlayer->setFullBodyArmor(armor);
//CurrentPlayer->setHealingPotion(healing); 
//CurrentPlayer->setFishKey(fkey); 

ReadStuff.close();
//CurrentPlayer->Inventory(); 
//CurrentPlayer->DisplayStats();
//NeedName = false; 
//Conquests();
//pName->SetWindowText(CurrentPlayer->getName());
//PlaySound(L"media/theme.wav",NULL,SND_FILENAME|SND_ASYNC);

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


CDNDPprojectDlg dlg(foods,ClassSelect,me);
dlg.DoModal();
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

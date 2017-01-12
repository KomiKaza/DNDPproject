// SaveDialog.cpp : implementation file
//

#include "stdafx.h"
#include "DNDPproject.h"
#include "SaveDialog.h"
#include "afxdialogex.h"
#include <fstream>
#include "DNDPprojectDlg.h"


// SaveDialog dialog

IMPLEMENT_DYNAMIC(SaveDialog, CDialogEx)

SaveDialog::SaveDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(SaveDialog::IDD, pParent)
{
	me=NULL;
	SaveDialog::ClassType=0;
	foods=NULL;
}

SaveDialog::SaveDialog(bool * foods,int classtype,Character * me,CWnd* pParent)
	: CDialogEx(SaveDialog::IDD, pParent)
{
	SaveDialog::me=me;
	SaveDialog::ClassType=classtype;
	SaveDialog::foods=foods;
}

SaveDialog::~SaveDialog()
{
}

void SaveDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, CSaveName);
	DDX_Control(pDX, IDC_EDIT2, CSavePass);
}


BEGIN_MESSAGE_MAP(SaveDialog, CDialogEx)
	ON_BN_CLICKED(IDCANCELSAVE, &SaveDialog::OnBnClickedCancelsave)
	ON_BN_CLICKED(ID_SAVEGAME, &SaveDialog::OnBnClickedSavegame)
END_MESSAGE_MAP()


// SaveDialog message handlers


void SaveDialog::OnBnClickedCancelsave()
{
EndDialog( 0 );
}


void SaveDialog::OnBnClickedSavegame()
{
CString CharacterName=CString(_T(""));
CString password=CString(_T(""));

CSaveName.GetWindowText(CharacterName);
CharacterName += ".gam";

CSavePass.GetWindowText(password);

std::ofstream WriteStuff;
WriteStuff.open(CharacterName);

if(!WriteStuff) 
{ 
	MessageBox(L"Your character could not be saved, for some reason.",
L"Error! Character Could Not Be Saved."); 
;
} //close if

else 
{
//NOTE: We need to convert the CStrings to strings to write the data.
char PASSWORD[100] = " ";
for(int y = 0; y < password.GetLength(); y++)
{ PASSWORD[y] = password[y]; }

CString CHARACTERNAME = me->getName();
char CHARNAME[100] = " ";
for(int z = 0; z < CHARACTERNAME.GetLength(); z++)
{ CHARNAME[z] = CHARACTERNAME[z]; }

//Simple serialization of Character class 
WriteStuff << PASSWORD << "\n"; 
WriteStuff << CHARNAME << "\n";
WriteStuff << me->getHP() << "\n";
WriteStuff << me->getDef() << "\n"; 
WriteStuff << me->getInt() << "\n";
WriteStuff << me->getStr() << "\n";
WriteStuff << me->getDex() << "\n";

WriteStuff << me->getX() << "\n";
WriteStuff << me->getY() << "\n"; 

WriteStuff<<ClassType<<"\n";

WriteStuff<<me->getFood()<<"\n";

WriteStuff <<((foods[0])?1:0)<<"\n";
WriteStuff <<((foods[1])?1:0)<<"\n";
WriteStuff <<((foods[2])?1:0)<<"\n";
WriteStuff <<((foods[3])?1:0)<<"\n";
WriteStuff <<((foods[4])?1:0)<<"\n";
WriteStuff <<((foods[5])?1:0)<<"\n";

WriteStuff <<((me->getWeapon0()->getEnable())?1:0)<<"\n";
WriteStuff <<((me->getWeapon1()->getEnable())?1:0)<<"\n";
WriteStuff <<((me->getWeapon2()->getEnable())?1:0)<<"\n";

WriteStuff <<((me->getItem(0)->getEnable())?1:0)<<"\n";
WriteStuff <<((me->getItem(1)->getEnable())?1:0)<<"\n";
WriteStuff <<((me->getItem(2)->getEnable())?1:0)<<"\n";


WriteStuff.close();

MessageBox(L"Your character was saved successfully!",
L"Character Saved Successfully!"); 
EndDialog( 0 );
}//close else





}

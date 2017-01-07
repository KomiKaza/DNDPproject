
// DNDPprojectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DNDPproject.h"
#include "DNDPprojectDlg.h"
#include "afxdialogex.h"
#include "Character.h"
#include "Monster.h"
#include "Elf.h"
#include "Viking.h"
#include "Ninja.h"
#include "Fairy.h"

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
bool monster[10];
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



CDNDPprojectDlg::CDNDPprojectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDNDPprojectDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
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
	DDX_Control(pDX, IDC_HEAL, CHeal);
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
END_MESSAGE_MAP()


// CDNDPprojectDlg message handlers

BOOL CDNDPprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

CNorth.EnableWindow(true);
CSouth.EnableWindow(true);
CEast.EnableWindow(true);
CWest.EnableWindow(true);
CGo.EnableWindow(false);
Dialog.SetReadOnly(true);

CBitmap CenterPix;//creating bitmap
		RHands.SetCheck(true);

switch(ClassSelect){
	case 0:
		SDialog="Hello ";
		SDialog+=name;
		SDialog+=",\r\n";
		SDialog+="we are honored to inform you that you are\r\n";
		SDialog+="the greatest ninja on earth! You're sitting in a\r\n";
		SDialog+="beautiful ancient temple, drink your\r\n protein shake,\r\n";
		SDialog+="watching the cherry trees bloom outside\r\n the window,\r\n";
		SDialog+="when suddenly you hear that your beloved \r\n teacher\r\n";
		SDialog+="Master Splinter is fighting the evils and needs\r\n";
		SDialog+="your assistance! He informs you that he's\r\n";
		SDialog+="in a middle of a desert,\r\n";
		SDialog+="go and find him!\r\n";
		me=new Ninja();
		Location=new CPoint(5,0);
		CenterPix.LoadBitmapW(BIT_NINJA);//load image
        pView.SetBitmap(CenterPix );//post image
	    GetDlgItem(RAD_WAND)->SetWindowTextW(L"Shurikan");
		GetDlgItem(RAD_SWORD)->SetWindowTextW(L"Nunchaka");
		GetDlgItem(RAD_BOW)->SetWindowTextW(L"Katana");
		CSouth.EnableWindow(false);
		break;
	case 1:
		SDialog="Look at those muscles!\r\n";
		SDialog+="You woke up as ";
		SDialog+=name;
		SDialog+=" the Viking!\r\n";
		SDialog+="There's a storm and you are on an ancient ship.\r\n";
		SDialog+="You just landed on a long shore.\r\n";
		SDialog+="A pigeon lands on your shoulder and you \r\n";
		SDialog+="receive a letter that informs you that there's \r\n";
		SDialog+="a treasure box in the middle of the desert!\r\n";
		SDialog+="As you are a greedy person,\r\n";
		SDialog+="you have to find that box!\r\n";
		me=new Viking();
		RWand.SetCheck(false);
		Location=new CPoint(0,4);
		CenterPix.LoadBitmapW(BIT_PIRATE);//load image
       pView.SetBitmap(CenterPix );//post image
	    GetDlgItem(RAD_WAND)->SetWindowTextW(L"Spear");
		GetDlgItem(RAD_SWORD)->SetWindowTextW(L"Sword");
		GetDlgItem(RAD_BOW)->SetWindowTextW(L"Axe");
		CWest.EnableWindow(false);
		break;
	case 2:
		SDialog=" Lucky you, you woke up as ";
		SDialog+=name;
		SDialog+=" the elf\r\n";
		SDialog+="in a flying castle! This is the place where\r\n";
		SDialog+="magic happens and doors are  opened \r\n when you say ";
		SDialog+="Alohomora.\r\n But life cannot be perfect and your\r\n";
		SDialog+="little elf sister got kidnapped! \r\n";
		SDialog+="As a  responsible brother you\r\n";
		SDialog+="should find her!\r\n";
		me=new Elf();
		RSword.SetCheck(false);
		Location=new CPoint(9,4);
		 CenterPix.LoadBitmapW(BIT_ELF);//load image
       pView.SetBitmap(CenterPix );//post image
	    GetDlgItem(RAD_WAND)->SetWindowTextW(L"Dagger");
		GetDlgItem(RAD_SWORD)->SetWindowTextW(L"Sword");
		GetDlgItem(RAD_BOW)->SetWindowTextW(L"Long Bow");
		CEast.EnableWindow(false);
		break;
	case 3:
		me=new Fairy();
		RBow.SetCheck(false);
		Location=new CPoint(4,9);
		SDialog="Wow, look at those shiny wings!\r\n";
		SDialog+="You woke up as ";
		SDialog+=name;
		SDialog+=" the fairy\r\n in the Goblin Valley!\r\n";
		SDialog+="Although it looks like the most peaceful place \r\n on earth,\r\n";
		SDialog+="filled with evergreen trees and fluffy clouds,\r\n ";
		SDialog+="the most cruel creatures \r\n";
		SDialog+="- THE GOBLINS - \r\n";
		SDialog+="live here and they are ruining others lives!\r\n";
		SDialog+="They stole the Barbie house of the princess of\r\n";
		SDialog+="the valley and she won't stop crying!\r\n Help her find it.\r\n";
		CenterPix.LoadBitmapW(BIT_FAIRY);//load image
        pView.SetBitmap(CenterPix );//post image
	    GetDlgItem(RAD_WAND)->SetWindowTextW(L"White Magic");
		GetDlgItem(RAD_SWORD)->SetWindowTextW(L"Armour Magic");
		GetDlgItem(RAD_BOW)->SetWindowTextW(L"Heal Magic");
		CNorth.EnableWindow(false);
		break;

}

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
GetDlgItem(RAD_HANDS)->SetWindowTextW(L"Hands");
GetDlgItem(RAD_BOW)->EnableWindow(false);
GetDlgItem(RAD_SWORD)->EnableWindow(false);
GetDlgItem(RAD_WAND)->EnableWindow(false);


CName.SetWindowTextW(name);
CInvetory.SetWindowTextW(L"You have nothing \r\n");
	}
	// TODO: Add your control notification handler code here
}


void CDNDPprojectDlg::OnBnClickedHands()
{
	if(newName)
	{
	ClassSelect=0;
	// TODO: Add your control notification handler code here
Output.SetWindowTextW(SDialog+L"You Selected Ninja \r\n High DEX low INT \r\n");
Dialog.SetFocus();
Dialog.SetSel(0,-1,false);

	}

}


void CDNDPprojectDlg::OnBnClickedWand()
{
		if(newName)
	{
	ClassSelect=1;
	// TODO: Add your control notification handler code here
	Output.SetWindowTextW(SDialog+L"You Selected Viking \r\n High STR low INT \r\n");
	Dialog.SetFocus();
Dialog.SetSel(0,-1,false);

		}
}


void CDNDPprojectDlg::OnBnClickedSword()
{
		if(newName)
	{
	ClassSelect=2;
	// TODO: Add your control notification handler code here
		Output.SetWindowTextW(SDialog+L"You Selected Elf \r\n High INT low STR \r\n");
		Dialog.SetFocus();
Dialog.SetSel(0,-1,false);

		}
}


void CDNDPprojectDlg::OnBnClickedBow()
{
		if(newName)
	{
	ClassSelect=3;
	// TODO: Add your control notification handler code here
		Output.SetWindowTextW(SDialog+L"You Selected Fairy \r\n High HP low  DEX \r\n");
		Dialog.SetFocus();
Dialog.SetSel(0,-1,false);

		}
}


void CDNDPprojectDlg::OnBnClickedNorth()
{
(*Location).y++;
if(Location->y ==9)
	CNorth.EnableWindow(false);
if(Location->y >0)
	CSouth.EnableWindow(true);
}


void CDNDPprojectDlg::OnBnClickedSouth()
{
(*Location).y--;
if(Location->y ==0)
	CSouth.EnableWindow(false);
if(Location->y <9)
	CNorth.EnableWindow(true);
}


void CDNDPprojectDlg::OnBnClickedEast()
{
(*Location).x++;
if(Location->x ==9)
	CEast.EnableWindow(false);
if(Location->x >0)
	CWest.EnableWindow(true);
}


void CDNDPprojectDlg::OnBnClickedWest()
{
(*Location).x--;
if(Location->x ==0)
	CWest.EnableWindow(false);
if(Location->x <9)
	CEast.EnableWindow(true);
}


void CDNDPprojectDlg::OnBnClickedRestart()
{
MsgAns = MessageBox(L"You are in the middle of a game. Are you sure?", 
L"Start Over?", MB_YESNOCANCEL|MB_ICONINFORMATION);
if(MsgAns==IDYES)
{
InitializeGlobals(); 
name="";
CName.SetWindowTextW(L"");
OnBnClickedStart();
CDef.SetWindowTextW(L"");
CDex.SetWindowTextW(L"");
CInt.SetWindowTextW(L"");
CStr.SetWindowTextW(L"");
CHp.SetWindowTextW(L"");
CNorth.EnableWindow(false);
CEast.EnableWindow(false);
CWest.EnableWindow(false);
CSouth.EnableWindow(false);

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
//pSaveName = ( CEdit * ) GetDlgItem( IDC_SaveName );
//pSavePassword = ( CEdit * ) GetDlgItem( IDC_SavePassword );
//bool success;
}

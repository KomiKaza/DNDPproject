
// DNDPprojectDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "Character.h"
#include "Monster.h"
#include "Elf.h"
#include "Viking.h"
#include "Ninja.h"
#include "Fairy.h"
#include "Goblin.h"
#include "Dragon.h"
#include "Cyclop.h"
#include "SaveDialog.h"
#include "DLGLoad.h"
#include "NinjaFactory.h"
#include "FairyFactory.h"
#include "ElfFactory.h"
#include "VikingFactory.h"
#include <fstream>


// CDNDPprojectDlg dialog
class CDNDPprojectDlg : public CDialogEx
{

// Construction
public:
	BOOL PreTranslateMessage(MSG * pMsg);
	CDNDPprojectDlg(CWnd* pParent = NULL);	// standard constructor
	CDNDPprojectDlg(bool * foods,int classSelect,Character *me,CWnd* pParent = NULL);	// standard constructor
	void afterLoad();
	void checkLocation();
	void Battle(int monstertype);
// Dialog Data
	enum { IDD = IDD_DNDPPROJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void updateHP();
	bool DoEvents();
	void NextAttack();
	void Died();
	void Won();
	void gameOver(int id);
	bool afterload;
	afx_msg void OnBnClickedQuit();
	CEdit Output;
	afx_msg void OnBnClickedStart();
	CEdit Dialog;
	CButton BtnStart;
	afx_msg void OnBnClickedGo();
	CEdit CHp;
	CEdit CStr;
	CEdit CInt;
	CEdit CDex;
	CEdit CDef;
	CStatic Cweapon;
	afx_msg void OnBnClickedHands();
	afx_msg void OnBnClickedWand();
	afx_msg void OnBnClickedSword();
	afx_msg void OnBnClickedBow();
	CButton CHeal;
	CButton RHands;
	CButton RWand;
	CButton RSword;
	CButton RBow;
	CButton CGo;
	CButton CNorth;
	CButton CWest;
	CButton CEast;
	CButton CSouth;
	afx_msg void OnBnClickedNorth();
	afx_msg void OnBnClickedSouth();
	afx_msg void OnBnClickedEast();
	afx_msg void OnBnClickedWest();
	CStatic PView;
	CBitmap IDFUCK;
	CStatic WATTT;
	CStatic CSFUCK;
	CStatic pView;
	CEdit CName;
	CEdit CInvetory;
	CButton CRestart;
	afx_msg void OnBnClickedRestart();
	afx_msg void OnBnClickedHelp();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedLoad();
	CButton CSaveG;
	CButton CEat;
	afx_msg void OnBnClickedEat();
private:
	CharacterFactory * characterFactory;
public:
	afx_msg void OnBnClickedAction();
	CButton CAction;
	afx_msg void OnBnClickedStopmusic();
};


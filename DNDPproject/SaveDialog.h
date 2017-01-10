#pragma once
#include "afxwin.h"
#include "Character.h"

// SaveDialog dialog

class SaveDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SaveDialog)

public:
	SaveDialog(CWnd* pParent = NULL);   // standard constructor
	SaveDialog(bool * foods,int classtype,Character * me,CWnd* pParent = NULL) ;
	virtual ~SaveDialog();

// Dialog Data
	enum { IDD = DLG_SAVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancelsave();
	afx_msg void OnBnClickedSavegame();
	CEdit CSaveName;
	CEdit CSavePass;
	Character * me;
	int ClassType;
	bool * foods;
};


// DNDPprojectDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CDNDPprojectDlg dialog
class CDNDPprojectDlg : public CDialogEx
{
// Construction
public:
	CDNDPprojectDlg(CWnd* pParent = NULL);	// standard constructor

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
};

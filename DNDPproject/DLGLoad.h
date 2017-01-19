#pragma once
#include "afxwin.h"

class CDNDPprojectDlg;

// DLGLoad dialog

class DLGLoad : public CDialogEx
{
	DECLARE_DYNAMIC(DLGLoad)

public:
	DLGLoad(CDNDPprojectDlg * dl,CWnd* pParent = NULL);   // standard constructor
	virtual ~DLGLoad();

// Dialog Data
	enum { IDD = DLG_LOAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLoadgame();
	afx_msg void OnBnClickedCancelload();
	CEdit CLoadName;
	CEdit CLoadPass;
	CDNDPprojectDlg * dlg;
};


// MFCpacpDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CMFCpacpDlg �Ի���
class CMFCpacpDlg : public CDialogEx
{
// ����
public:
	CMFCpacpDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCPACP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpenButton();
	afx_msg void OnBnClickedSaveButton();
	afx_msg void OnBnClickedOk();
	// pcap��ַ
	CString m_pfile;
//	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedWuButton();
	// ����·��
	CString m_path;

	afx_msg void OnEnChangeOpenEdit();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();

	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton5();
	// jindu
	CString m_jindu;
};

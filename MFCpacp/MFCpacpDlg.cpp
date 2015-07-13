
// MFCpacpDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCpacp.h"
#include "MFCpacpDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern void Butten1();
extern void Butten2();
extern void Butten3();
extern void Butten4();
extern int Filepath(char str[260], char str1[260]);


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCpacpDlg �Ի���



CMFCpacpDlg::CMFCpacpDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCpacpDlg::IDD, pParent)
	, m_pfile(_T(""))
	, m_path(_T(""))
	, m_jindu(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCpacpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_OPEN_EDIT, m_pfile);
	DDX_Text(pDX, IDC_SAVE_EDIT, m_path);
	DDX_Text(pDX, IDC_EDIT1, m_jindu);
	DDV_MaxChars(pDX, m_jindu, 100);
}

BEGIN_MESSAGE_MAP(CMFCpacpDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN_BUTTON, &CMFCpacpDlg::OnBnClickedOpenButton)
	ON_BN_CLICKED(IDC_SAVE_BUTTON, &CMFCpacpDlg::OnBnClickedSaveButton)
	ON_BN_CLICKED(IDOK, &CMFCpacpDlg::OnBnClickedOk)
//	ON_EN_CHANGE(IDC_EDIT1, &CMFCpacpDlg::OnEnChangeEdit1)
//ON_EN_CHANGE(IDC_EDIT2, &CMFCpacpDlg::OnEnChangeEdit2)
ON_BN_CLICKED(IDC_WU_BUTTON, &CMFCpacpDlg::OnBnClickedWuButton)
ON_BN_CLICKED(IDC_BUTTON2, &CMFCpacpDlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON3, &CMFCpacpDlg::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON4, &CMFCpacpDlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON6, &CMFCpacpDlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON5, &CMFCpacpDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CMFCpacpDlg ��Ϣ�������

BOOL CMFCpacpDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCpacpDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCpacpDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCpacpDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCpacpDlg::OnBnClickedOpenButton()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TCHAR szFilter[] = _T("pcap(*.pcap)|*.pcap|�����ļ�(*.*)|*.*||");
	// ������ļ��Ի���   
	CFileDialog fileDlg(TRUE, _T("pcap"), NULL, 0, szFilter, this);
	CString strFilePath;
	
	// ��ʾ���ļ��Ի���   
	if (fileDlg.DoModal() == IDOK)
	{
		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
		strFilePath = fileDlg.GetPathName();
		m_pfile = strFilePath;
		SetDlgItemText(IDC_OPEN_EDIT, strFilePath);
		//SetDlgItemText(IDC_EDIT2, strFilePath);
		
	}
}


void CMFCpacpDlg::OnBnClickedSaveButton()
{
	CFolderPickerDialog folderDlg(NULL, 0, this, 0);

	if (folderDlg.DoModal() == IDOK)
	{
		m_path = folderDlg.GetFolderPath();
		SetDlgItemText(IDC_SAVE_EDIT, m_path);
	}
	
	
	/*TCHAR szPath[MAX_PATH];     //���ѡ���Ŀ¼·�� 
	CString str;
	ZeroMemory(szPath, sizeof(szPath));
	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szPath;
	bi.lpszTitle = _T("��ѡ���ļ��У�");
	bi.ulFlags = 0;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;
	//����ѡ��Ŀ¼�Ի���

	LPITEMIDLIST lp = SHBrowseForFolder(&bi);

	if (lp)
	{
		//str.Format(_T("%s"), szPath);
		//AfxMessageBox(str);
		SHGetPathFromIDList(lp, szPath);
		m_path = szPath;
		SetDlgItemText(IDC_SAVE_EDIT, szPath);
	}
	/*else
		MessageBox(_T("��Ч��Ŀ¼��������ѡ��"));*/
}


void CMFCpacpDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CMFCpacpDlg::OnBnClickedWuButton()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	char p1[260] = "", p2[260] = "";
	int i = 0;
	int len1 = WideCharToMultiByte(CP_ACP, 0, m_pfile, -1, NULL, 0, NULL, NULL);
	int len2 = WideCharToMultiByte(CP_ACP, 0, m_path, -1, NULL, 0, NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, m_pfile, -1, p1, len1, NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, m_path, -1, p2, len2, NULL, NULL);
	
	//SetDlgltemText(IDC_EDIT1, m_jindu, "���ڽ����ļ�...");
	m_jindu = "���ڽ����ļ�...";
	UpdateData(false);
	UpdateWindow();
	i = Filepath(p1, p2);
	if (i==0)
		MessageBox(_T("���ļ�ʧ��"));
	m_jindu = "��ť1��������...";
	UpdateData(false);
	UpdateWindow();
	Butten1();
	m_jindu = "��ť1�����";
	UpdateData(false);
	UpdateWindow();
}





void CMFCpacpDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_jindu = "��ť2��������...";
	UpdateData(false);
	UpdateWindow();
	Butten2();
	m_jindu = "��ť2�����";
	UpdateData(false);
	UpdateWindow();
}


void CMFCpacpDlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_jindu = "��ť3��������...";
	UpdateData(false);
	UpdateWindow();
	Butten3();
	m_jindu = "��ť3�����";
	UpdateData(false);
	UpdateWindow();
}


void CMFCpacpDlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_jindu = "��ť4��������...";
	UpdateData(false);
	UpdateWindow();
	Butten4();
	m_jindu = "��ť4�����";
	UpdateData(false);
	UpdateWindow();
}




void CMFCpacpDlg::OnBnClickedButton6()
{

	CMFCpacpDlg::OnBnClickedWuButton();
	CMFCpacpDlg::OnBnClickedButton2();
	CMFCpacpDlg::OnBnClickedButton3();
	CMFCpacpDlg::OnBnClickedButton4();
	CMFCpacpDlg::OnBnClickedButton5();
	MessageBox(_T("һ�������ɹ�"));
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFCpacpDlg::OnBnClickedButton5()
{
	m_jindu = "��ť5��������...";
	UpdateData(false);
	UpdateWindow();
	Butten4();
	m_jindu = "��ť5�����";
	UpdateData(false);
	UpdateWindow();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

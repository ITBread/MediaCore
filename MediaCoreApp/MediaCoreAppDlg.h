
// MediaCoreAppDlg.h : ͷ�ļ�
//

#pragma once


// CMediaCoreAppDlg �Ի���
class CMediaCoreAppDlg : public CDialog
{
// ����
public:
	CMediaCoreAppDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MEDIACOREAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

private:
		CMenu m_Menu;
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPlaymenu();
	afx_msg void OnPlayStreammenu();
	afx_msg void OnStopmenu();
	DECLARE_MESSAGE_MAP()
};

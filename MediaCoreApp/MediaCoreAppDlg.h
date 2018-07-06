
// MediaCoreAppDlg.h : 头文件
//

#pragma once


// CMediaCoreAppDlg 对话框
class CMediaCoreAppDlg : public CDialog
{
// 构造
public:
	CMediaCoreAppDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MEDIACOREAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

private:
		CMenu m_Menu;
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPlaymenu();
	afx_msg void OnPlayStreammenu();
	afx_msg void OnStopmenu();
	DECLARE_MESSAGE_MAP()
};

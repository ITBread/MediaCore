
// MediaCoreApp.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMediaCoreAppApp:
// �йش����ʵ�֣������ MediaCoreApp.cpp
//

class CMediaCoreAppApp : public CWinAppEx
{
public:
	CMediaCoreAppApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMediaCoreAppApp theApp;
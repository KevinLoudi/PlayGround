
// DEMO1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDEMO1App:
// �йش����ʵ�֣������ DEMO1.cpp
//

class CDEMO1App : public CWinAppEx
{
public:
	CDEMO1App();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDEMO1App theApp;
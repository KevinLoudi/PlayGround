
// Calculator_v1.0.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
typedef unsigned int UINT;


// CCalculator_v10App:
// �йش����ʵ�֣������ Calculator_v1.0.cpp
//

class CCalculator_v10App : public CWinAppEx
{
public:
	CCalculator_v10App();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

class MCalculator
{
public:
	MCalculator(UINT n=0.0, UINT r=0.0):num_(n),res_(r){}
	~MCalculator(){}
	void set_num(UINT t_num){num_=t_num;}
	BOOL update_sum(){res_+=num_; return true;}
private:
	UINT num_;
	UINT res_;
};

extern CCalculator_v10App theApp;
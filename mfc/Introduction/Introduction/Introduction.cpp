// Introduction.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Introduction.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;

class CStudent: public CObject
{
public:
	CStudent();
	~CStudent();
	char* name_;
	char* level_;
	int age_;
};

//CWinApp provides all the basic functionality that an application needs.
struct CSimpleApp: public CWinApp
{
	//equipe functions
	BOOL InitInstance() {return TRUE;}
};

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����: MFC ��ʼ��ʧ��\n"));
		nRetCode = 1;
	}
	else
	{
		cout<<"Introduction of MFC\n";
	}

	system("pause");
	return nRetCode;
}

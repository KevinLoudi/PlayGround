
// Calculator_v1.0Dlg.h : ͷ�ļ�
//

#pragma once


// CCalculator_v10Dlg �Ի���
class CCalculator_v10Dlg : public CDialog
{
// ����
public:
	CCalculator_v10Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALCULATOR_V10_DIALOG };

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
	afx_msg void OnEnChangeEditInnum1();
	afx_msg void OnBnClickedButtonOne();
};

//--------------------------------------------------------------------
//           Mltithrd - �ܽd threads �����ͻP�u���v���]�w
//                      Top Studio * J.J.Hou
//
// �ɦW     : mltithrd.c
// �@��     : �J�T��
// �sĶ�p�� : �аѦ� mltithrd.mak
// �зN�ӷ� : "Multitask Windows NT" Chap6 (joel Powell/WAITE GROUP PRESS)
//
// ���� : ���Ҳ��� 5 �� threads�A�U�������P���u���v (priority)�F�C��
//        threads ���� 1000 ���j���A�j�������_ø�|��ΡA�N������i�סC
//        �H���[�� threads ���W�߱��p�H���u���v���P�ұa�Ӥ��v�T�C
//
//        �A�i�H��ܥH Sleep() �γ�¤� for loop ���� thread ���i��A
//        �o�]���U��A�[�� thread ���񱱨��v�C
//--------------------------------------------------------------------

#include <windows.h>
#include "mltithrd.h"

// �����ܼ�
HANDLE _hInst;
HANDLE _hWnd;
HANDLE _hThread[5];
UINT   _uDelayType=NODELAY;

//--------------------------------------------------------------------
// WinMain : �{���i�J�I
//--------------------------------------------------------------------
int APIENTRY WinMain (HANDLE hInstance, HANDLE hPrevInstance,
                      LPSTR lpCmdLine, int nCmdShow)
{
MSG  msg;
WNDCLASS wndclass;

   UNREFERENCED_PARAMETER(lpCmdLine);      // �קK�sĶ�ɪ�ĵ�i
   UNREFERENCED_PARAMETER(hPrevInstance);

   _hInst = hInstance;

   wndclass.style = 0;
   wndclass.lpfnWndProc = (WNDPROC)MainWndProc;
   wndclass.cbClsExtra = 0;
   wndclass.cbWndExtra = 0;
   wndclass.hInstance = hInstance;
   wndclass.hIcon = LoadIcon (hInstance, "Multi1Icon");
   wndclass.hCursor = LoadCursor (NULL, IDC_ARROW);
   wndclass.hbrBackground = GetStockObject (WHITE_BRUSH);
   wndclass.lpszMenuName = "Multi1Menu";
   wndclass.lpszClassName = "Multi1Class";

   RegisterClass(&wndclass);

   _hWnd = CreateWindow ("Multi1Class",
                         "Thread Priority Example",
                         WS_OVERLAPPED | WS_SYSMENU,
                         0, 0, 400, 250,
                         NULL,
                         NULL,
                         hInstance,
                         NULL);

   ShowWindow(_hWnd, nCmdShow);

   while (GetMessage (&msg, NULL, 0, 0)) {
      TranslateMessage (&msg);
      DispatchMessage (&msg);
   }
   return (msg.wParam);
}
//--------------------------------------------------------------------
// MainWndProc - �D�����禡
//--------------------------------------------------------------------
LONG APIENTRY MainWndProc (HWND hWnd, UINT message,
                           UINT wParam, LONG lParam)
{
int    i;
DWORD  ThreadID[5];
static HMENU  hMenu;
static HANDLE hMasterThread;
static DWORD  ThreadArg[5] = {HIGHEST_THREAD,    // 0x00
                              ABOVE_AVE_THREAD,  // 0x3F
                              NORMAL_THREAD,     // 0x7F
                              BELOW_AVE_THREAD,  // 0xBF
                              LOWEST_THREAD      // 0xFF
                             };    // �Ψӽվ�|����C��

 switch (message) {
   case WM_CREATE:
      hMenu = GetMenu (hWnd);

      // ���o primary thread handle �ó]���̰� priority
      hMasterThread = GetCurrentThread();
      SetThreadPriority(hMasterThread, THREAD_PRIORITY_HIGHEST);

      for(i=0; i<5; i++)   // ���� 5 �� threads
          _hThread[i] = CreateThread(NULL,
                                    0,
                                    (LPTHREAD_START_ROUTINE)ThreadProc,
                                    &ThreadArg[i],
                                    CREATE_SUSPENDED,
                                    &ThreadID[i]);
      // �]�w thread priorities
      SetThreadPriority(_hThread[0], THREAD_PRIORITY_HIGHEST);
      SetThreadPriority(_hThread[1], THREAD_PRIORITY_ABOVE_NORMAL);
      SetThreadPriority(_hThread[2], THREAD_PRIORITY_NORMAL);
      SetThreadPriority(_hThread[3], THREAD_PRIORITY_BELOW_NORMAL);
      SetThreadPriority(_hThread[4], THREAD_PRIORITY_LOWEST);
      return (0);

   case WM_COMMAND:
      switch (LOWORD(wParam))
      {
         case IDM_RESUME:       // �� threads �}�l����
            EnableMenuItem(hMenu, IDM_RESUME, MF_BYCOMMAND | MF_GRAYED);
            EnableMenuItem(hMenu, IDM_SUSPEND, MF_BYCOMMAND | MF_ENABLED);
            DrawMenuBar(hWnd);
            for (i=0; i<5; i++)
                ResumeThread(_hThread[i]);   // �Ұ� threads ������
            return (0);

         case IDM_SUSPEND:  // �Ȱ� threads ������
            for (i=0; i<5; i++)
                SuspendThread(_hThread[i]);   // �Ȱ� threads ������
            EnableMenuItem(hMenu, IDM_SUSPEND, MF_BYCOMMAND | MF_GRAYED);
            EnableMenuItem(hMenu, IDM_RESUME, MF_BYCOMMAND | MF_ENABLED);
            DrawMenuBar(hWnd);
            return (0);

         case IDM_FOR:    // �H for loop ���� thread ������
            _uDelayType = FORLOOPDELAY;
            EnableMenuItem(hMenu, IDM_FOR, MF_BYCOMMAND | MF_GRAYED);
            EnableMenuItem(hMenu, IDM_SLEEP, MF_BYCOMMAND | MF_ENABLED);
            EnableMenuItem(hMenu, IDM_NODELAY, MF_BYCOMMAND | MF_ENABLED);
            DrawMenuBar(hWnd);
            return (0);

         case IDM_SLEEP:  // �H Sleep() ���� thread ������
            _uDelayType = SLEEPDELAY;
            EnableMenuItem(hMenu, IDM_SLEEP, MF_BYCOMMAND | MF_GRAYED);
            EnableMenuItem(hMenu, IDM_FOR, MF_BYCOMMAND | MF_ENABLED);
            EnableMenuItem(hMenu, IDM_NODELAY, MF_BYCOMMAND | MF_ENABLED);
            DrawMenuBar(hWnd);
            return (0);

         case IDM_NODELAY:  // ������ thread ������
            _uDelayType = NODELAY;
            EnableMenuItem(hMenu, IDM_NODELAY, MF_BYCOMMAND | MF_GRAYED);
            EnableMenuItem(hMenu, IDM_FOR, MF_BYCOMMAND | MF_ENABLED);
            EnableMenuItem(hMenu, IDM_SLEEP, MF_BYCOMMAND | MF_ENABLED);
            DrawMenuBar(hWnd);
            return (0);

         default:
            return (0);
      }

   case WM_DESTROY :
      for(i=0; i<5; i++)
          TerminateThread(_hThread[i], 0);   // �פ� threads
      PostQuitMessage (0);
      return (0);

   default:
      return DefWindowProc (hWnd, message, wParam, lParam);
   }
   return (0L);
}
//--------------------------------------------------------------------
// ThreadProc() - ���Ҥ� 5 �� threads �@�Τ� thread procedure
//--------------------------------------------------------------------
VOID ThreadProc(DWORD *ThreadArg)
{
RECT rect;
HDC  hDC;
HANDLE hBrush, hOldBrush;
DWORD dwThreadHits = 0;
char  cBuf[80];
int   iThreadNo, i;

   GetClientRect (_hWnd, &rect);
   hDC = GetDC (_hWnd);
   hBrush = CreateSolidBrush(RGB(*(ThreadArg), *(ThreadArg), *(ThreadArg)));  // �ܤƵe���C��
   hOldBrush = SelectObject(hDC, hBrush);

   switch (*ThreadArg) {
     case HIGHEST_THREAD   : iThreadNo = 0; break;
     case ABOVE_AVE_THREAD : iThreadNo = 1; break;
     case NORMAL_THREAD    : iThreadNo = 2; break;
     case BELOW_AVE_THREAD : iThreadNo = 3; break;
     case LOWEST_THREAD    : iThreadNo = 4; break;
   }

   // ��� thread ���X�Ψ��u���v (priority)
   wsprintf(cBuf, "T%d", iThreadNo);
   TextOut(hDC, *(ThreadArg), rect.bottom-150, cBuf, lstrlen(cBuf));
   wsprintf(cBuf, "P=%d", GetThreadPriority(_hThread[iThreadNo]));
   TextOut(hDC, *(ThreadArg), rect.bottom-130, cBuf, lstrlen(cBuf));

   do
   {
     dwThreadHits++;       // �p�ƾ�

     // �e�X�|��ΡA�N�� thread ���i��
     Rectangle(hDC, *(ThreadArg), rect.bottom-(dwThreadHits/10),
               *(ThreadArg)+0x40, rect.bottom);

     // ����...
     if (_uDelayType == SLEEPDELAY)
         Sleep(10);
     else if (_uDelayType == FORLOOPDELAY)
         for (i=0; i<30000; i++);
     else // _uDelayType == NODELAY)
         {   }
   } while (dwThreadHits < 1000);      // ���j  1000 ��

   hBrush = SelectObject(hDC, hOldBrush);   // ��_�e���C��
   DeleteObject (hBrush);
   ReleaseDC (_hWnd, hDC);
}
//------------------------- end of file ------------------------------

#ifndef _CL_TESTWINDOWS_H_
#define _CL_TESTWINDOWS_H_

#include"IWindows.h"

class CL_TestWindows : public IWindows
{
protected:
	WNDCLASSEX m_wc;
	HWND m_hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	
	virtual LRESULT CALLBACK PaintWndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
	virtual LRESULT CALLBACK KeyBoardWndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
	virtual LRESULT CALLBACK MouseWndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
	
	virtual int MyRegisterClassEx();
	virtual int RegisterFunc();
	
public:
	CL_TestWindows(int pcbClsExtra, int pcbWndExtra, int pcbSize, HINSTANCE phInstance, HCURSOR phCursor, HBRUSH phbrBackground,
			LPCSTR plpszClassName, HICON phIcon, HICON phIconSm);
	virtual int MyCreateWindowEx(DWORD pdwExStyle, LPCTSTR plpClassName, LPCTSTR plpWindowName, DWORD pdwStyle, int px, int py, int pnWidth,
						int pnHeight, HWND phWndParent, HMENU phMenu, HINSTANCE phInstance, LPVOID plpParam);
	virtual int RunWindows(MSG* pmsg);
	virtual ~CL_TestWindows();
	
	virtual int SetStyle(UINT pstyle);
	virtual int SetMenuName(LPCSTR plpszMenuName);
};

#endif
#include"CL_TestWindows.h"

CL_TestWindows::CL_TestWindows(int pcbClsExtra, int pcbWndExtra, int pcbSize, HINSTANCE phInstance, HCURSOR phCursor, HBRUSH phbrBackground,
			LPCSTR plpszClassName, HICON phIcon, HICON phIconSm):m_hwnd(0)
{
	/* zero out the struct and set the stuff we want to modify */
	memset(&m_wc, 0, sizeof(m_wc));
	m_wc.cbSize		 = pcbSize;
	m_wc.lpfnWndProc = IWindows::WndProc; /* This is where we will send messages to */
	m_wc.hInstance	 = phInstance;
	m_wc.hCursor	 = phCursor;
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	m_wc.hbrBackground = phbrBackground;
	m_wc.lpszClassName = plpszClassName;
	m_wc.hIcon		   = phIcon; /* Load a standard icon */
	m_wc.hIconSm	   = phIconSm; /* use the name "A" to use the project icon */
	
	m_wc.cbClsExtra    = pcbClsExtra;
	m_wc.cbWndExtra    = pcbWndExtra;
}

int CL_TestWindows::MyRegisterClassEx()
{
	if(!RegisterClassEx(&m_wc))
	{
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return -1;
	}
	return 0;
}

int CL_TestWindows::MyCreateWindowEx(DWORD pdwExStyle, LPCTSTR plpClassName, LPCTSTR plpWindowName, DWORD pdwStyle, int px, int py, int pnWidth,
						       int pnHeight, HWND phWndParent, HMENU phMenu, HINSTANCE phInstance, LPVOID plpParam)
{
	if(MyRegisterClassEx() == -1)
	{
		return -1;
	}
	m_hwnd = CreateWindowEx(pdwExStyle, plpClassName, plpWindowName, pdwStyle, px, py,
							pnWidth, pnHeight, phWndParent, phMenu, phInstance, plpParam);
	if(m_hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION|MB_OK);
		return -1;
	}
	m_MapTable.insert(pair<HWND, IWindows*>(m_hwnd, (IWindows*)this));
	RegisterFunc();
	return 0;
}

int CL_TestWindows::RegisterFunc()
{
	m_MessageFunc.insert(pair<UINT, WindowProc>(WM_NCMOUSEMOVE, (WindowProc)&CL_TestWindows::MouseWndProc));
	m_MessageFunc.insert(pair<UINT, WindowProc>(WM_NCLBUTTONDOWN, (WindowProc)&CL_TestWindows::MouseWndProc));
	m_MessageFunc.insert(pair<UINT, WindowProc>(WM_NCLBUTTONUP, (WindowProc)&CL_TestWindows::MouseWndProc));
	m_MessageFunc.insert(pair<UINT, WindowProc>(WM_KEYDOWN, (WindowProc)&CL_TestWindows::KeyBoardWndProc));
	m_MessageFunc.insert(pair<UINT, WindowProc>(WM_CHAR, (WindowProc)&CL_TestWindows::KeyBoardWndProc));
	m_MessageFunc.insert(pair<UINT, WindowProc>(WM_KEYUP, (WindowProc)&CL_TestWindows::KeyBoardWndProc));
	m_MessageFunc.insert(pair<UINT, WindowProc>(WM_PAINT, (WindowProc)&CL_TestWindows::PaintWndProc));
	return 0;
}

int CL_TestWindows::RunWindows(MSG* pmsg)
{
	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(pmsg, NULL, 0, 0) > 0)
	{ /* If no error is received... */
		TranslateMessage(pmsg); /* Translate key codes to chars if present */
		DispatchMessage(pmsg); /* Send it to WndProc */
	}
}

CL_TestWindows::~CL_TestWindows()
{
	m_MapTable.clear();
	m_MessageFunc.clear();
}

int CL_TestWindows::SetStyle(UINT pstyle)
{
	m_wc.style = pstyle;
	return 0;
}

int CL_TestWindows::SetMenuName(LPCSTR plpszMenuName)
{
	m_wc.lpszMenuName = plpszMenuName;
	return 0;
}

LRESULT CALLBACK CL_TestWindows::PaintWndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

LRESULT CALLBACK CL_TestWindows::KeyBoardWndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

LRESULT CALLBACK CL_TestWindows::MouseWndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
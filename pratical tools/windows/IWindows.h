#ifndef _IWINDOWS_H_
#define _IWINDOWS_H_

#include<windows.h>
#include<map>

using namespace std;

class IWindows;

typedef LRESULT (CALLBACK IWindows::*WindowProc)(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);

class IWindows
{
protected:
	static map<HWND, IWindows*> m_MapTable;
	static multimap<UINT, WindowProc> m_MessageFunc;
	
	virtual int RegisterFunc() = 0;
	virtual LRESULT CALLBACK MainWndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);

public:
	IWindows();
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
	virtual ~IWindows();
};

#endif
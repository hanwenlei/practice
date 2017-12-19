#include"IWindows.h"

map<HWND, IWindows*> IWindows::m_MapTable;

multimap<UINT, WindowProc> IWindows::m_MessageFunc;

IWindows::IWindows(){}

IWindows::~IWindows(){}

/* This is where all the input to the window goes to */
LRESULT CALLBACK IWindows::WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
		{
			map<HWND, IWindows*>::iterator it;
			it = m_MapTable.find(hwnd);
			return (it->second)->MainWndProc(hwnd, Message, wParam, lParam);
		}
	}
}

LRESULT CALLBACK IWindows::MainWndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	multimap<UINT, WindowProc>::iterator it;
	it = m_MessageFunc.find(Message);
	if(it != m_MessageFunc.end())
	{
		(this->*(it->second))(hwnd, Message, wParam, lParam);
		return 0;
	}
	return DefWindowProc(hwnd, Message, wParam, lParam);
}
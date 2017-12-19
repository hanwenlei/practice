#include"CL_TestWindows.h"

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg; /* A temporary location for all messages */
	CL_TestWindows* test = new CL_TestWindows(0, 0, sizeof(WNDCLASSEX), hInstance, LoadCursor(NULL, IDC_ARROW), (HBRUSH)(COLOR_WINDOW + 1),
											"WindowClass", LoadIcon(NULL, IDI_APPLICATION), LoadIcon(NULL, IDI_APPLICATION));
	
//	/* zero out the struct and set the stuff we want to modify */
//	memset(&wc,0,sizeof(wc));
//	wc.cbSize		 = sizeof(WNDCLASSEX);
//	wc.lpfnWndProc	 = IWindows::WndProc; /* This is where we will send messages to */
//	wc.hInstance	 = hInstance;
//	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
//	
//	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
//	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wc.lpszClassName = "WindowClass";
//	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
//	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	int flag = test->MyCreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, /* x */
			CW_USEDEFAULT, /* y */
			640, /* width */
			480, /* height */
			NULL,NULL,hInstance,NULL);
	if(flag == -1)
	{
		return -1;
	}
	test->RunWindows(&msg);
	delete test;
	return msg.wParam;
}
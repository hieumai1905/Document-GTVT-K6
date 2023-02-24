// CreateWindow.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "CreateWindow.h"

#define MAX_LOADSTRING 100
#define ID_EDIT_NAME 20
#define ID_BUTTON_DEMO 21
#define ID_CHECKBOX_DEMO 19
#define ID_EDIT_HH 22

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND hEditName, hButton, cbState, editHT;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_CREATEWINDOW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CREATEWINDOW));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CREATEWINDOW));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_CREATEWINDOW);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE: {
		hEditName = CreateWindow(_T("edit"), L"Edit name...", WS_CHILD | WS_VISIBLE | WS_BORDER, 210, 100, 200, 50, hWnd, (HMENU)ID_EDIT_NAME, NULL, NULL);
		hButton = CreateWindow(_T("button"), L"CLICK HERE", WS_CHILD | WS_VISIBLE | WS_BORDER, 50, 50, 100, 50, hWnd, (HMENU)ID_BUTTON_DEMO, NULL, NULL);
		cbState = CreateWindow(_T("button"), L"Check or Uncheck", WS_CHILD | WS_VISIBLE | WS_BORDER | BS_RIGHT|BS_CHECKBOX, 500, 300, 200, 30, hWnd, (HMENU)ID_CHECKBOX_DEMO, NULL, NULL);
		editHT = CreateWindow(_T("edit"), L"Edit name...", WS_CHILD | WS_VISIBLE | WS_BORDER |ES_MULTILINE|ES_AUTOHSCROLL| ES_AUTOVSCROLL |WS_VSCROLL, 610, 100, 400, 200, hWnd, (HMENU)ID_EDIT_NAME, NULL, NULL);
		SendMessage(hButton, BM_SETSTATE, 0, 0);
		break;
	}
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case ID_BUTTON_DEMO: {
			int wmSubId = HIWORD(wParam);
			switch (wmSubId) {
			case BN_CLICKED: {
				SendMessage(hEditName, BN_SETFOCUS, 1, 0);
				break;
			}
			}
			break;
		}
		case ID_CHECKBOX_DEMO: {
			// lay ra trang thai 
			bool check = SendMessage(cbState, BM_GETCHECK, 0, 0);
			if (check) {
				// set uncheck
				SendMessage(cbState, BM_SETCHECK, 0, 0);
			}
			else {
				SendMessage(cbState, BM_SETCHECK, 1, 0);
			}
			break;
		}
		case ID_EDIT_NAME: {
			UINT idEdit = LOWORD(wParam);
			TCHAR str = HIWORD(wParam);
			HWND hWndSub = (HWND)lParam;
			int id = GetDlgCtrlID(hWndSub);
			break;
		}
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

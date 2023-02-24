// ChildrenWindow.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "ChildrenWindow.h"

#define ID_EDITHT 1
#define ID_BUTTONOK 3
#define ID_BUTTONCLOSE 2
#define MAX_LOADSTRING 100
#define ID_CHECK1 5
#define ID_CHECK2 6

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND editHT, buttonOK, buttonClose, ckb1, ckb2;

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
	LoadStringW(hInstance, IDC_CHILDRENWINDOW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CHILDRENWINDOW));

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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CHILDRENWINDOW));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_CHILDRENWINDOW);
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
	case WM_CLOSE:
		SendMessage(buttonClose, BM_CLICK, 0, 0);
		break;

	case WM_CREATE:
		editHT = CreateWindow(TEXT("EDIT"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 10, 200, 20, hWnd, (HMENU)ID_EDITHT, NULL, NULL);
		buttonOK = CreateWindow(TEXT("BUTTON"), TEXT("oke"), WS_CHILD | WS_VISIBLE | BS_BOTTOM, 255, 50, 100, 20, hWnd, (HMENU)ID_BUTTONOK, NULL, NULL);
		buttonClose = CreateWindow(TEXT("BUTTON"), TEXT("close"), WS_CHILD | WS_VISIBLE | BS_BOTTOM, 400, 50, 100, 20, hWnd, (HMENU)ID_BUTTONCLOSE, NULL, NULL);
		ckb1 = CreateWindow(TEXT("BUTTON"), TEXT("checkbox1"), WS_CHILD | WS_VISIBLE | BS_CHECKBOX, 500, 500, 100, 50, hWnd, (HMENU)ID_CHECK1, NULL, NULL);
		ckb2 = CreateWindow(TEXT("BUTTON"), TEXT("checkbox2"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 500, 600, 100, 50, hWnd, (HMENU)ID_CHECK2, NULL, NULL);
		ckb2 = CreateWindow(TEXT("BUTTON"), TEXT("checkbox2"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 500, 600, 100, 50, hWnd, (HMENU)ID_CHECK2, NULL, NULL);
		break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		int event = HIWORD(wParam);
		static int resultShopping, len, count = 0;
		static TCHAR ht[30];
		// Parse the menu selections:
		switch (wmId)
		{
		case ID_BUTTONOK:
			len = GetWindowText(editHT, ht, 30);
			if (len == 0) {
				MessageBox(NULL, TEXT("Nhap ten: "), TEXT("Warning"), MB_OK);
				SetFocus(editHT);
				return 0;
			}
			// check option
			
			break;
		case ID_CHECK1:
			if (SendMessage(ckb1, BM_GETCHECK, 0, 0) == TRUE) {
				SendMessage(ckb1, BM_SETCHECK, 0, 0);
			}
			else SendMessage(ckb1, BM_SETCHECK, 1, 0);
			break;
		case ID_BUTTONCLOSE:
			switch (event) {
			case BN_CLICKED:
				if (MessageBox(NULL, TEXT("Are you sure to close?"), TEXT("Close"), MB_YESNO) == IDYES)
					PostQuitMessage(0);
				break;
			}
			break;
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

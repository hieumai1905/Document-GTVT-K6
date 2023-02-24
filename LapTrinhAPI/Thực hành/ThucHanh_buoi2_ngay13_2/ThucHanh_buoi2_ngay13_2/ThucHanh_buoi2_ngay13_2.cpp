// ThucHanh_buoi2_ngay13_2.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "ThucHanh_buoi2_ngay13_2.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
HWND groupCH, groupMN, groupDV, btnMNColor[5], btnDVColor[5], btnHinh[2];
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
	LoadStringW(hInstance, IDC_THUCHANHBUOI2NGAY132, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_THUCHANHBUOI2NGAY132));

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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_THUCHANHBUOI2NGAY132));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_THUCHANHBUOI2NGAY132);
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
	static int xRight, xLeft, yBottom, yTop, Hinh, DV, MN;
	static HDC hdcDraw, hdcDraw1;
	static int x = 35, y = 35, x1 = 220, y1 = 35, x2 = 505, y2 = 35;
	static HBRUSH hBrush;

	static HPEN hPen;
	COLORREF color[5] = { RGB(255,0,0),RGB(0,255,0),RGB(0,0,255),RGB(255,255,0),RGB(0,255,255) };

	switch (message)
	{
	case WM_CREATE:
		groupCH = CreateWindow(TEXT("button"), TEXT("Chọn hình"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 30, 10, 180, 85, hWnd, NULL, NULL, NULL);
		groupMN = CreateWindow(TEXT("button"), TEXT("Chọn màu"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 215, 10, 280, 85, hWnd, NULL, NULL, NULL);
		groupCH = CreateWindow(TEXT("button"), TEXT("Chọn màu nền"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 500, 10, 280, 85, hWnd, NULL, NULL, NULL);
		for (int i = 0; i < 2; i++) {
			btnHinh[i] = CreateWindow(TEXT("button"), TEXT(""), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, x, y, 80, 50, hWnd, (HMENU)(5 * 2 + i), NULL, NULL);
			x += 85;
		}
		for (int i = 0; i < 5; i++) {
			btnMNColor[i] = CreateWindow(TEXT("button"), TEXT(""), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, x1, y1, 50, 50, hWnd, (HMENU)i, NULL, NULL);
			x1 += 55;
			btnDVColor[i] = CreateWindow(TEXT("button"), TEXT(""), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, x2, y2, 50, 50, hWnd, (HMENU)(5 + i), NULL, NULL);
			x2 += 55;
		}
		break;
	case WM_LBUTTONDOWN:
		xLeft = LOWORD(lParam);
		yTop = HIWORD(lParam);
		break;
	case WM_LBUTTONUP:
		xRight = LOWORD(lParam);
		yBottom = HIWORD(lParam);
		hdcDraw = GetDC(hWnd);
		SelectObject(hdcDraw, hBrush);
		SelectObject(hdcDraw, hPen);
		switch (Hinh) {
		case 10:
			Rectangle(hdcDraw, xLeft, yTop, xRight, yBottom);
			break;

		case 11:
			Ellipse(hdcDraw, xLeft, yTop, xRight, yBottom);
			break;

		}
		break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case 10:
		case 11:
			Hinh = wmId;
			break;
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			hBrush = CreateSolidBrush(color[wmId]);
			break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			hPen = CreatePen(PS_SOLID, 2, color[wmId - 5]);
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
		/*HDC hdc = BeginPaint(hWnd, &ps);*/
		// TODO: Add any drawing code that uses hdc here...
		HBRUSH hBrush;

		hdcDraw = BeginPaint(btnHinh[0], &ps);
		Rectangle(hdcDraw, 10, 10, 70, 40);
		hdcDraw = BeginPaint(btnHinh[1], &ps);
		Ellipse(hdcDraw, 10, 10, 70, 40);
		for (int i = 0; i < 5; i++) {
			hBrush = CreateSolidBrush(color[i]);
			hdcDraw = BeginPaint(btnMNColor[i], &ps);
			SelectObject(hdcDraw, hBrush);
			Rectangle(hdcDraw, 2, 2, 48, 48);

			hdcDraw1 = BeginPaint(btnDVColor[i], &ps);
			SelectObject(hdcDraw1, hBrush);
			Rectangle(hdcDraw1, 2, 2, 48, 48);

			EndPaint(btnMNColor[i], &ps);
			EndPaint(btnDVColor[i], &ps);
		}
		HDC hdc = BeginPaint(hWnd, &ps);

		EndPaint(hWnd, &ps);
		InvalidateRect(hWnd, NULL, FALSE);
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

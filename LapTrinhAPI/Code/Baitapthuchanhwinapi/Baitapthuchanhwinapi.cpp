// Baitapthuchanhwinapi.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Baitapthuchanhwinapi.h"

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
	LoadStringW(hInstance, IDC_BAITAPTHUCHANHWINAPI, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BAITAPTHUCHANHWINAPI));

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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BAITAPTHUCHANHWINAPI));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	// thay ten menu vao day
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDR_MENU1);
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

	
	static HPEN hPen;
	static HBRUSH hBrush;
	static int penStyle = PS_SOLID;
	static COLORREF  penColor = RGB(255, 25, 0);
	static POINT point[3];
	static HDC hdc;

	static int xLeft, yTop, xRight, yBotton;
	int wmId = LOWORD(wParam);
	switch (message)
	{
	case WM_COMMAND:
	{
		// Parse the menu selections:
		switch (wmId)
		{

		case background_yellow:
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			break;

		case border_lien:
			penStyle = PS_DASH;
			hPen = CreatePen(penStyle, 1, penColor);
			break;

		case border_dut:
			hPen = CreatePen(penStyle, 1, penColor);
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
	case WM_LBUTTONDOWN:
		xLeft = LOWORD(lParam);
		yTop = HIWORD(lParam);
		break;

	case WM_LBUTTONUP:
		xRight = LOWORD(lParam);
		yBotton = HIWORD(lParam);

		// ve tam giac can
		point[0].x = xLeft;
		point[0].y = yBotton;
		point[1].x = xRight;
		point[1].y = yBotton;
		point[2].x = xLeft + (xRight - xLeft) / 2;
		point[2].y = yTop;

		hdc = GetDC(hWnd);
		SelectObject(hdc, CreatePen(PS_DASHDOT, 1, RGB(22, 22, 22)));
		SelectObject(hdc, CreateSolidBrush(RGB(225, 0, 0)));
		Polygon(hdc, point, 3);
		ReleaseDC(hWnd, hdc);


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

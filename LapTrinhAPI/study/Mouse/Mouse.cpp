// Mouse.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Mouse.h"

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
	LoadStringW(hInstance, IDC_MOUSE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MOUSE));

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

	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;

	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MOUSE));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MOUSE);
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
	static POINT point[1000];
	static int n = 0;
	static HDC hdc;
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		// hien thi vi tri nhap chuot
		/*POINT point;
		GetCursorPos(&point);
		TCHAR str[100];
		wsprintf(str, TEXT("Vi tri nhap chuot la: (%d, %d)"), point.x, point.y);
		MessageBox(hWnd, L"Vua nhap chuot trai 1 click", L"show", MB_OK);*/

		// kiem tra xem nguoi dung co nhap ctrl khong neu co show ra man hinh
		//if (GetKeyState(VK_CONTROL) < 0)
		//{
		//	MessageBox(hWnd, L"Vua nhap chuot trai 1 click va nhan ctrl", L"show", MB_OK);
		//}
		//// GetKeyState(VK_SHIFT) dùng để kiểm tra xem người dùng có nhấn phím shift hay không nếu có thì trả về giá trị âm

		//// kiem tra xem nguoi dung co nhap shift khong neu co show ra man hinh
		//if (GetKeyState(VK_SHIFT) < 0)
		//{
		//	MessageBox(hWnd, L"Vua nhap chuot trai 1 click va nhan shift", L"show", MB_OK);
		//}
		//GetCursorPos(&point[n]);
		point[n].x = LOWORD(lParam);
		point[n].y = HIWORD(lParam);
		hdc = GetDC(hWnd);
		SetPixel(hdc, point[n].x, point[n].y, RGB(255, 0, 0));
		ReleaseDC(hWnd, hdc);
		n++;
		break;
	}
	case WM_RBUTTONDOWN:
	{
		hdc = GetDC(hWnd);

		// noi tung doi 1 cac diem voi nhau
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++) {
				MoveToEx(hdc, point[i].x, point[i].y, NULL);
				LineTo(hdc, point[j].x, point[j].y);
			}
		}

		ReleaseDC(hWnd, hdc);
		break;
	}
	case WM_LBUTTONDBLCLK:
	{
		//MessageBox(hWnd, L"Vua nhap chuot trai 2 click", L"show", MB_OK);

		// xoá toan bo mien thao tac
		RECT rect;
		GetClientRect(hWnd, &rect);		// lay ra kich thuoc cua cua so
		rect.bottom = rect.bottom / 2;
		InvalidateRect(hWnd, &rect, true);		// xoa mien thao tac 
		n = 0;



	}
	break;
	//case WM_LBUTTONDOWN:
	//{/*
	//	TCHAR str[100];
	//	// lay ra so nut chuot
	//	wsprintf(str, TEXT("So chuot la: %d", GetSystemMetrics(SM_CMOUSEBUTTONS)));
	//	MessageBox(hWnd, str, L"Thong bao", MB_OK);*/
	//}break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
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

// Check21_2.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Check21_2.h"

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
INT_PTR CALLBACK    ShowManager(HWND, UINT, WPARAM, LPARAM);

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
	LoadStringW(hInstance, IDC_CHECK212, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CHECK212));

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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CHECK212));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_CHECK212);
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
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case ID_QLSV:
		{
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_QLSV), hWnd, ShowManager);
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

INT_PTR CALLBACK ShowManager(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND editName, lstSV, btnAdd, btnEdit, btnDel, btnFind, btnExit;
	static TCHAR name[30];
	static int selectIndex = -1, iSearch = -1;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		editName = GetDlgItem(hDlg, IDC_EDIT_NAME);
		lstSV = GetDlgItem(hDlg, IDC_LIST);
		btnAdd = GetDlgItem(hDlg, IDC_BTNADD);
		btnEdit = GetDlgItem(hDlg, IDC_BTNEDIT);
		btnDel = GetDlgItem(hDlg, IDC_BTNDEL);
		btnFind = GetDlgItem(hDlg, IDC_BTNFIND);
		btnExit = GetDlgItem(hDlg, IDC_BTNEXIT);
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		int wmId = LOWORD(wParam);
		switch (wmId) {
		case IDC_BTNEXIT: {
			if (MessageBox(NULL, L"Bạn có muốn thoát không?", L"Thông báo", MB_YESNO | MB_ICONQUESTION) == IDYES) {
				EndDialog(hDlg, LOWORD(wParam));
				return (INT_PTR)TRUE;
			}
			break;
		}
		case IDC_BTNADD: {
			GetWindowText(editName, name, 30);
			if (GetWindowTextLength(editName) == 0) {
				MessageBox(NULL, L"Dữ liệu không được để trống!", L"Cảnh bảo", MB_OK);
				SetFocus(editName);
			}
			else {
				SendMessage(lstSV, LB_INSERTSTRING, -1, (LPARAM)name);
				SetWindowText(editName, L"");
			}
			break;
			return (INT_PTR)TRUE;
		}
		case IDC_LIST: {
			switch (HIWORD(wParam)) {
			case LBN_SELCHANGE:
				EnableWindow(btnDel, TRUE);
				EnableWindow(btnEdit, TRUE);
				selectIndex = SendMessage(lstSV, LB_GETCURSEL, 0, 0);
				SendMessage(lstSV, LB_GETTEXT, selectIndex, (LPARAM)name);
				SetWindowText(editName, name);
				break;
			}
			return (INT_PTR)TRUE;
		}
		case IDC_BTNEDIT: {
			selectIndex = SendMessage(GetDlgItem(hDlg, IDC_LIST), LB_GETCURSEL, 0, 0);
			if (GetWindowText(GetDlgItem(hDlg, IDC_EDIT_NAME), name, 30) == 0) {
				MessageBox(NULL, TEXT("Bạn phải nhập tên"), TEXT(""), MB_OK);
				SetFocus(GetDlgItem(hDlg, IDC_EDIT_NAME));
				return 0;
			}
			selectIndex = SendMessage(GetDlgItem(hDlg, IDC_LIST), LB_GETCURSEL, 0, 0);
			SendMessage(GetDlgItem(hDlg, IDC_LIST), LB_DELETESTRING, selectIndex, 0);
			SendMessage(GetDlgItem(hDlg, IDC_LIST), LB_INSERTSTRING, selectIndex, (LPARAM)name);
			SetWindowText(editName, L"");
			break;
			return (INT_PTR)TRUE;
		}
		case IDC_BTNFIND: {
			iSearch = -1;
			if (GetWindowText(editName, name, 30) == 0) {
				MessageBox(NULL, TEXT("Bạn phải nhập tên"), TEXT(""), MB_OK);
				SetFocus(editName);
				return 0;
			}
			iSearch = SendMessage(lstSV, LB_FINDSTRING, 0, (LPARAM)name);
			SendMessage(lstSV, LB_SETCURSEL, iSearch, (LPARAM)name);
			if (selectIndex < 0)
				MessageBox(NULL, TEXT("Không tìm thấy"), TEXT(""), MB_OK);
			break;
			return (INT_PTR)TRUE;
		}
		case IDC_BTNDEL:
			selectIndex = SendMessage(lstSV, LB_GETCURSEL, 0, 0);
			if (MessageBox(NULL, TEXT("Bạn có chắc chắn muốn xóa không"), TEXT("Xóa nhé"), MB_YESNO) == IDYES)
			{
				SendMessage(GetDlgItem(hDlg, IDC_LIST), LB_DELETESTRING, selectIndex, 0);
				EnableWindow(GetDlgItem(hDlg, IDC_BTNDEL), FALSE);
			}
			break;
			return (INT_PTR)TRUE;
		}
	}
	return (INT_PTR)FALSE;
}
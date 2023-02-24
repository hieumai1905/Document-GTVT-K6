// ngay31_1.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "ngay31_1.h"

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
    LoadStringW(hInstance, IDC_NGAY311, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_NGAY311));

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

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_NGAY311));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDR_MENU1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
    static COLORREF penColor = RGB(0, 0, 0);
    static int xLeft, yTop, xRight, yBottom,hinh;
    static POINT pt[9];
    HDC hdc;
    switch (message)
    {
    case WM_LBUTTONDOWN:
        xLeft = LOWORD(lParam);
        yTop = HIWORD(lParam);
        break;
    case WM_LBUTTONUP:
        xRight = LOWORD(lParam);
        yBottom = HIWORD(lParam);
        /*pt[0].x = xLeft;
        pt[0].y = yBottom;
        pt[1].x = xRight;
        pt[1].y = yBottom;
        pt[2].x = xLeft + (xRight - xLeft) / 2;
        pt[2].y = yTop;*/
        hdc = GetDC(hWnd);
        SelectObject(hdc, hPen);
        SelectObject(hdc, hBrush);
        if (hinh == ID_TAMGIAC) {
            pt[0].x = xLeft;
            pt[0].y = yBottom;
            pt[1].x = xRight;
            pt[1].y = yBottom;
            //pt[2].x = xLeft + (xRight - xLeft) / 2;
            pt[2].x = (xRight+xLeft) *2/ 4;
            pt[2].y = yTop;
            Polygon(hdc, pt, 3);
        }
        if (hinh == ID_CHUNHAT)
            Rectangle(hdc, xLeft, yTop, xRight, yBottom);
        if (hinh == ID_HINHTHOI) {
            pt[0].x = (xLeft + xRight) /2;
            pt[0].y = yTop;
            pt[1].x = xLeft;
            pt[1].y = (yTop + yBottom) / 2;
            pt[2].x = (xLeft + xRight) / 2;
            pt[2].y = (yBottom);
            pt[3].x = (xRight);
            pt[3].y = (yTop + yBottom) / 2;
            Polygon(hdc, pt, 4);
        }
        if (hinh == ID_SAO4CANH) {
            pt[0].x = (xLeft + xRight) / 2;
            pt[0].y = yTop;
            pt[1].x = (double)(3 * xLeft + 3 * xRight) / 8;
            pt[1].y = (3 * yTop + 3 * yBottom) / 8;
            pt[2].x = xLeft;
            pt[2].y = (yTop + yBottom) / 2;
            pt[3].x = (double)(3 * xLeft + 3 * xRight) / 8;
            pt[3].y = (double)(5 * yTop + 5 * yBottom) / 8;
            pt[4].x = (xLeft + xRight) / 2;
            pt[4].y = (yBottom);
            pt[5].x = (double)(5 * xLeft + 5 * xRight) / 8;
            pt[5].y = (double)(5 * yTop + 5 * yBottom) / 8;
            pt[6].x = (xRight);
            pt[6].y = (yTop + yBottom) / 2;
            pt[7].x = (double)(5 * xLeft + 5 * xRight) / 8;
            pt[7].y = (double)(3 * yTop + 3 * yBottom) / 8;
            Polygon(hdc, pt, 8);
        }
        ReleaseDC(hWnd, hdc);
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case ID_TAMGIAC:
                hinh = wmId;
                break;
            case ID_CHUNHAT:
                hinh = wmId;
                break;
            case ID_HINHTHOI:
                hinh = wmId;
                break;
            case ID_SAO4CANH:
                hinh = wmId;
                break;
            case ID_NENDO:
                hBrush = CreateSolidBrush(RGB(255, 0, 0));
                break;
            case ID_NENXANHLA:
                hBrush = CreateSolidBrush(RGB(0, 255, 0));
                break;
            case ID_NENVANG:
                hBrush = CreateSolidBrush(RGB(255, 255, 0));
                break;
            case ID_NETCHAM:
                penStyle = PS_DOT;
                hPen = CreatePen(penStyle, 1, penColor);
                break;
            case ID_VIENDUT:
                penStyle = PS_SOLID;
                hPen = CreatePen(penStyle, 1, penColor);
                break;
            case ID_DUONGVIENDO:
                penColor = RGB(255, 0, 0);
                hPen = CreatePen(penStyle, 1, penColor);
                break;
            case ID_DUONGVIENXANH:
                penColor = RGB(255, 255, 0);
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

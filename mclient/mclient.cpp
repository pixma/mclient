
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
//
//Author : Annim Banerjee
//Date: 4/3/2014
//Program: mclient.
//A simple mail client for windows platform.
//
//Copyright (C) <year>  <name of author>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
//
//
//Include files goes here
#include "stdafx.h"
#include "resource.h"

//
//
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
//
//wndProc
//
//
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
//
// main entry point goes here.
//
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	
	WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;
	TCHAR lpsWndClass[MAXLEN];
	LPWSTR lpwsErrorStr;
	LPWSTR lpwsErrorTitle;
	LPWSTR lpwsWindowTitle;
	LPWSTR lpwsWindowCreationFailError;

	LoadString(hInstance, appclass, lpsWndClass, MAXLEN);
	ZeroMemory( &wc, sizeof( WNDCLASSEX));
    //Step 1: Registering the Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
	wc.hIcon         = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_APP));
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = lpsWndClass;
    wc.hIconSm       = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_APP));

	LoadString( hInstance, wndRegFailErrMsg, lpwsErrorStr, MAXLEN);
	LoadString( hInstance, wndErrorTitle, lpwsErrorTitle, MAXLEN);

    if(!RegisterClassEx(&wc))
    {
		MessageBox(NULL, lpwsErrorStr, lpwsErrorTitle, MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
	LoadString( hInstance, appTitle, lpwsWindowTitle, MAXLEN);
    // Step 2: Creating the Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        lpsWndClass,
        lpwsWindowTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
		LoadString( hInstance, wndCreationFailedErrMsg, lpwsWindowCreationFailError, MAXLEN);
        MessageBox(NULL, lpwsWindowCreationFailError, lpwsWindowTitle,
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd);

    // Step 3: The Message Loop
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

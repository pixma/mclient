

#ifndef MAIN_H
#define MAIN_H

#include "Stdafx.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
LRESULT CALLBACK ApplicationMessageProcessMethod(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

//Param: int: Which class specified as per MACRO
//Param: HWND, any Parent of this window or NULL to make this as Parent window of this application.
//Return: int: Returns SUCCESS if done, else -1.
//set your window class
int windowClass(int, HWND);

//HRESULT TaskDialog(
//	_In_   HWND hWndParent,
//	_In_   HINSTANCE hInstance,
//	_In_   PCWSTR pszWindowTitle,
//	_In_   PCWSTR pszMainInstruction,
//	_In_   PCWSTR pszContent,
//	_In_   TASKDIALOG_COMMON_BUTTON_FLAGS dwCommonButtons,
//	_In_   PCWSTR pszIcon,
//	_Out_  int *pnButton
//	);
int showTaskDialog(HWND, HINSTANCE, PCWSTR, PCWSTR, PCWSTR, TASKDIALOG_COMMON_BUTTON_FLAGS, PCWSTR, int);




#endif
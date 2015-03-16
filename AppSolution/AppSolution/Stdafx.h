
#ifndef STDAFX_H
#define STDAFX_H

#include <Windows.h>
#include<CommCtrl.h>
#include <string.h>

#include "res_file\resource\resource.h"

#pragma comment(lib,"comctl32.lib")
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")



#define BASE_WINDOW	10
#define NULL_PARENT	NULL
#define SUCCESS	1
#endif
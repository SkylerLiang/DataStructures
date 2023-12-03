#include <iostream>
#include <process.h>
#include <windows.h>
using namespace std;

DWORD WINAPI Thread1(LPVOID lpParam);
DWORD WINAPI Thread2(LPVOID lpParam);
DWORD WINAPI Thread3(LPVOID lpParam);

bool isStop = false;
int main()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    TCHAR szCommandLine[] = TEXT("notepad");

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    ZeroMemory(&pi, sizeof(pi));

    int x;
    while (true)
    {
        cout << "请输入要选择的操作：\n0:退出\n1:创建进程\n2:挂起进程\n3:激活进程\n4:销毁进程\n5:启动两个一样的线程\n6:启动两个不同线程\n7:停止线程\n";
        cin >> x;
        switch (x)
        {
        case 0:
            return 0;
        case 1:
            if (!CreateProcess(NULL, szCommandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
            { // 创建进程，参数2使用szCommandLine，启动notepad软件
                fprintf(stderr, "Createprocess Failed \n");
                return 0;
            }
            break;
        case 2:
            if (SuspendThread(pi.hThread) >= 0)
                cout << "挂起进程成功" << endl;
            else
                cout << "挂起失败" << endl;
            break;
        case 3:
            if (ResumeThread(pi.hThread) != -1) // 调用激活线程的函数
                cout << "激活进程成功" << endl;
            else
                cout << "激活失败" << endl;
            break;
        case 4:
            if (TerminateProcess(pi.hProcess, 0) != 0) // 调用终止线程的函数
                cout << "销毁进程成功" << endl;
            else
                cout << "销毁失败" << endl;
            break;
        case 5:
            HANDLE hThread1, hThread2;
            DWORD dwThreadId1, dwThreadId2;
            // 创建两个相同的子线程，启动并观察,一个传入整数11，一个传入整数22
            hThread1 = CreateThread(
                NULL,          // no security attributes
                0,             // use default stack size
                Thread1,       // 需要填写Thread1
                (void *)11,    // argument to thread function
                0,             // use default creation flags
                &dwThreadId1); // returns the thread identifier

            hThread2 = CreateThread(
                NULL,          // no security attributes
                0,             // use default stack size
                Thread1,       // 需要填写Thread1
                (void *)22,    // argument to thread function
                0,             // use default creation flags
                &dwThreadId2); // returns the thread identifier

            break;
        case 6:
            // 创建两个不同的子线程，启动并观察同步控制过程
            HANDLE hThread3, hThread4;
            DWORD dwThreadId3, dwThreadId4;
            // 创建信号量
            HANDLE hSem;
            hSem = CreateSemaphore(NULL, 0, 1, NULL); // 创建一个信号量，初值为0，最大为1

            // 创建两个不同的子线程，启动并观察,信号量句柄hSem作为线程参数传递给线程
            hThread3 = CreateThread(
                NULL,          // no security attributes
                0,             // use default stack size
                Thread2,       // 需要填写Thread2
                (LPVOID)hSem,  // argument to thread function
                0,             // use default creation flags
                &dwThreadId3); // returns the thread identifier

            hThread4 = CreateThread(
                NULL,          // no security attributes
                0,             // use default stack size
                Thread3,       // 需要填写Thread3
                (LPVOID)hSem,  // argument to thread function
                0,             // use default creation flags
                &dwThreadId4); // returns the thread identifier

            break;
        case 7:
            isStop = true;
            break;
        default:
            cout << "选项不正确" << endl;
        }
    }
    return 0;
}

DWORD WINAPI Thread1(LPVOID lpParam)
{
    int count;

    count = (long long)lpParam;
    while (!isStop)
    {
        printf("%d ", count);
        Sleep(10);
    }
    return 0;
}

/*
线程2：每打印20个数后，需要等待线程3（Thread3）打印30个数，释放一次信号，才能继续
线程3：在每打印30个数以后，释放信号量

*/

// 补充Thread2，每打印20个，申请信号量
DWORD WINAPI Thread2(LPVOID lpParam)
{
    int count = 0;
    HANDLE hSem = (HANDLE)lpParam;
    while (!isStop)
    {
        if (count % 20 == 0)
        {
            WaitForSingleObject(hSem, INFINITE); // 申请信号量
            count = 0;
        }
        printf("T2:%2d ", count + 1);
        count++;
        Sleep(100);
    }
    return 0;
}

// 补充Thread3，每打印30个，释放信号量
DWORD WINAPI Thread3(LPVOID lpParam)
{
    int count = 0;
    HANDLE hSem = (HANDLE)lpParam;
    while (!isStop)
    {
        if (count % 30 == 0)
        {
            ReleaseSemaphore(hSem, 1, NULL); // 释放信号量
            count = 0;
        }
        printf("T3:%2d ", count + 1);
        count++;
        Sleep(100);
    }
    return 0;
}

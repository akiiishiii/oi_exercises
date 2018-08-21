#include <Windows.h>
#include <stdio.h>

/*
* 窗口的回调函数
*/
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    HDC hDC;
    PAINTSTRUCT ps;
    switch (uMsg) {
    case WM_PAINT:
        /*
         * 窗口重绘时调用
         * 只有在WM_PAINT消息中才可以使用BeginPaint、EndPaint
         * 其他消息使用GetDC、ReleaseDC
         */
        hDC = BeginPaint(hwnd, &ps);
        TextOut(hDC, 0, 50, "这是在WM_PAINT消息中重绘的文字", strlen("这是在WM_PAINT消息中重绘的文字"));
        EndPaint(hwnd, &ps);
        break;
    case WM_CHAR:
        MessageBox(hwnd, "WM_CHAR消息触发了", "提示", MB_OK);
        break;
    case WM_LBUTTONDOWN:
        hDC = GetDC(hwnd);
        TextOut(hDC, 0, 70, "这是在WM_LBUTTONDOWN消息中重绘的文字", strlen("这是在WM_LBUTTONDOWN消息中重绘的文字"));
        ReleaseDC(hwnd, hDC);
        break;
    case WM_CLOSE:
        if (IDYES == MessageBox(hwnd, "确定要退出吗？", "提示", MB_YESNO)) {
            //确定退出,销毁窗口,抛出一个WM_DESTYRY的消息
            DestroyWindow(hwnd);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    //第一步、设计窗口类
    WNDCLASS wndclass;
    wndclass.style = CS_HREDRAW | CS_VREDRAW; //设置水平竖直重绘，发送WM_PAINT消息
    wndclass.lpfnWndProc = WindowProc;        //指定窗口的回调函数
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0; //两个额外数据
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_CROSS);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = "myWindowClass";

    //第二步、注册窗口类
    RegisterClass(&wndclass);

    //第三步、创建窗口
    HWND hWnd = CreateWindow(
        "myWindowClass",     //窗口类的名字
        "my first window",   //窗口标题
        WS_OVERLAPPEDWINDOW, //样式
        0, 0, 500, 500,      //左上角坐标，宽高
        NULL,                //父窗口
        NULL,                //菜单
        hInstance,           //实例
        NULL);               //附加参数

    //第四步、显示更新窗口
    ShowWindow(hWnd, SW_SHOWNORMAL); //正常显示窗口
    UpdateWindow(hWnd);              //更新窗口

    //第五步、消息循环
    MSG msg;
    while (GetMessageA(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg); //翻译消息
        DispatchMessageA(&msg); //将消息传入窗口的回调函数
    }

    return 0;
}
#include<graphics.h>//图形库 需要安装 VS VC

#include<stdio.h>

#include<time.h> //time clock

#include<math.h>//计算

#include<stdlib.h>//关机命令

//playsound 只能放wav 可以用于资源文件

//mciSendSring 可以放mp3

#include<mmsystem.h>

#pragma comment(lib,“WINMM.LIB”)//播放多媒体的一个库

#define PI 3.141592654

void draw(int,int,int);

int main()

{

    initgraph(640, 480);//新建窗口

    //表盘界面

    //1.获取时间

    SYSTEMTIME time;//结构体

    //char arr[50];

    setbkmode(TRANSPARENT);

    settextstyle(30,0,“华文彩云”);//高度和默认宽度

    //setbkcolor(LIGHTGRAY);//grey gray

    while (1)

    {

        loadimage(NULL, “1.jpg”);

        setlinecolor(WHITE);

        rectangle(480, 0, 640, 160);

        outtextxy(500, 70, “放音乐”);

        rectangle(480, 160, 640, 320);

        outtextxy(500, 230, “不要点”);

        rectangle(480, 320, 640, 480);

        outtextxy(500, 380, “退出”);

        //界面

        GetLocalTime(&time);//获取当前时间 年 月 日 小时 分 秒

        draw(time.wHour, time.wMinute, time.wSecond);

        Sleep(1000);

    }

    //while (1)

    //{

    //Sleep(1000);//单位毫秒

    //GetLocalTime(&time);//获取当前时间 年 月 日 小时 分 秒

    //sprintf(arr, “%d年%d月%d日%d小时%d分%d秒”, time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);//格式化写入

    //outtextxy(0, 0, arr);//图形库的输出函数 printf

    ////

    //}

    getchar();

    closegraph();//关闭窗口

    return 0;

}



void draw(int hour,int min,int sec)

{

    //画表盘

    setlinecolor(WHITE);

    setlinestyle(PS_SOLID, 1);

    circle(240,240,200);//圆心加半径 直径<480 半径<240

    //圆心坐标 200 是半径

    char arr[3];

    for (int i = 1; i <= 12; i++)//刻度

    {

        sprintf(arr, “%d”, i);

        outtextxy(240+(int)(200sin(30iPI/180))-5, 240-(int)(200 * cos(30 * iPI / 180))-5, arr);

    }

    //强转

    //开始画指针 时针 分针 秒针 时针最短120 分针160 秒针最长200

    //粗细 颜色

    //画时针

    setlinecolor(RED);

    setlinestyle(PS_SOLID,7);

    line(240, 240, 240 + (int)(120 * sin(30 * (hour+min/60.0)*PI / 180)), 240 - (int)(120 * cos(30 * (hour+min/60.0)*PI / 180)));

    //画分针

    setlinecolor(BLUE);

    setlinestyle(PS_SOLID, 6);

    line(240, 240, 240 + (int)(160 * sin(6 * minPI / 180)), 240 - (int)(160 * cos(6 min*PI / 180)));

    //画秒针

    setlinecolor(YELLOW);

    setlinestyle(PS_SOLID, 2);

    line(240, 240, 240 + (int)(200 * sin(6 * secPI / 180)), 240 - (int)(200 * cos(6 * secPI / 180)));

}

void play()

{

    if (MouseHit())//判断有没有鼠标信息

    {

        MOUSEMSG msg = GetMouseMsg();//鼠标信息

        switch (msg.uMsg)

        {

        case WM_LBUTTONDOWN:

            if (msg.x >= 480)

            {

                if (msg.y <= 160)

                {

                    //放音乐

                    mciSendString(“open Fade.mp3 alias bgm”, 0, 0, 0);//

                    mciSendString(“play bgm repeat”, 0, 0, 0);

                }

                else if (msg.y > 320)

                {

                    //结束 整个程序

                    //return ? break?

                    closegraph();

                    exit(0);

                }

                else

                {

                    //关机

                    MessageBox(GetHWnd(), “将在60秒后关机”, “关机”, MB_OK);//句柄 对应一个窗口

                    system(“shutdown -s -t 60”);//关机和取消关机

                    //shutdown -s -t 60

                    //shutdown -s 立刻关机

                    //23:30关机

                    //at 23:30 shutdown -s

                    //shutdown -a 取消关机

                }

            }

        }

    }

}

#include <stdlib.h>
#include <string.h>

#include <cstdio>
#include <iostream>

#include "CPluginController.h"

#define MAXSIZE 100

using namespace std;

int main() {
    char input;
    cout << "插件系统" << endl;
    cout << "输入h查看插件帮助信息" << endl;
    cout << "输入1,2,3,4,5,6分别查看插件1，2，3，4, 5, 6的信息"
         << endl;  // 1,2,3为所需要实现的插件功能
    cout << "输入r进入插件1,2,5执行页面" << endl;  // 4,5,6为额外增加的插件功能
    cout << "输入d进入插件3,4,6执行页面" << endl;
    cout << "输入e时退出" << endl;
    while (1) {
        // scanf("%c", &input);
        cin >> input;
        getchar();
        if (input == 'h') {
            CPluginController pc;
            pc.ProcessHelp();
        }
        if (input == '1') {
            CPluginController pc;
            pc.InitializeController();
            pc.ProcessRequest(1);
            pc.UninitializeController();
        }
        if (input == '2') {
            CPluginController pc;
            pc.InitializeController();
            pc.ProcessRequest(2);
            pc.UninitializeController();
        }
        if (input == '3') {
            CPluginController pc;
            pc.InitializeController();
            pc.ProcessRequest(3);
            pc.UninitializeController();
        }
        if (input == '4') {
            CPluginController pc;
            pc.InitializeController();
            pc.ProcessRequest(4);
            pc.UninitializeController();
        }
        if (input == '5') {
            CPluginController pc;
            pc.InitializeController();
            pc.ProcessRequest(5);
            pc.UninitializeController();
        }
        if (input == '6') {
            CPluginController pc;
            pc.InitializeController();
            pc.ProcessRequest(6);
            pc.UninitializeController();
        }
        if (input == 'r') {
            CPluginController ptr;
            cout << "输入文件名" << endl;
            char File[MAXSIZE];
            cin >> File;
            cout << "输入执行的插件代号" << endl;
            char Function[MAXSIZE];
            cin >> Function;
            ptr.InitializeController();
            if (ptr.IfProcess(Function) == false)  //判断插件是否存在
            {
                cout << "No this plugin!" << endl;
            } else {
                ptr.ProcessFunction(Function, File);
            };
            ptr.UninitializeController();
            if (input == 'e') {
                exit(0);
                break;
            }
        }
        if (input == 'd') {
            CPluginController ptr;
            cout << "输入目录名" << endl;
            char Dir[MAXSIZE];
            cin >> Dir;
            cout << "输入后缀名" << endl;
            char Suffix[MAXSIZE];
            cin >> Suffix;
            cout << "输入执行的插件代号" << endl;
            char Function[MAXSIZE];
            cin >> Function;
            ptr.InitializeController();
            if (ptr.IfProcess(Function) == false)  //判断插件是否存在
            {
                cout << "No this plugin!" << endl;
            } else {
                ptr.ProcessFunction(Function, Dir, Suffix);
            };
            ptr.UninitializeController();
            if (input == 'e') {
                exit(0);
                break;
            }
        }
        if (input == 'e') {
            exit(0);
            break;
        }
    }
}

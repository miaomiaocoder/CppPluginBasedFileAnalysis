#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "IPlugin.h"

using namespace std;

char FUNC_NAME[] = "cssw";  // count the special suffix file word

class Plugin : public IPlugin {
   public:
    Plugin() {}
    virtual ~Plugin() {}
    virtual void Print() {
        cout << "Count the specific suffix file word of the directory ! Use "
                "'cssw'"
             << endl;
    }
    virtual void Help() {
        cout << "Func id:4 "
             << "This func will count the specific suffix file word" << endl;
    }
    virtual int GetID() { return 4; }
    virtual char *GetName() { return FUNC_NAME; }
    int FuncLine(const char *szLine) {
        int nWords = 0;
        int i = 0;
        for (; i < strlen(szLine); i++) {
            if (*(szLine + i) != ' ') {
                nWords++;
                while ((*(szLine + i) != ' ') && (*(szLine + i) != '\0')) {
                    i++;
                }
            }
        }
        return nWords;
    }
    void Func(char *File) {
        int nWords = 0;         //词计数变量，初始值为0
        FILE *fp;               //文件指针
        char carrBuffer[1024];  //每行字符缓冲，每行最多1024个字符
        if ((fp = fopen(File, "r")) == NULL)  //打开文件
        {
            cout << "fopen error" << endl;
            exit(-1);
        }
        while (!feof(fp))  //如果没有读到文件末尾
        {
            //从文件中读一行
            if (fgets(carrBuffer, sizeof(carrBuffer), fp) != NULL)
                //统计每行词数
                nWords += FuncLine(carrBuffer);
        }
        fclose(fp);  //关闭文件
        cout << "word numbers: " << nWords << endl;
    }
    virtual void Func(string path, string suffix) {
        DIR *dir;
        struct dirent *ptr;
        if ((dir = opendir(path.c_str())) == nullptr) {
            perror("Open directory error...");
            exit(1);
        }
        while ((ptr = readdir(dir)) != nullptr) {
            if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
                continue;
            else if (ptr->d_type == 8) {
                string filename = ptr->d_name;
                string suffixStr = filename.substr(filename.find_last_of('.') +
                                                   1);  //获取文件后缀
                if (suffixStr == suffix) {
                    // files.push_back(path + "/" + ptr->d_name);
                    char p[100];
                    strcpy(p, (path + "/" + ptr->d_name).c_str());
                    Func(p);
                }
            } else if (ptr->d_type == 4)  // directory
            {
                Func(path + "/" + ptr->d_name, suffix);  //递归
            }
        }
        closedir(dir);
    }
};
extern "C" void GetInterface(IPlugin **ppPlugin) {
    static Plugin plugin;
    *ppPlugin = &plugin;
}

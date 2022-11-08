#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <cstdio>
#include <iostream>
#include <map>

#include "IPlugin.h"

using namespace std;
char FUNC_NAME[] = "cw";  // count the word cw
class Plugin : public IPlugin {
   public:
    Plugin() {}
    virtual ~Plugin() {}
    virtual void Print() { cout << "Count the file word! Use 'cw'" << endl; }
    virtual void Help() {
        cout << "Func id:2 "
             << "This func will count the file word" << endl;
    }
    virtual int GetID() { return 2; }
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
    virtual void Func(string path, string suffix) {}
};
extern "C" void GetInterface(IPlugin **ppPlugin) {
    static Plugin plugin;
    *ppPlugin = &plugin;
}

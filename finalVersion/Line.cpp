#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <iostream>
#include <string>

#include "IPlugin.h"

using namespace std;

char FUNC_NAME[] = "cl";  // count the line

class Plugin : public IPlugin {
   public:
    Plugin() {}
    virtual ~Plugin() {}
    virtual void Print() { cout << "Count the file line！Use 'cl'" << endl; }
    virtual void Help() {
        cout << "Func id:1 "
             << "This func will count the file line" << endl;
    }
    virtual int GetID() { return 1; }
    virtual char *GetName() { return FUNC_NAME; }
    virtual void Func(char *File)  //统计文件行数
    {
        int fd;
        char temp;
        int num = 0;
        if (-1 == (fd = open(File, O_RDONLY)))  //只读打开文件
        {
            cout << "Can not open: " << File << endl;
            return;
        }
        while (read(fd, &temp, 1)) {
            if (temp == '\n')  //每次读到换行符num++
            {
                num++;
            }
        }
        close(fd);                                 //关闭文件
        cout << File << " line: " << num << endl;  //展示
    }
    virtual void Func(string path, string suffix) {}
};
extern "C" void GetInterface(IPlugin **ppPlugin) {
    static Plugin plugin;
    *ppPlugin = &plugin;
}

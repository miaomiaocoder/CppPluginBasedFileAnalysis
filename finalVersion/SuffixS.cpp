#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "IPlugin.h"

using namespace std;

char FUNC_NAME[] = "cssl";  // count the special suffix file line

class Plugin : public IPlugin {
   public:
    Plugin() {}
    virtual ~Plugin() {}
    virtual void Print() {
        cout << "Count the specific suffix file line of the directory ! Use "
                "'cssl'"
             << endl;
    }
    virtual void Help() {
        cout << "Func id:3 "
             << "This func will count the specific suffix file line" << endl;
    }
    virtual int GetID() { return 3; }
    virtual char *GetName() { return FUNC_NAME; }
    virtual void Func(char *File) {
        int fd;
        char temp;
        int num = 0;
        if (-1 == (fd = open(File, O_RDONLY))) {
            cout << "Can not open: " << File << endl;
            return;
        }
        while (read(fd, &temp, 1)) {
            if (temp == '\n') {
                num++;
            }
        }
        close(fd);
        cout << File << " line: " << num << endl;
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

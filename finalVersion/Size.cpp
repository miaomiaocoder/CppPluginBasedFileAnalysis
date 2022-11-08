#include <fcntl.h>
#include <unistd.h>

#include <iostream>

#include "IPlugin.h"

using namespace std;
char FUNC_NAME[] = "cs";  // count the file size
class Plugin : public IPlugin {
   public:
    Plugin() {}
    virtual ~Plugin() {}
    virtual void Print() { cout << "Count the file size! Use 'cs'" << endl; }
    virtual void Help() {
        cout << "Func id:5 "
             << "This func will count file size" << endl;
    }
    virtual int GetID() { return 5; }
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
            num++;
        }
        close(fd);
        if (0 == num) {
            cout << "Empty file: " << File << endl;
        }
        cout << File << " size is : " << num << endl;
    }
    virtual void Func(string path, string suffix) {}
};
extern "C" void GetInterface(IPlugin **ppPlugin) {
    static Plugin plugin;
    *ppPlugin = &plugin;
}
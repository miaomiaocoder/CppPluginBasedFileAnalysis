#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>

#include "SearchPlugin.h"
#include "a.h"

using namespace std;

typedef void (*FUNC_PRINT)();
typedef void (*FUNC_HELP)();
typedef int (*FUNC_GETID)();

int main(int argc, char* argv[]) {
    vector<string> PluginName;
    SearchPlugin ptr;
    if (!ptr.GetPlugin(PluginName)) {
        cout << "GetPlugin error" << endl;
        return 0;
    }
    int Count = 0;
    vector<FUNC_PRINT> vPrint;
    vector<FUNC_HELP> vHelp;
    vector<FUNC_GETID> vGetid;
    //遍历文件名数组
    for (auto i = 0; i < PluginName.size(); i++) {
        void* handle =
            dlopen(PluginName[i].c_str(), RTLD_LAZY);  // open all lib.so
        if (0 == handle) {
            cout << "dlopen error" << endl;
            return 0;
        }

        vPrint.push_back((FUNC_PRINT)dlsym(handle, "print"));
        vHelp.push_back((FUNC_HELP)dlsym(handle, "Help"));
        vGetid.push_back((FUNC_GETID)dlsym(handle, "GetID"));
        ++Count;
    }
    // 提示
    if (argc == 1) {
        cout << "Using:./ExeFile help or 1 or 2" << endl;
        cout << "Example:./ExeFile help" << endl;
        cout << "        ./ExeFile 1" << endl;
        cout << "        ./ExeFile 2" << endl;
    }
    if (argc > 1) {
        char* p = argv[1];
        if (!strcmp(p, "help")) {
            for (auto i = 0; i < Count; ++i) {
                cout << vGetid[i]() << ":";
                vHelp[i]();
            }
        } else {
            int id = atoi(p);
            for (auto j = 0; j < Count; ++j) {
                if (id == vGetid[j]()) vPrint[j]();
            }
        }
    }
    return 0;
}

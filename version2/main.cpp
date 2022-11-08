#include <dlfcn.h>

#include <iostream>
#include <vector>

#include "SearchPlugin.h"
#include "a.h"

using namespace std;

int main() {
    vector<string> PluginName;
    SearchPlugin ptr;
    if (!ptr.GetPlugin(PluginName)) {
        cout << "GetPlugin error" << endl;
        return 0;
    }

    for (auto i = 0; i < PluginName.size(); i++) {
        void* handle =
            dlopen(PluginName[i].c_str(), RTLD_LAZY);  // open all lib.so
        if (0 == handle) {
            cout << "dlopen error" << endl;
            return 0;
        }

        typedef void (*Func)();

        Func print1 = (Func)dlsym(handle, "print");

        if (0 == print1) {
            cout << "print1 error" << endl;
            char* str = dlerror();
            cout << str << endl;
        }

        (*print1)();

        dlclose(handle);
    }

    return 0;
}

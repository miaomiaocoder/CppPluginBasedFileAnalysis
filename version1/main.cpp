#include <dlfcn.h>

#include <iostream>

#include "a.h"

using namespace std;

int main() {
	// void* handle = dlopen("./liba1.so", RTLD_LAZY);  // open liba1.so or liba2.so 当前目录测试，请使用makefile
    void* handle = dlopen("../plugin/liba2.so", RTLD_LAZY);  // open liba1.so or liba2.so plugin测试，请使用cmake
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

    return 0;
}

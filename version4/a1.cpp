#include <iostream>

#include "IPlugin.h"

using namespace std;

class Plugin : public IPlugin {
   public:
    Plugin() {}
    virtual ~Plugin() {}
    virtual void Print() { cout << "Hello World!" << endl; }
    virtual void Help() {
        cout << "Func id:1 "
             << "This func prints 'Hello World!'" << endl;
    }
    virtual int GetID() { return 1; }
};
extern "C" void GetInterface(IPlugin **ppPlugin) {
    static Plugin plugin;
    *ppPlugin = &plugin;
}

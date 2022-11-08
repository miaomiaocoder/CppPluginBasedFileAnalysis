#include <iostream>

#include "IPlugin.h"

using namespace std;

class Plugin : public IPlugin {
   public:
    Plugin() {}
    virtual ~Plugin() {}
    virtual void Print() { cout << "Hello China!" << endl; }
    virtual void Help() {
        cout << "Func id:2 "
             << "This func prints 'Hello China!'" << endl;
    }
    virtual int GetID() { return 2; }
};
extern "C" void GetInterface(IPlugin **ppPlugin) {
    static Plugin plugin;
    *ppPlugin = &plugin;
}

#include <stdlib.h>
#include <string.h>

#include <iostream>

#include "CPluginController.h"

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "Parameters error" << endl;
        cout << "Exampel:./ExeFile help" << endl;
        cout << "        ./ExeFile FuncId" << endl;
        cout << "        ./ExeFile 1" << endl;
        return 0;
    }
    if (strcmp(argv[1], "help") == 0) {
        CPluginController ptr;
        ptr.ProcessHelp();
        return 0;
    }
    int FunctionID = atoi(argv[1]);
    CPluginController pointer;
    pointer.InitializeController();
    pointer.ProcessRequest(FunctionID);
    pointer.UninitializeController();
    return 0;
}

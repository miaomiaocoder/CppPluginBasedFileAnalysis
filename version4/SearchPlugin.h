#ifndef _SEARCHPLUGIN_H_
#define _SEARCHPLUGIN_H_

#include <dirent.h>

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class SearchPlugin {
   public:
    SearchPlugin() {}
    ~SearchPlugin() {}
    bool GetPlugin(vector<string>& PluginName);
};

#endif  // !_SEARCHPLUGIN_H_

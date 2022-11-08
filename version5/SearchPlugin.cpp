#include "SearchPlugin.h"

bool SearchPlugin::GetPlugin(vector<string>& PluginName) {
	DIR*dir = opendir("../plugin");
	if (0 == dir) {
		return false;
	}
	while (1) {
		struct dirent *ptr = readdir(dir);
		if (0 == ptr) {
			break;
		}
		if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
			continue;
		string str = "../plugin/";
		str = str + ptr->d_name;
		PluginName.push_back(str);
	}
	closedir(dir);
    return true;
}

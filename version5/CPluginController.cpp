#include "CPluginController.h"

#include "IPlugin.h"
#include "SearchPlugin.h"
#include "dlfcn.h"

CPluginController::CPluginController(void) {}

CPluginController::~CPluginController(void) {}

bool CPluginController::InitializeController(void) {
    //存放所有插件的文件名
    std::vector<std::string> PluginName;
    //定义插件搜索类对象
    SearchPlugin ptr;
    //获取所有的插件文件名
    if (!ptr.GetPlugin(PluginName)) return false;
    for (unsigned int i = 0; i < PluginName.size(); i++) {
        typedef int (*PLUGIN_CREATE)(IPlugin **);
        PLUGIN_CREATE GetIFC;
        IPlugin *pPlugin = NULL;
        //打开动态链接库文件
        void *handle = dlopen(PluginName[i].c_str(), RTLD_LAZY);
        if (handle != NULL) {
            m_vhForPlugin.push_back(handle);
            //获取导出的接口对象指针
            GetIFC = (PLUGIN_CREATE)dlsym(handle, "GetInterface");
            if (NULL != GetIFC) {
                (GetIFC)(&pPlugin);
                if (pPlugin != NULL) {
                    m_vpPlugin.push_back(pPlugin);
                }
            }
        }
    }
    return true;
}

bool CPluginController::UninitializeController() {
    for (unsigned int i = 0; i < m_vhForPlugin.size(); i++) {
        dlclose(m_vhForPlugin[i]);
    }
    return true;
}

bool CPluginController::ProcessRequest(int FunctionID) {
    for (unsigned int i = 0; i < m_vpPlugin.size(); i++) {
        if (m_vpPlugin[i]->GetID() == FunctionID) {
            m_vpPlugin[i]->Print();
            break;
        }
    }
    return true;
}

bool CPluginController::ProcessHelp(void) {
    //存放所有插件的文件名
    std::vector<std::string> PluginName;
    //定义插件搜索类对象
    SearchPlugin ptr;
    //获取所有的插件文件名
    if (!ptr.GetPlugin(PluginName)) return false;
    for (unsigned int i = 0; i < PluginName.size(); i++) {
        typedef int (*PLUGIN_CREATE)(IPlugin **);
        PLUGIN_CREATE GetIFC;
        IPlugin *pPlugin = NULL;
        //打开动态链接库文件
        void *handle = dlopen(PluginName[i].c_str(), RTLD_LAZY);
        if (handle != NULL) {
            //获取导出的接口对象指针
            GetIFC = (PLUGIN_CREATE)dlsym(handle, "GetInterface");
            if (NULL != GetIFC) {
                (GetIFC)(&pPlugin);
                if (pPlugin != NULL) {
                    pPlugin->Help();
                }
            }
            dlclose(handle);
        }
    }
    return true;
}

bool CPluginController::IfProcess(char *Function)  //判断插件是否存在
{
    unsigned int i;
    for (i = 0; i < m_vpPlugin.size(); i++) {
        if (strcmp(Function, m_vpPlugin[i]->GetName()) == 0) {
            break;
        }
    };
    if (i < m_vpPlugin.size())  //插件存在
    {
        return true;
    } else {
        return false;
    }
}

bool CPluginController::ProcessFunction(char *Function,
                                        char *File)  //执行插件功能
{
    for (unsigned int i = 0; i < m_vpPlugin.size(); i++) {
        if (strcmp(Function, m_vpPlugin[i]->GetName()) == 0) {
            m_vpPlugin[i]->Func(File);  //插件功能
            break;
        }
    }
    return true;
}

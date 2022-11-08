#ifndef _CPLUGINCONTROLLER_H_
#define _CPLUGINCONTROLLER_H_

#include <vector>

class IPlugin;

class CPluginController {
   public:
    CPluginController(void);
    virtual ~CPluginController(void);

    bool InitializeController(void);    //初始化
    bool UninitializeController(void);  //释放

    bool ProcessHelp(void);
    bool ProcessRequest(int FunctionID);
    bool IfProcess(char *Function);  //判断插件是否存在
    bool ProcessFunction(char *Function, char *Document);  //执行插件1，2，5
    bool ProcessFunction(char *Function, char *Dir,
                         char *Suffix);  //执行插件3，4，6
   private:
    std::vector<void *> m_vhForPlugin;
    std::vector<IPlugin *> m_vpPlugin;
};

#endif

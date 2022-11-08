#ifndef _CPLUGINCONTROLLER_H_
#define _CPLUGINCONTROLLER_H_

#include <vector>

class IPlugin;

class CPluginController {
   public:
    CPluginController(void);
    virtual ~CPluginController(void);

    bool InitializeController(void);
    bool UninitializeController(void);

    bool ProcessHelp(void);
    bool ProcessRequest(int FunctionID);
    bool IfProcess(char *Function);
    bool ProcessFunction(char *Function, char *Document);

   private:
    std::vector<void *> m_vhForPlugin;
    std::vector<IPlugin *> m_vpPlugin;
};

#endif

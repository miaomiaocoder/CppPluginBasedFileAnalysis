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

   private:
    std::vector<void *> m_vhForPlugin;
    std::vector<IPlugin *> m_vpPlugin;
};

#endif

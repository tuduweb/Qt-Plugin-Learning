#include "../PluginInterface/PluginInterface.h"

class HelloPlugin : PluginInterface {
public:
    HelloPlugin();
    void Init(QString resPath);
    ~HelloPlugin();
};
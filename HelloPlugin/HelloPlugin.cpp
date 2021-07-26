#include "HelloPlugin.h"

void HelloPlugin::Init(QString resPath) {
    std::cout << resPath << std:: endl;
}

void HelloPlugin::~HelloPlugin() {
    std::cout << "~HelloPlugin" << std::endl;
}
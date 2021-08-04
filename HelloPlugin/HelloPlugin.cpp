#include "./HelloPlugin.h"
#include <iostream>
#include <qDebug>

void HelloPlugin::Init(QString resPath) {
    std::cout << resPath.toStdString() << std::endl;
}

HelloPlugin::~HelloPlugin() {
    std::cout << "~HelloPlugin" << std::endl;
}

HelloPlugin::HelloPlugin() {
    std::cout << "Hello world" << std::endl;
}
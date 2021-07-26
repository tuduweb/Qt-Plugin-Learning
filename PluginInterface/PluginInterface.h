#ifndef _PLUGIN_INTERFACE_H_
#define _PLUGIN_INTERFACE_H_

#include <QObject>
#include <QWidget>

class PluginInterface : public QObject
{
    Q_OBJECT
public:
    enum Type{
        WIDGET, SHELL
    };
    Q_ENUM(Type);
public:
    Type m_type;
public:
    virtual ~PluginInterface() {}
    virtual void Init(QString resPath) = 0;
};

#endif
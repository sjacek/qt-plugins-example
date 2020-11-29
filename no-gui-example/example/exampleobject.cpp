#include "exampleobject.h"

#include <QDebug>

ExampleObject::ExampleObject(QObject *parent)
    : QObject(parent)
{
}

void ExampleObject::name(QString name)
{
    qCInfo(log) << "received name=" << name;
}

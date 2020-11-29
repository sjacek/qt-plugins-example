#include "exampleobject.h"

#include <QDebug>

ExampleObject::ExampleObject(QObject *parent)
    : QObject(parent)
{
}

void ExampleObject::name(QString name)
{
    qInfo() << "received name=" << name;
}

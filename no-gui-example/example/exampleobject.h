#ifndef EXAMPLEOBJECT_H
#define EXAMPLEOBJECT_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>

class ExampleObject : public QObject
{
    Q_OBJECT
public:
    explicit ExampleObject(QObject *parent = nullptr);

signals:

public slots:
    void name(QString name);
};

#endif // EXAMPLEOBJECT_H

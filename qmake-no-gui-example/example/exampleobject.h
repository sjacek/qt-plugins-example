#ifndef EXAMPLEOBJECT_H
#define EXAMPLEOBJECT_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>

#include <QtCore/QLoggingCategory>

class ExampleObject : public QObject
{
    Q_OBJECT
    Q_LOGGING_CATEGORY(log, "ExampleObject")
public:
    explicit ExampleObject(QObject *parent = nullptr);

signals:

public slots:
    void name(QString name);
};

#endif // EXAMPLEOBJECT_H

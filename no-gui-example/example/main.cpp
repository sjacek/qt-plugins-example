#include <QCoreApplication>
#include <QDir>
#include <QPluginLoader>

#include <QDebug>
#include <QSignalSpy>
#include <QTimer>

#include <QLoggingCategory>

#include <interfaceplugin.h>
#include "exampleobject.h"

Q_LOGGING_CATEGORY(main_log, "main")

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ExampleObject theObject(&a);

    Interface *interface;
    QDir dir(qApp->applicationDirPath());
    dir.cd("plugins");
    for (auto &filename : dir.entryList(QDir::Files | QDir::NoSymLinks))
    {
        QPluginLoader loader(dir.absoluteFilePath(filename));
        auto *plugin = loader.instance();
        if (plugin)
        {
            qCDebug(main_log) << "register plugin " << loader.fileName();

            interface = qobject_cast<Interface *>(plugin);
            QObject::connect(interface, SIGNAL(name(QString)), &theObject, SLOT(name(QString)));
        }
    }
    if (!interface)
    {
        qCDebug(main_log) << "Couldn't load interface!";
        return -1;
    }

    // Verify plugin emits its `name` with `QSignalSpy`.
    QSignalSpy spy(interface, &Interface::name);
    QTimer::singleShot(100, interface, &Interface::getName);
    spy.wait();
    if (spy.count() == 1)
    {
        auto name = spy.takeFirst().at(0).toString();
        qCDebug(main_log) << "Plugin emitted name:" << name;
    }
    else
    {
        qCDebug(main_log) << "Not emitted!";
    }
    return 0;

    // return a.exec();
}

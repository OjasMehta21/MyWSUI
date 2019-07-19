#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include  "getdata.h"
#include <QQuickStyle>
#include <QDebug>

#include "myLibrary/mylibrary.h"
#include "DGADllEngine.h"

int main(int argc, char *argv[])
{  QQuickStyle::setStyle("Material");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    //Startup();
    qDebug()<< QDir::currentPath();
    Mylibrary some;
    qDebug() << some.calc();
    app.setOrganizationName("KLA");
    app.setOrganizationDomain("surfscan");
    app.setApplicationName("WaferSight Analysis");
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    qmlRegisterType<MyData>("Core", 1, 0, "MyData");

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

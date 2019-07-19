#ifndef GETDATA_H
#define GETDATA_H
#include <QFile>
#include <QDebug>
#include<QDir>
#include <QQmlContext>
#include <QSettings>

class MyData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(std::vector<double> dataX MEMBER dataX NOTIFY dataXChanged)
    Q_PROPERTY(std::vector<double> dataY MEMBER dataY NOTIFY dataYChanged)
    Q_PROPERTY(std::vector<double> dataZ MEMBER dataZ NOTIFY dataZChanged)
    Q_PROPERTY(std::vector<int> plotZ MEMBER plotZ NOTIFY plotZChanged)
signals:
    void dataXChanged();
    void dataYChanged();
    void dataZChanged();
    void plotZChanged();
    void dataLoaded();
public:
    double maxZ = -1e7, minZ = 1e7;
    MyData(QObject *parent = nullptr) {}
    std::vector<double> dataX, dataY, dataZ;
    std::vector<int> plotZ;//each vector for x,y, z respectively.
public slots:
    Q_INVOKABLE void show(QString s);

private:
    QSettings settings;
};
//#include "main.moc"
#endif // GETDATA_H

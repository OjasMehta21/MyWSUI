#include "getdata.h"
#define UNDEF 1e10
void MyData::show(QString s){
    qInfo()<<s;
    QStringList dataString;
    QString dir = QDir::currentPath();
    QFile f1(s);
    if (!f1.open(QIODevice::ReadOnly | QIODevice::Text)){
        qInfo()<<"file not opened";

    }
    else{
        QTextStream s1(&f1);
        s1.readLine(); //skips the first line

        while (!s1.atEnd()){
          QString s=s1.readLine(); // reads line from file
          QList<QString> l = (s.split(","));
          dataX.push_back(l[0].toDouble());
          dataY.push_back(l[1].toDouble());
          if(l[2]!=""){
              if(l[2].toDouble()>maxZ){
                  maxZ = l[2].toDouble();
              }
              if(l[2].toDouble()<minZ){
                  minZ = l[2].toDouble();
              }
              dataZ.push_back(l[2].toDouble());
          }
          else{
              dataZ.push_back(UNDEF);
          }
        }

        f1.close();
    }

    int dataLen = dataZ.size();
//    for (int i = 0; i<datalen; i++) {
//        if(dataZ[i]<10000000)
//            plotZ.push_back(255*(dataZ[i]-minZ)/(maxZ - minZ));
//        else
//            plotZ.push_back(255);
//    };
    plotZ.resize(596*596);
    int i = 0, j=0;
    qInfo()<<maxZ<<"max"<<minZ<<'\n';
    for (double x = 148.75; x >=-148.75; x = x -0.5) {
        for (double y = -148.75; y <=148.75; y = y+0.5) {
           // console.log(myObject.dataX[i],y);
           // console.log(myObject.dataY[i],x);
            if(i< dataLen && dataX[i]==y && dataY[i]==x){
               // console.log('heyyyy');
                if(dataZ[i]<10000000)
                    plotZ[j] = 255*(dataZ[i]-minZ)/(maxZ - minZ);
                else
                    plotZ[j] = 255;
                i++;
            }
            else{
                plotZ[j] = 255;
            }
            j++;

        }

    }
//    int mnz = INT_MAX, mxz = INT_MIN;
//    for(int z=0; z<j; z++){
//        if(mnz>plotZ[z])mnz=plotZ[z];
//        if(mxz<plotZ[z])mxz = plotZ[z];
//    }
//    qInfo()<<mnz<<"i"<<mxz;
    emit dataLoaded();
}

#ifndef IMAGEPROC_H
#define IMAGEPROC_H
#include <QThread>
#include <QObject>
#include <QList>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/highgui/highgui.hpp"
#include <QDebug>
#include "basetool.h"
//using namespace std;
using namespace cv;

/////////////
/// \brief The VideoReader class
///  从一个视频文件中读取数据
///
class VideoReader:public QThread{
  Q_OBJECT
  public:
     VideoReader(QString filepath=""):m_filepath(filepath)
     {
         if(!m_filepath.isEmpty())
         {
             capture.open(m_filepath.toStdString());
         }
         index=0;
     }

     //打开文件
     bool open(QString videoPath)
     {
         if(capture.isOpened()){
             capture.release();
             return capture.open(videoPath.toStdString());
         }
        return capture.open(videoPath.toStdString());
     }

     void run()
     {
        Mat frame;
        QImage img;
        Mat temp;
        //注册Mat这个类型
        qRegisterMetaType<Mat>("Mat");
        while(1)
        {
            msleep(50);
            if(!capture.isOpened()){
                qDebug()<<"capture not open";sleep(1);continue;
            }
            capture>>frame;
            if(index++%2!=0) continue;

            if(frame.empty()) {
                qDebug()<<"file read end";sleep(1); continue;}


            frame.copyTo(temp);
            img= MatToQImage(frame);


            emit frameAvailable(img);
            emit frameMatToDeal(temp);
            //imshow("frame",frame);  加上这个程序崩溃
        }

        exec();
     }


   QString  m_filepath;
   VideoCapture  capture;
   int index;

   signals:
   void  frameAvailable(QImage img);
   void  frameMatToDeal(Mat m);
   void  testSignal(QString );

};

//////
/// \brief The ImageProc class
///
class ImageProc : public QThread
{
    Q_OBJECT
public:
    explicit ImageProc(QObject *parent = 0);

    void run();

    QList<Mat>  matList;

signals:
    void  frameDealed(QImage img);
    void  frameMatToDeal(Mat m);

public slots:
    void onNewFrame(Mat m);
    void onNewImage(QImage img);
};


/////
///  导航
///
class NavImagePorc:public QThread{
    Q_OBJECT
  public:
     NavImagePorc();

    void run();
    QList<Mat>  matList;

signals:
    void frameDealed(QImage img);

    void sendNav(QString str);

public slots:
    void onNewFrame(Mat m);
};


#endif // IMAGEPROC_H

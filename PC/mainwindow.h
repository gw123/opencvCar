#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imageproc.h"
#include <QStack>
#include <tcpserver.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event) ;

private slots:
    void on_btnSelectVideoFile_clicked();
    //   有新的帧到来
    void on_FrameAvailable(QImage img);
    //   初次处理完毕 显示
    void on_FrameDealed(QImage img);
    //   根据图片识别结果
    void on_FrameNav(QImage img);

    void on_SendNav(QString nav);

    //
    void onFinish(QImage);


    void on_btnUp_clicked();

    void on_btnLeft_clicked();

    void on_btnRight_clicked();

    void on_btnDown_clicked();

signals:
    void tcpNewFrame(QImage img);

private:

    Ui::MainWindow *ui;

    //视频处理相关
    QString            m_videoFile;
    VideoReader        videoReader;
    ImageProc          imageProc;
    NavImagePorc       navImagePorc;

    //窗口拖拽相关
    QSize lablesize;
    bool  m_bDrag;
    QPoint m_dragPosition;

    QStack<String> jilu;

    //视频传输相关函数
    TcpServer  *tcpServer;

};

#endif // MAINWINDOW_H

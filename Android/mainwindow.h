#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;

#include <QVideoProbe>
#include <QVideoFrame>

#include <tcpclient.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void convertYUV420_NV21toARGB8888(uchar *data,uchar* to ,int width, int height);
public slots:
    void processFrame(QVideoFrame frame);
    void onDisplay(QString msg);

signals:
    void frameAvailable(QImage image);

private slots:

    void on_btnSetting_clicked();

    void on_btnEnd_clicked();

private:
    Ui::MainWindow *ui;
    //QTimer  *m_timer;
    QCamera *m_camera;
    QCameraViewfinder *viewfinder;
    QCameraImageCapture *imageCapture;
    int m_frameIndex;

    TcpThread *tcpthread;
    TcpClient *m_client;

    QString   m_ip;
    QImage *m_frameImage;
};

#endif // MAINWINDOW_H

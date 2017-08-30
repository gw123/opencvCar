#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include "QTcpSocket"
#include <QAbstractSocket>
#include <QFile>
#include <QImage>
#include <QBuffer>
#include <QThread>
class TcpClient;

//处理收发文件的线程
class TcpThread : public QThread
{
public:
    TcpThread(QObject *parent = 0);
    ~TcpThread();

protected:
    void run();

public:
    TcpClient *m_worker;

};


////////////////////////////

class TcpClient :public QObject
{
   Q_OBJECT
public:
    TcpClient(QObject *parent);

    ~TcpClient();


    void setIP(QString ip);

public slots:
    void onReadyRead();
    void onByteWrite(qint64 len);
    void onError(QAbstractSocket::SocketError socketError);
    void onConnect();
    void sendFrame(QImage frame);



signals:
    void sendToDisplay(QString data);
    void miss();

public :
    QTcpSocket *m_socket;

private:

    bool  m_isConnect;

    qint64  frameindex;    //第几帧
    qint64  framesize;     //帧的大小
    qint64 bytesToWrite;
    QByteArray  outBlock;
    qint64 bytesWritten;
    qint64 loadSize;
    qint64 totalBytes;

};



#endif // TCPCLIENT_H

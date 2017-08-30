#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QThread>
#include <QTableWidget>
#include <QFile>

class MainWindow;
class TcpWorkThread;
class TcpWorker;
class TaskEvent;

class TcpServer : public QTcpServer
{
   Q_OBJECT
public:
    TcpServer(QObject* parent=0,QTableWidget *widget=NULL);
    ~TcpServer();
    void incomingConnection(qintptr handle);
    //创造一个线程池
    void  createThreadPool();
    //回去一个空闲的线程
    TcpWorkThread*  getIdleThread();
    void  setShowWidget(QTableWidget *widget);


signals:
    void  statusChange(int id,QString isRun,QString status);
protected slots:
    //void onNewConnection();
public slots:
    void onFinish(QByteArray request);
    void onTcpServerStatusChange(int id,QString isRun,QString stauts);
private:
    MainWindow       *m_receiver;
    TcpWorkThread    *m_thread;
    QList<TcpWorkThread*> m_threadPool;
    QTableWidget  *m_threadShow;
};

//
class TaskEvent:public QEvent
{
   // Q_OBJECT 加上这个编译器会报错
   public :
    TaskEvent(qintptr fd);
    qintptr fd;
    static Type eventType();

   private:
    static Type m_evType;
};



//工作者
class  TcpWorker :public QObject
{
  Q_OBJECT
  public :
    TcpWorker(QObject *parent=0);
    bool event(QEvent *e);
    //void doWork();
    //解析get请求
   // bool saveFile();
   // bool parseGetData(QByteArray &data);
    //构建新的socket 新任务
    void processConnection(qintptr fd);
    bool isBusy();
    //
    int  readALine();
signals:
    void proess(int proess,int total);
    void finish(QImage result);

  public slots:
     /*处理客户端发来的数据*/
     void onReadyRead();
     /*处理断开连接*/
     void onDisconnected();
  private:

     int m_proess;
     QTcpSocket *m_socket;
    //判断是否发送完成
     //bool isBlock=false;
     qint64   m_filesize;
     QString  m_filename;
     QString  m_ext;

     QFile    m_file;
     bool     m_flag=false;//标准位 用来是否要从流中读取一个字符
     qint64   m_total;
     bool m_sendFileEnd=false;

     qint64  bytesReceived;
     qint64  totalBytes;
     qint64  frameheadersize;
     QString fileName;

     qint64     frameindex;
     QImage     frame;
     QByteArray framebuffer;


};


class  TcpWorkThread :public QThread
{
  Q_OBJECT

  public :
     TcpWorkThread(QObject* parent,MainWindow *receiver);

     //将任务（新的套接字描述符传递给 线程的工作者）
     void postSocketToWorker(qintptr handle);
     //判断线程是否繁忙
     bool isBusy();
  public:
     void run();

  private:
     TcpWorker    *m_worker;
     MainWindow   *m_receiver;
};

#endif // TCPSERVER_H

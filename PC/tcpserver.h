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
    //����һ���̳߳�
    void  createThreadPool();
    //��ȥһ�����е��߳�
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
   // Q_OBJECT ��������������ᱨ��
   public :
    TaskEvent(qintptr fd);
    qintptr fd;
    static Type eventType();

   private:
    static Type m_evType;
};



//������
class  TcpWorker :public QObject
{
  Q_OBJECT
  public :
    TcpWorker(QObject *parent=0);
    bool event(QEvent *e);
    //void doWork();
    //����get����
   // bool saveFile();
   // bool parseGetData(QByteArray &data);
    //�����µ�socket ������
    void processConnection(qintptr fd);
    bool isBusy();
    //
    int  readALine();
signals:
    void proess(int proess,int total);
    void finish(QImage result);

  public slots:
     /*����ͻ��˷���������*/
     void onReadyRead();
     /*����Ͽ�����*/
     void onDisconnected();
  private:

     int m_proess;
     QTcpSocket *m_socket;
    //�ж��Ƿ������
     //bool isBlock=false;
     qint64   m_filesize;
     QString  m_filename;
     QString  m_ext;

     QFile    m_file;
     bool     m_flag=false;//��׼λ �����Ƿ�Ҫ�����ж�ȡһ���ַ�
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

     //�������µ��׽������������ݸ� �̵߳Ĺ����ߣ�
     void postSocketToWorker(qintptr handle);
     //�ж��߳��Ƿ�æ
     bool isBusy();
  public:
     void run();

  private:
     TcpWorker    *m_worker;
     MainWindow   *m_receiver;
};

#endif // TCPSERVER_H

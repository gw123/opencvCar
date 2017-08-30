#include "tcpserver.h"
#include <QFile>
#include <QBuffer>
#include <QProcess>
#include <QFileInfo>


TcpServer::TcpServer(QObject* parent,QTableWidget *widget):QTcpServer(parent),m_receiver((MainWindow*)parent)
{   //�����̳߳�
   connect(this,SIGNAL(statusChange(int,QString,QString)),this,SLOT(onTcpServerStatusChange(int,QString,QString)));
   //emit statusChange(2,"run","free");

   m_threadShow=widget;
   createThreadPool();
}

TcpServer::~TcpServer()
{   //�߳��˳�
    for(int i=0;i<m_threadPool.length();i++)
    {
        m_threadPool.at(i)->quit();
    }
}

void TcpServer::incomingConnection(qintptr handle)
{
    //qDebug()<<"new comimg";
    while((m_thread=getIdleThread())==NULL)
    {
         QThread::msleep(10);
    };
    //m_thread=getIdleThread();
    m_thread->postSocketToWorker(handle);
}

void TcpServer::createThreadPool()
{
    for(int i=0;i<2;i++)
    {
        m_thread=new TcpWorkThread(this,m_receiver);
        m_thread->start();
        m_threadPool.append(m_thread);
        QString label=tr("Thread%1").arg(i);

        //qDebug()<<label;
 //      m_threadShow->setItem(i, 0, new QTableWidgetItem(label));
 //      m_threadShow->setItem(i, 1, new QTableWidgetItem(tr("IS run%1").arg("run")));
 //        m_threadShow->setItem(i, 2, new QTableWidgetItem(tr("Status%1").arg("����")));
 //       emit statusChange(i,"run","free");
        //qDebug()<<i;
        //if(m_threadShow)m_threadShow->addItem(label);
    }

}

//��ȡһ�����е��߳�
TcpWorkThread *TcpServer::getIdleThread()
{
   for(int i=0;i<m_threadPool.length();i++)
   {
       if(!m_threadPool.at(i)->isBusy())
       {
           qDebug()<<i;
           return m_threadPool.at(i);
           break;
       }

   }
   return NULL;
}

void TcpServer::setShowWidget(QTableWidget *widget)
{
    m_threadShow=widget;
}



void TcpServer::onFinish(QByteArray request)
{

    qDebug()<<"data------>"<<request;
}

void TcpServer::onTcpServerStatusChange(int id, QString isRun, QString stauts)
{
    qDebug()<<"TcpServer::onTcpServerStatusChange"<<id;
}

/**************�¼���*******************/
QEvent::Type TaskEvent::m_evType=QEvent::None;

TaskEvent::TaskEvent(qintptr fd):QEvent(eventType()),fd(fd)
{}

QEvent::Type TaskEvent::eventType()
{
    if(m_evType==QEvent::None)
    {
        m_evType=(QEvent::Type)registerEventType();
    }
    return m_evType;
}






/***************������******************/
TcpWorker::TcpWorker(QObject *parent)
{
    this->m_socket=NULL; this->m_total=0;
    this->m_proess=0;  m_flag=false;
    m_sendFileEnd=false;
    frameheadersize=0;
    bytesReceived = 0; // clear for next receive
    totalBytes = 0;

}

bool TcpWorker::event(QEvent *e)
{

    if(e->type()==TaskEvent::eventType())
    {
        processConnection(((TaskEvent*)e)->fd);
        qDebug()<<"new task :"<<(unsigned int)QThread::currentThreadId();
    }
    return QObject::event(e);
}

void TcpWorker::processConnection(qintptr fd)
{
    QTcpSocket *socket=new QTcpSocket();
    socket->setSocketDescriptor(fd);
    m_socket=socket;

    connect(m_socket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(m_socket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
}

bool TcpWorker::isBusy()
{
    if(m_socket==NULL)
    {qDebug()<<"not busy";return false;}
    else{qDebug()<<"busy";}
    return true;
}


void TcpWorker::onReadyRead()
{
   // qDebug()<<"onReadyRead"<<m_socket->bytesAvailable();
    QDataStream in(m_socket);
    in.setVersion(QDataStream::Qt_5_0);
    //������յ�������С�ڵ���16���ֽڣ���ô�Ǹտ�ʼ�������ݣ����Ǳ���Ϊͷ�ļ���Ϣ
    if(bytesReceived <= sizeof(qint64)*2)
    {
        //���������ܴ�С��Ϣ���ļ�����С��Ϣ
        if((m_socket->bytesAvailable() >= sizeof(qint64)*2) && (frameheadersize == 0))
        {
            in >> totalBytes >> frameheadersize;
           // qDebug()<<"totoalByte:"<<totalBytes<<" "<<"Header size:"<<frameheadersize;
            bytesReceived += sizeof(qint64) * 2;
        }
        //�����ļ������������ļ�
        if((m_socket->bytesAvailable() >= frameheadersize) && (frameheadersize != 0))
        {
            in >> frameindex;
            //qDebug()<<frameindex;
           //qDebug()<<framebuffer.size();
            framebuffer.resize(0);
            //ui->currentStatusLabel->setText(tr("Accept file %1 ...").arg(fileName));
            bytesReceived += frameheadersize;
        }
        else
            return;
    }

    //������յ�����С�������ݣ���ôд���ļ�
    if(bytesReceived < totalBytes)
    {
        int left=totalBytes-bytesReceived;
        bytesReceived += m_socket->bytesAvailable();

        if(bytesReceived>totalBytes)
        {
            bytesReceived=totalBytes;
            QByteArray inBlock = m_socket->read(left);
            framebuffer.append(inBlock);
            inBlock.resize(0);

        }else{
            QByteArray inBlock = m_socket->readAll();
            framebuffer.append(inBlock);
            inBlock.resize(0);
        }

       // qDebug()<<"bytesReceived"<<bytesReceived;
    }

    //���½�����
    //emit proess(bytesReceived,totalBytes);
    //�����������ʱ
    if(bytesReceived == totalBytes)
    {
        //tcpSocket->close();
        //ui->listenButton->setEnabled(true);
        //ui->currentStatusLabel->setText(tr("Status: receive file %1 successfully!").arg(fileName));
        bytesReceived = 0; // clear for next receive
        totalBytes = 0;
        frameheadersize = 0;
       // QFile log("log.txt");
        //log.open(QFile::WriteOnly);
        //Ī���������ļ�ͷ�����4���ֽ�
        framebuffer=framebuffer.remove(0,4);
        //log.write(framebuffer);
        //log.close();

        if(frame.loadFromData(framebuffer))
        {
          //  qDebug()<<"load success";
        }else{
          //  qDebug()<<"load faild";
        };

        emit finish(frame);
        frameindex++;

    }
}



void TcpWorker::onDisconnected()
{  //ɾ���ö����ҽ�����Ϊ��
    qDebug()<<"socket end";
    m_socket->deleteLater();
    m_socket=NULL;

}

/*********************************/
void TcpWorkThread::run()
{
    qDebug()<<"new TcpWorkThread :"<<(unsigned int)QThread::currentThreadId();
    m_worker=new TcpWorker();
    connect(m_worker,SIGNAL(finish(QImage)),this->parent()->parent(),SLOT(onFinish(QImage)));
    //connect(m_worker,SIGNAL(proess(int,int)),this,
    //connect(m_worker,SIGNAL(finish(QByteArray)),this->parent(),SLOT(onFinish(QByteArray)));
    //connect(m_worker,SIGNAL(finish(QByteArray)),m_receiver,SLOT(onFinish()))
    //connect(m_worker,SIGNAL(finish(QObject*)),
    exec();
}

TcpWorkThread::TcpWorkThread(QObject *parent,MainWindow *receiver):
    QThread(parent),m_receiver(receiver)
{

}

void TcpWorkThread::postSocketToWorker(qintptr handle)
{

    QCoreApplication::postEvent(m_worker,new TaskEvent(handle));
}

bool TcpWorkThread::isBusy()
{
    return m_worker->isBusy();
}




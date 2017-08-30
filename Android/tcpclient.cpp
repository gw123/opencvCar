#include "tcpclient.h"
#include <QHostAddress>
#include <QDebug>
#include <QDataStream>
#include <QBuffer>
#include <QAbstractSocket>


TcpClient::TcpClient(QObject *parent):QObject(parent)
{
   m_socket=new QTcpSocket(this);
   m_isConnect=false;   framesize=0;
   bytesToWrite=0;      bytesWritten=0;
   loadSize=2048;       totalBytes=0;
   frameindex=0;

   //m_socket->connectToHost("192.168.198.228",8080);
  // m_socket->waitForConnected();

   connect(m_socket,SIGNAL(disconnected()),m_socket,SLOT(deleteLater()));
   connect(m_socket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
   connect(m_socket,SIGNAL(bytesWritten(qint64)),this,SLOT(onByteWrite(qint64)));

   qRegisterMetaType<QAbstractSocket::SocketError>("QAbstractSocket::SocketError");
   connect(m_socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError(QAbstractSocket::SocketError)));
   connect(m_socket,SIGNAL(connected()),this,SLOT(onConnect()));


}

TcpClient::~TcpClient()
{

}

void TcpClient::setIP(QString ip)
{
    m_socket->disconnectFromHost();
    if (m_socket->state() == QAbstractSocket::UnconnectedState || m_socket->waitForDisconnected(1000))
    {
      m_socket->connectToHost(ip,8080);
    }


}


void TcpClient::sendFrame(QImage frame)
{
    // m_socket->write("hello world 1213123123131231231");return;
     //m_socket; return;
     if(m_socket==NULL) { qDebug()<<"socket not open ";  emit sendToDisplay(tr("socket not open"));return;}
     if(frame.isNull()) { qDebug()<<"frame is null "; return;}
     if(!m_socket->isOpen()||!m_socket->isValid())  { qDebug()<<"socket not ok "; return;}

     QByteArray temp;
     QBuffer buffer(&temp);
     buffer.open(QIODevice::WriteOnly);

     frame.save(&buffer, "JPEG");
     //buffer.close();
     framesize=temp.length();

     frameindex++;

     QDataStream sendOut(&outBlock, QIODevice::WriteOnly);
     sendOut.setVersion(QDataStream::Qt_5_0);

     //依次写入总大小信息空间，文件名大小信息空间，文件名
     sendOut << qint64(0) << qint64(0) << frameindex<<temp;
     //这里的总大小是文件名大小等信息和实际文件大小的总和
     //totalBytes=framesize + 3*sizeof(qint64);
     totalBytes=outBlock.size();
     //返回outBolock的开始，用实际的大小信息代替两个qint64(0)空间
     sendOut.device()->seek(0);
     sendOut<<totalBytes<<qint64(sizeof(qint64));

     int len=m_socket->write(outBlock);
     //qDebug()<<" sendFrame len:"<<len<<m_socket->errorString();
     emit sendToDisplay(tr("begin send:%1").arg(frameindex));

}

//
void TcpClient::onReadyRead()
{
  QByteArray arr=  m_socket->readAll();

  emit sendToDisplay(tr("服务端消息：%1").arg(QString(arr)));
}


void TcpClient::onByteWrite(qint64 len)
{
   //qDebug()<<"bytewrite"<<len;
}

void TcpClient::onError(QAbstractSocket::SocketError socketError)
{
    qDebug()<<"SocketError: "<<socketError;

    emit sendToDisplay(tr("连接出错：%1").arg(socketError));
}

void TcpClient::onConnect()
{
    qDebug()<<"onConnect";
    emit sendToDisplay("已经连接");
    m_isConnect=true;
}






//////////////////////////
TcpThread::TcpThread(QObject *parent):QThread(parent)
{

}

TcpThread::~TcpThread()
{

}

void TcpThread::run()
{

   exec();
}


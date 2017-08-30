#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QVideoEncoderSettings>
#include <QCameraImageCapture>
#include <QVideoProbe>
#include <QBuffer>
#include <QList>
#include <QHostAddress>

QList<QImage>  imageList;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->groupBox->hide();
    m_camera  =new QCamera(this);
    this->viewfinder=new QCameraViewfinder ;
    m_camera->setViewfinder(this->viewfinder);
    m_camera->setCaptureMode(QCamera::CaptureVideo);
    m_camera->start();

    m_frameImage=new QImage(640,640,QImage::Format_RGB32);

    QVideoProbe   *probe=new QVideoProbe(this) ;
    probe->setSource(m_camera);

    connect(probe, SIGNAL(videoFrameProbed(QVideoFrame)), this, SLOT(processFrame(QVideoFrame)));
    m_frameIndex=0;

    m_client=NULL;
    tcpthread=new TcpThread(this);
    tcpthread->start();
}

MainWindow::~MainWindow()
{
    tcpthread->exit();
    delete ui;
}


void MainWindow::processFrame(QVideoFrame frame)
{

    static int index=0;
    Q_UNUSED(frame);
    if (frame.isValid())
    {
      QVideoFrame cloneFrame(frame);
      cloneFrame.map(QAbstractVideoBuffer::ReadOnly);

      //qDebug()<<"width:"<<cloneFrame.width()<<"height:"<<cloneFrame.height();
      //qDebug()<<cloneFrame.pixelFormat();


       convertYUV420_NV21toARGB8888(cloneFrame.bits(),m_frameImage->bits(),
                     cloneFrame.width(),
                     cloneFrame.height());

       ui->label->setPixmap(QPixmap::fromImage(*m_frameImage));

       if(index++%2==1)
       {
           if(m_client&&m_client->m_socket->isOpen()&&m_client->m_socket->bytesToWrite()==0)
           {m_client->sendFrame(*m_frameImage);}
       }
       cloneFrame.unmap();
       return ;
   }
    ui->textshow->appendPlainText("frame is not valid");
    //qDebug()<<"not valid frame";
}

void MainWindow::onDisplay(QString msg)
{
    if(ui->textshow->height()>100)
    {
      ui->textshow->clear();
    }
    ui->textshow->appendPlainText(msg);
}

int inline  yvuToRgb(int y,int u,int v)
{
       static int r, g , b;
       r = y + (int)(1.402f*u);
       g = y - (int)(0.344f*v + 0.714f*u);
       b = y + (int)(1.772f*v);
       r = r>255? 255 : r<0 ? 0 : r;
       g = g>255? 255 : g<0 ? 0 : g;
       b = b>255? 255 : b<0 ? 0 : b;
       return 0xff000000 | (r<<16) | (g<<8) | b;
}

void MainWindow::convertYUV420_NV21toARGB8888(uchar *data,uchar* to ,int width, int height)
{
  int size = width*height;
  int offset = size;
  int* pixels=(int*) to;
  int u, v, y1, y2, y3, y4,r,g,b;
  int i=0;

  int x_start=(width -640)/2/2*2;
  int y_start=(height-640)/2/2*2;

  int rowindex1;

  //zheli xuan zhuan 90@
  for(int i=0;i<640;i++)
  {
      rowindex1=width*(i+y_start)+x_start;
      for(int j=0;j<640;j++)
      {
         pixels[j*640+640-i]=data[rowindex1+j];
      }
  }

//  for(int i=0;i<640;i+=2)
//  {
//      rowindex1=width*(i+y_start)+x_start;
//      rowindex2=width*(i+y_start+1)+x_start;
//      rowindex3=((i+y_start)/2+height)*width+x_start;

//      for(int j=0;j<640;j+=2)
//      {
//         //pixels[j*640+640-i]=data[rowindex1+j];
//         y1=data[rowindex1+j];
//         y2=data[rowindex1+j+1];
//         y3=data[rowindex2+j];
//         y4=data[rowindex2+j+1];

//         u=data[rowindex3+j];
//         v=data[rowindex3+j+1];
//         pixels[j*640+640-i]=yvuToRgb(y1,u,v);
//         pixels[j*640+640-i+1]=yvuToRgb(y1,u,v);
//         pixels[j*640+1280-i]=yvuToRgb(y1,u,v);
//         pixels[j*640+1280-i+1]=yvuToRgb(y1,u,v);
//      }
//  }

}



void MainWindow::on_btnSetting_clicked()
{
   static int i=0;
   if(i++%2==0)
   {
     ui->groupBox->show();
   }else{

     ui->groupBox->hide();
     m_ip=ui->edit_IP->text().trimmed();
     QString s=tr("设置IP：%1").arg(m_ip);

     delete m_client;
     m_client=new TcpClient(0);
     m_client->moveToThread(tcpthread);
     m_client->setIP(m_ip);

     connect(m_client,SIGNAL(sendToDisplay(QString)),this,SLOT(onDisplay(QString)));
     ui->textshow->appendPlainText(s);

   }
}

void MainWindow::on_btnEnd_clicked()
{
    qApp->exit();
}

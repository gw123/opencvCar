#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    tcpServer=new TcpServer(this,0);
    tcpServer->listen(QHostAddress::Any,8080);

    //将接受图片到的图片传递到 图片处理线程中
    connect(this,SIGNAL(tcpNewFrame(QImage)),&imageProc,SLOT(onNewImage(QImage)));

    connect(&videoReader,SIGNAL(frameAvailable(QImage)),this,SLOT(on_FrameAvailable(QImage)));

    connect(&imageProc,SIGNAL(frameDealed(QImage)),this,SLOT(on_FrameDealed(QImage)));
    connect(&videoReader,SIGNAL(frameMatToDeal(Mat)),&imageProc,SLOT(onNewFrame(Mat)));

    connect(&imageProc,SIGNAL(frameMatToDeal(Mat)),&navImagePorc,SLOT(onNewFrame(Mat)));
    connect(&navImagePorc,SIGNAL(frameDealed(QImage)),this,SLOT(on_FrameNav(QImage)));
    connect(&navImagePorc,SIGNAL(sendNav(QString)),this,SLOT(on_SendNav(QString)));
    lablesize=ui->label_2->size();

    if(!imageProc.isRunning())
       imageProc.start();

   if(!navImagePorc.isRunning())
        navImagePorc.start();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_FrameAvailable(QImage img)
{
    //qDebug()<<" MainWindow::on_FrameAvailable";
    //img=img.scaled(278,197,
   //       Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
    ui->lable_1->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_FrameDealed(QImage img)
{
   // qDebug()<<"MainWindow::on_FrameDealed";
   // img=img.scaled(278,197,
   //       Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
    ui->label_2->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_FrameNav(QImage img)
{
   // qDebug()<<"MainWindow::on_FrameNav"<<lablesize.width();
     //img=img.scaled(278,197,
     //     Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
     ui->label_3->setPixmap(QPixmap::fromImage(img));
}

// 方向信息
void MainWindow::on_SendNav(QString nav)
{
       ui->label_4->setText(nav);
//     QImage img;
//     img.load(":/image/fangxiang/image/fangxiang/fangxiangpan.png");
//     if(nav=="Left")
//     {
//         QTransform tr;
//         tr.rotate(300);
//         img=img.transformed(tr);
//     }
//     if(nav=="Right")
//     {
//         QTransform tr;
//         tr.rotate(60);
//         img=img.transformed(tr);
//     }

//     ui->label_4->setPixmap(QPixmap::fromImage(img));

}

// 从TCP 流中读取帧
void MainWindow::onFinish(QImage img)
{
    //qDebug()<<" MainWindow::onFinish:: new image coming ";

    img=img.scaled(320,320,
          Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
    //qDebug()<<"MainWindow::onFinish image:"<<img.width()<<img.height();
    ui->lable_1->setPixmap(QPixmap::fromImage(img));
    //发送到图片处理线程
    emit  tcpNewFrame(img);
}


void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton & m_bDrag ) {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton  ) {
        m_bDrag = TRUE;
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_bDrag = FALSE;
}





void MainWindow::on_btnUp_clicked()
{
    ui->label_4->setText("up");
}

void MainWindow::on_btnLeft_clicked()
{
    ui->label_4->setText("left");
}

void MainWindow::on_btnRight_clicked()
{
    ui->label_4->setText("right");
}

void MainWindow::on_btnDown_clicked()
{
    ui->label_4->setText("down");
}

void MainWindow::on_btnSelectVideoFile_clicked()
{
   QString fileName=QFileDialog::getOpenFileName(this, tr("视频文件"),
   QDir::homePath(), tr("(*.*)"));
   ui->label_videopath->setText("Path"+fileName);
   videoReader.open(fileName);
}



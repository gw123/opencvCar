#include "imageproc.h"

ImageProc::ImageProc(QObject *parent)
{

}

void ImageProc::onNewFrame(Mat m)
{
    //qDebug()<<"ImageProc::onNewFrame";
    this->matList.append(m);
}

void ImageProc::onNewImage(QImage img)
{
    // qDebug()<<"ImageProc::onNewFrame"<<img.width()<<":"<<img.height();
    Mat m=QImage2cvMat(img);
    //Mat m=imread("E:/yingying.png");
    this->matList.append(m);
}

void ImageProc::run()
{
  QImage img;
  Mat ele=getStructuringElement(MORPH_RECT,Size(4,4));
  Mat ele1=getStructuringElement(MORPH_RECT,Size(10,10));
  //注册Mat这个类型
  qRegisterMetaType<Mat>("Mat");
  while(1)
  {

    if(matList.empty())
    {
       msleep(10); continue;
    }

     Mat frame= matList.takeFirst();
     cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
     blur(frame,frame,Size(10,10));
     erode(frame,frame,ele);

     erode(frame,frame,ele1);

     img= MatToQImage(frame);
    // qDebug()<<"imageproc:"<<" "<<matList.length();
     emit(frameDealed(img));
     emit(frameMatToDeal(frame));
  }

  exec();
}




////////////////////////////////////////


NavImagePorc::NavImagePorc()
{

}

void NavImagePorc::run()
{
    QImage img;
    Mat frame;

    while(matList.empty())
    {
       msleep(10);
    }
    frame=matList.takeFirst();
    int row,col;
    //这里在以后   尺寸变化后需要改动
    row=frame.rows;
    col=frame.cols;

    int y_start=col/3;
    int y_end=col-col/4;
    int col1=col/3;
    int col2=col1+col1;
    int col3=col2+col1;
    //qDebug()<<" col1 "<<col1<<" col2 "<<col2<<" col3 "<<col3;
    //处理后的图像
    Mat copy(320,320,CV_8UC1);
    //灰度表
    uchar table[256];
    for(int i=0;i<256;i++)
    {
      table[i]=i/20*20;
    }

    int total1=0,total2=0,total3=0;
    uchar tempData[1];
    int   rowN_pos;
    int   elementSize=frame.step[1];
    int   colOffset;

    while(1)
    {
      if(matList.empty())
      {
         msleep(10); continue;
      }


      frame = matList.takeFirst();

      // 遍历图片
      total1=0,total2=0,total3=0;

      for(int y=y_start;y<y_end;y++)
      {
         rowN_pos=frame.step[0]*y;
         colOffset=0;

         for(int x=0 ;x<col1;x++)
         {

            tempData[0]=*(frame.data+rowN_pos+colOffset);
            tempData[0]<160?(tempData[0]=0,total1++):(tempData[0]=255);
            *(copy.data+rowN_pos+colOffset)=table[tempData[0]];

            colOffset+=elementSize;
         }
         for(int x=col1;x<col2;x++)
         {

            tempData[0]=*(frame.data+rowN_pos+colOffset);
            tempData[0]<160?(tempData[0]=0,total2++):(tempData[0]=255);
           *(copy.data+rowN_pos+colOffset)=table[tempData[0]];
            colOffset+=elementSize;

         }
         for(int x=col2;x<col3;x++)
         {

            tempData[0]=*(frame.data+rowN_pos+colOffset);
            tempData[0]<160?(tempData[0]=0,total3++):(tempData[0]=255);
            *(copy.data+rowN_pos+colOffset)=table[tempData[0]];
            colOffset+=elementSize;
         }

     } //for end

      // 320*160=51200  , /3=17000 ,  /2=8533

      img = MatToQImage(copy);
      emit(frameDealed(img));
      qDebug()<<" MM "<<total1<<" "<<total2<<" "<<total3;

      if(total1<2000&&total2<2000&&total3<2000) // 路面信息比较模糊
      {
          emit(sendNav("cannot shibbie"));

      }else if(total1>=total2&&total1>=total3)
      {
          if(total1-total2<1000)
          emit(sendNav("Left little"));
          else
          emit(sendNav("Left "));

      }else if(total3>total2)
      {
          if(total3-total2<1000)
          emit(sendNav("Right little"));
          else
          emit(sendNav("Right"));
      }else{
          if(total2-total1<1000)
          {
              //qDebug()<<"Left little";
               emit(sendNav("Left little"));
          }else if(total2-total3<1000){
             // qDebug()<<"Right littel";
               emit(sendNav("Right littel"));
          }else{
            //  qDebug()<<"go ahead";
               emit(sendNav("go ahead"));
          }
      }

    }//while(1) end

    exec();
}

void NavImagePorc::onNewFrame(Mat m)
{
    qDebug()<<"NavImage::onNewFrame";
  this->matList.append(m);
}

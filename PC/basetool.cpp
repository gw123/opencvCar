#include "basetool.h"


QImage MatToQImage(const Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS=1
    if(mat.type()==CV_8UC1)
    {
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    if(mat.type()==CV_8UC3)
    {
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}



// 将32位的qimage 图像转换为 24位的mat
Mat QImage2cvMat(QImage image32)
{
    Mat mat;
    mat = cv::Mat(image32.height(), image32.width(), CV_8UC3);
    uchar *imagebits_32;
    uchar *matbits_24;
    //uchar *matData=mat.data;
    int lineIndex=0;
    int lineIndex1=0;
    int height=image32.height();
    int width=image32.width();
    //
    int value;
    for(int i=0; i<height; ++i)
    {
           imagebits_32 = image32.scanLine(i);
           matbits_24=mat.ptr(i);
           lineIndex=0;
           lineIndex1=0;
          for(int j=0; j<width; ++j)
          {
                   //int r_32 = imagebits_32[ lineIndex + 2];
                   //int g_32 = imagebits_32[ lineIndex + 1];
                   value= imagebits_32[ lineIndex];
                   matbits_24[lineIndex1]=value;
                   matbits_24[lineIndex1+1]=value;
                   matbits_24[lineIndex1+2]=value;
                   // int r_24 = imagebits_24[ j * 3];
                   // int g_24 = imagebits_24[ j *3 + 1];
                   // int b_24 = imagebits_24[ j * 3 + 2];
                   // int gray_8 = imagebits_8[ j ];
            lineIndex+=4;
            lineIndex1+=3;
          }
    }

//    // qDebug() << image.format();
//    switch(image.format())
//    {

//    case QImage::Format_ARGB32:
//    case QImage::Format_RGB32:
//    case QImage::Format_ARGB32_Premultiplied:
//        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.bits(), image.bytesPerLine());
//        break;
//    case QImage::Format_RGB888:
//        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.bits(), image.bytesPerLine());
//        cv::cvtColor(mat, mat, CV_BGR2RGB);
//        break;
//    case QImage::Format_Indexed8:
//        mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.bits(), image.bytesPerLine());
//        break;
//    }
    return mat;
}



#ifndef BASETOOL_H
#define BASETOOL_H


#include <QtGui>
#include <QDebug>

#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace cv;

//Mat he Qimage Ïà»¥×ª»»

QImage MatToQImage(const Mat&);

Mat QImage2cvMat(QImage image);

#endif // BASETOOL_H

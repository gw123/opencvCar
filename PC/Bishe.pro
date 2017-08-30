#-------------------------------------------------
#
# Project created by QtCreator 2016-05-11T09:00:07
#
#-------------------------------------------------

QT       += core gui  network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bishe
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imageproc.cpp \
    basetool.cpp \
    tcpserver.cpp

HEADERS  += mainwindow.h \
    imageproc.h \
    basetool.h \
    tcpserver.h

FORMS    += mainwindow.ui


INCLUDEPATH = "E:/Qt/Opencv/opencv/build/include"

LIBS += E:/Qt/opencvmingw/lib/libopencv_calib3d2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_calib3d_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_contrib2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_contrib_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_core2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_core_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_features2d2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_features2d_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_flann2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_flann_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_gpu2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_gpu_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_haartraining_engine.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_highgui2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_highgui_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_imgproc2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_imgproc_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_legacy2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_legacy_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_ml2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_ml_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_nonfree2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_nonfree_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_objdetect2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_objdetect_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_ocl2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_ocl_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_perf_calib3d_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_perf_core_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_perf_features2d_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_perf_gpu_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_perf_highgui_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_perf_imgproc_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_perf_nonfree_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_perf_objdetect_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_perf_ocl_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_perf_photo_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_perf_stitching_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_perf_superres_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_perf_video_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_photo2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_photo_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_stitching2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_stitching_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_superres2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_superres_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_calib3d_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_contrib_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_core_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_features2d_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_flann_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_gpu_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_highgui_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_imgproc_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_legacy_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_ml_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_nonfree_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_objdetect_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_ocl_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_photo_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_stitching_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_superres_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_test_video_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_ts2412.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_ts_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_video2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_videostab2412.dll.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_videostab_pch_dephelp.a
LIBS += E:/Qt/opencvmingw/lib/libopencv_video_pch_dephelp.a

RESOURCES += \
    res.qrc

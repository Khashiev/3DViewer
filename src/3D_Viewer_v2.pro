QT  += core gui opengl
QT  += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += openglwidgets

CONFIG += c++17 silent

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gifanim/gifanim.cpp \
    main.cc \
    mainwindow.cc \
    model/s21_affine_transformation.cc \
    model/s21_affine_transformation_facade.cc \
    model/s21_matrix_plus.cc \
    model/s21_parser.cc \

HEADERS += \
    gifanim/gifanim.h \
    mainwindow.h \
    model/s21_affine_transformation.h \
    model/s21_affine_transformation_facade.h \
    model/s21_matrix_oop.h \
    model/s21_parser.h \
    s21_controller.h \

FORMS += \
    mainwindow.ui

DISTFILES += \
    Makefile \
    readme/readme.texi \
    # Old tests.
    tests/main.cc \
    # New tests.
    tests/test_parser.cc \
    tests/obj/cube.obj \
    tests/obj/parser.txt \
    tests/test_affine_trans.cc \
    model/test.cc \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

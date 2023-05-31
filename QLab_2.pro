QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    AbstractFactory.h \
    ClassUnit.h \
    MethodUnit.h \
    PrintOperatorUnit.h \
    Unit.h \
    cpp/CPP_ClassUnit.h \
    cpp/CPP_Factory.h \
    cpp/CPP_MethodUnit.h \
    cpp/CPP_PrintOperatorUnit.h \
    csharp/CSHARP_ClassUnit.h \
    csharp/CSHARP_Factory.h \
    csharp/CSHARP_MethodUnit.h \
    csharp/CSHARP_PrintOperatorUnit.h \
    include/ClassUnit.h \
    include/Factory.h \
    include/MethodUnit.h \
    include/PrintOperatorUnit.h \
    include/Unit.h \
    java/JAVA_ClassUnit.h \
    java/JAVA_Factory.h \
    java/JAVA_MethodUnit.h \
    java/JAVA_PrintOperatorUnit.h

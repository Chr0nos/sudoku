TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    chained_list.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    main.h \
    chained_list.h


TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    chained_list.c \
    my_printf.c \
    my_strlen.c \
    check_grid.c \
    my_atoi.c \
    my_itoa.c \
    my_strrev.c \
    my_memset.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    main.h \
    chained_list.h \
    my_strlen.h \
    my_printf.h \
    check_grid.h \
    my_atoi.h \
    my_itoa.h \
    my_strrev.h \
    my_memset.h


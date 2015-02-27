TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    chained_list.c \
    ft_printf.c \
    ft_strlen.c \
    check_grid.c \
    ft_atoi.c \
    ft_itoa.c \
    ft_strrev.c \
    ft_memset.c \
    ft_itohex.c \
    ft_memcpy.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    main.h \
    chained_list.h \
    ft_strlen.h \
    ft_printf.h \
    check_grid.h \
    ft_atoi.h \
    ft_itoa.h \
    ft_strrev.h \
    ft_memset.h \
    ft_itohex.h \
    ft_memcpy.h


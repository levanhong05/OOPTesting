TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    customer.cpp \
    product.cpp \
    stock.cpp \
    order.cpp \
    store.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    customer.h \
    product.h \
    stock.h \
    order.h \
    store.h


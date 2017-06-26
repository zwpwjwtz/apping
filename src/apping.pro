TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    help.cpp \
    info.cpp \
    uninstall.cpp \
    reinstall.cpp \
    error.cpp \
    app.cpp \
    install.cpp \
    subsystem/app.cpp \
    subsystem/help.cpp \
    subsystem/info.cpp \
    subsystem/install.cpp \
    subsystem/reinstall.cpp \
    subsystem/uninstall.cpp \
    error.cpp \
    main.cpp

HEADERS += \
    main.h \
    help.h \
    i18n.h \
    error.h \
    info.h \
    app.h \
    install.h \
    reinstall.h \
    uninstall.h \
    subsystem/app.h \
    subsystem/help.h \
    subsystem/info.h \
    subsystem/install.h \
    subsystem/reinstall.h \
    subsystem/uninstall.h \
    error.h \
    i18n.h \
    main.h \
    subsystem/uninstall.h \
    subsystem/reinstall.h

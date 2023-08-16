TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        cpu.cpp \
        main.cpp \
        memory_ram.cpp

HEADERS += \
    aliases.h \
    cpu.h \
    memory_ram.h \
    opcodes.h


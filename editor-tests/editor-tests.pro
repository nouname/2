include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     \
    ../app/text/text.h \
    ../app/text/_text.h \
    tests.h

SOURCES +=     main.cpp \
    ../app/mcf.c \
    ../app/mpweb.c \
    ../app/ple.c \
    ../app/text/append_line.c \
    ../app/text/change_cursor_position.c \
    ../app/text/create_text.c \
    ../app/text/delete_line.c \
    ../app/text/process_forward.c \
    ../app/text/remove_all.c \
    ../app/load.c \
    ../app/show.c \
    ../app/shownum.c \
    ../app/save.c \
    ../app/getcrsr.c \
    ../app/mwcrsr.c \
    ../app/text/create_objects.c

QMAKE_CXXFLAGS += -std=c++0x

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

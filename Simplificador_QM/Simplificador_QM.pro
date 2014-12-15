#-------------------------------------------------
#
# Project created by QtCreator 2014-11-18T16:35:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Simplificador_QM
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    quine_mccluskey.cpp \
    AndNode.cpp \
    ContentReader.cpp \
    IdNode.cpp \
    Lexer.cpp \
    LexicalException.cpp \
    NotNode.cpp \
    OrNode.cpp \
    Parser.cpp \
    SyntacticException.cpp \
    Token.cpp

HEADERS  += mainwindow.h \
    quine_mccluskey.h \
    AndNode.h \
    ContentReader.h \
    IdNode.h \
    Lexer.h \
    LexicalException.h \
    Node.h \
    NotNode.h \
    OrNode.h \
    Parser.h \
    SyntacticException.h \
    Token.h

FORMS    += mainwindow.ui

RESOURCES += \
    graphics.qrc

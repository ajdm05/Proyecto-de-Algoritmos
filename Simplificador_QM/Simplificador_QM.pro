#-------------------------------------------------
#
# Project created by QtCreator 2014-11-18T16:35:04
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Simplificador_QM
TEMPLATE = app


SOURCES += main.cpp\
        Windows\mainwindow.cpp \
    Expression\AndNode.cpp \
    Parsing\ContentReader.cpp \
    Expression\IdNode.cpp \
    Parsing\Lexer.cpp \
    Exceptions\LexicalException.cpp \
    Expression\NotNode.cpp \
    Expression\OrNode.cpp \
    Parsing\Parser.cpp \
    Exceptions\SyntacticException.cpp \
    Parsing\Token.cpp \
    Graphing\qcustomplot.cpp \
    Algorithm/quine_mccluskey.cpp

HEADERS  += Windows\mainwindow.h \
    Expression\AndNode.h \
    Parsing\ContentReader.h \
    Expression\IdNode.h \
    Parsing\Lexer.h \
    Exceptions\LexicalException.h \
    Expression\Node.h \
    Expression\NotNode.h \
    Expression\OrNode.h \
    Parsing\Parser.h \
    Exceptions\SyntacticException.h \
    Parsing\Token.h \
    Graphing\qcustomplot.h \
    Algorithm/quine_mccluskey.h

FORMS    += Windows\mainwindow.ui

RESOURCES += \
    graphics.qrc

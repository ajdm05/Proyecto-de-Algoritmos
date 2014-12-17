#include "LexicalException.h"

LexicalException::LexicalException(const char* msg){
    this->msg = msg;
}

const char * LexicalException::what() const throw(){
    return msg;
}


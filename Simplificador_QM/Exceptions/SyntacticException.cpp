#include "SyntacticException.h"

SyntacticException::SyntacticException(const char* msg){
    this->msg = msg;
}

const char * SyntacticException::what() const throw(){
    return msg;
}

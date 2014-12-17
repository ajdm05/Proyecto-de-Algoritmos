#ifndef PARSER_H
#define	PARSER_H

#include "ContentReader.h"
#include "Lexer.h"
#include "Expression/Node.h"


class Parser {
public:
    Parser(char *input);
    ~Parser();
    Node* Parse();
private:
    Lexer* lexer;
    Token currentToken;
    
    Node* S();
    Node* Sp();
    Node* T();
    Node* U();
};

#endif	/* PARSER_H */


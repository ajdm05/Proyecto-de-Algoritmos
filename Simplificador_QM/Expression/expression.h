#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "IdNode.h"
#include "NotNode.h"
#include "OrNode.h"
#include "AndNode.h"
#include <map>

class Expression
{
public:
    Expression();
    bool evaluateExpression(map<string,bool> *values);
private:
    Node* root;

};

#endif // EXPRESSION_H

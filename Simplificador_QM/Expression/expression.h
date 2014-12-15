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
    bool evaluateNode(Node* node, map<string,bool>* values);
};

#endif // EXPRESSION_H

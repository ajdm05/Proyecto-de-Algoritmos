#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "IdNode.h"
#include "NotNode.h"
#include "OrNode.h"
#include "AndNode.h"
#include <map>
#include <vector>

using namespace std;

class Expression
{
public:
    Expression();
    bool evaluateExpression(map<string,bool> *values);
    vector<string> getVariableNames();
private:
    Node* root;
    bool evaluateNode(Node* node, map<string,bool>* values);
    void getVariables(Node* node, vector<string>* vector);
    void pushUniqueVariable(string, vector<string>*);
};

#endif // EXPRESSION_H

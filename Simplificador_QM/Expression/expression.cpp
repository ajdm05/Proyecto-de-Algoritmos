#include "expression.h"

Expression::Expression()
{
}

bool Expression::evaluateExpression(map<string, bool> *values)
{
    return evaluateNode(root, values);
}

vector<string> Expression::getVariableNames()
{
    vector<string> names;
    getVariables(root, &names);
}

bool Expression::evaluateNode(Node* node, map<string,bool>* values){
    if(node->getType() == AndNodeType){
        return evaluateNode( ((AndNode*)node)->getIzqNode() , values)
                && evaluateNode( ((AndNode*)node)->getDerNode(), values);
    }else if(node->getType() == OrNodeType){
        return evaluateNode( ((OrNode*)node)->getIzqNode(), values )
                || evaluateNode(((OrNode*)node)->getDerNode(), values);
    }else if(node->getType() == NotNodeType){
        return ! evaluateNode( ((NotNode*)node)->getNode(), values);
    }else if(node->getType() == IdNodeType){
        return values->at( ((IdNode*)node)->getId() );
    }
    return false;
}

void Expression::getVariables(Node *node, vector<string> *vector)
{
    if(node->getType() == AndNodeType){
        getVariables( ((AndNode*)node )->getIzqNode(), vector );
        getVariables( ((OrNode*)node)->getDerNode(), vector);
    }else if(node->getType() == OrNodeType){
        getVariables( ((OrNode*)node)->getIzqNode(), vector);
        getVariables( ((OrNode*)node)->getDerNode(), vector);
    }else if(node->getType() == NotNodeType){
        getVariables( ((NotNode*)node)->getNode(), vector);
    }else if(node->getType() == IdNodeType){
        pushUniqueVariable( ((IdNode*)node)->getId(), vector );
    }
}

void Expression::pushUniqueVariable(string variableName, vector<string> *variableVector)
{
    bool found = false;
    for(int i = 0; i < variableVector->size(); i++){
        if(variableName.compare( variableVector->at(i) )){
            found = true;
            break;
        }
    }
    if(!found){
        variableVector->push_back(variableName);
    }
}

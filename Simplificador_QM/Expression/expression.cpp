#include "expression.h"

Expression::Expression()
{
}

bool Expression::evaluateExpression(map<string, bool> *values)
{
    return evaluateNode(root, values);
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
}

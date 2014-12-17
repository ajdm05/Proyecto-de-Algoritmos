#include "AndNode.h"

AndNode::AndNode(Node* izq, Node* der) {
    this->izq = izq;
    this->der = der;
}

Node* AndNode::getDerNode() {
    return der;
}

Node* AndNode::getIzqNode() {
    return izq;
}

NodeType AndNode::getType(){
    return AndNodeType;
}


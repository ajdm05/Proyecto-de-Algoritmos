#include "OrNode.h"

OrNode::OrNode(Node* izq, Node* der) {
    this->izq = izq;
    this->der = der;
}

Node* OrNode::getDerNode() {
    return der;
}

Node* OrNode::getIzqNode() {
    return izq;
}

NodeType OrNode::getType() {
    return OrNodeType;
}

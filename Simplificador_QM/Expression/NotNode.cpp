#include "NotNode.h"

NotNode::NotNode(Node* node) {
    this->node = node;
}

Node* NotNode::getNode() {
    return node;
}



NodeType NotNode::getType() {
    return NotNodeType;
}

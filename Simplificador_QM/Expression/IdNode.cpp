#include "IdNode.h"

IdNode::IdNode(string id) {
    this->id = id;
}

string IdNode::getId(){
    return id;
}


NodeType IdNode::getType() {
    return IdNodeType;
}


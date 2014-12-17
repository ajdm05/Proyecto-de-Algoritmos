#ifndef NOTNODE_H
#define	NOTNODE_H

#include "Node.h"


class NotNode : public Node {
public:
    NotNode(Node* node);
    Node* getNode();
    virtual NodeType getType();

private:
    Node* node;
};

#endif	/* NOTNODE_H */


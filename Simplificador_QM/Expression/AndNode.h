#ifndef ANDNODE_H
#define	ANDNODE_H

#include "Node.h"


class AndNode : public Node {
public:
    AndNode(Node* izq, Node*der);
    Node* getIzqNode();
    Node* getDerNode();
    virtual NodeType getType();

private:
    Node *izq;
    Node *der;
};

#endif	/* ANDNODE_H */


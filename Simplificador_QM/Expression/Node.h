#ifndef NODE_H
#define	NODE_H

enum NodeType{
    AndNodeType,    
    OrNodeType, 
    NotNodeType,
    IdNodeType,    
};

class Node {
public:
    virtual NodeType getType()=0;
private:

};

#endif	/* NODE_H */


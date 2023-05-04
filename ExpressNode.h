#ifndef SD_TEMA2_EXPRESSNODE_H
#define SD_TEMA2_EXPRESSNODE_H
#include "Node.h"
#include <ostream>
class ExpressNode:public Node{
    Node* down;
public:

    ExpressNode();

    ExpressNode(int valoare, Node *prev, Node *next, Node *down);

    Node *getDown() const;

    void setDown(Node *down);

};


#endif //SD_TEMA2_EXPRESSNODE_H

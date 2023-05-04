
#include "ExpressNode.h"



ExpressNode::ExpressNode() {}

ExpressNode::ExpressNode(int valoare, Node *prev, Node *next, Node *down) : Node(valoare, prev, next), down(down) {}

Node *ExpressNode::getDown() const {
    return down;
}

void ExpressNode::setDown(Node *down) {
    ExpressNode::down = down;
}






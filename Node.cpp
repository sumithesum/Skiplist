

#include "Node.h"

Node::Node(int valoare, Node *prev, Node *next) : valoare(valoare), prev(prev), next(next) {}

Node::Node() {}

int Node::getValoare() const {
    return valoare;
}

void Node::setValoare(int valoare) {
    Node::valoare = valoare;
}

Node *Node::getPrev() const {
    return prev;
}

void Node::setPrev(Node *prev) {
    Node::prev = prev;
}

Node *Node::getNext() const {
    return next;
}

void Node::setNext(Node *next) {
    Node::next = next;
}

Node::~Node() =default;

std::ostream & operator<<(std::ostream &os,Node &n){
    os << n.getValoare() << ' ';
    return os;
}
#ifndef SD_TEMA2_NODE_H
#define SD_TEMA2_NODE_H


#include "ostream"

class Node {
    int valoare;
    Node* prev;
    Node* next;
public:
    Node(int valoare, Node *prev, Node *next);
    Node();

    int getValoare() const;

    void setValoare(int valoare);

    Node *getPrev() const;

    void setPrev(Node *prev);

    Node *getNext() const;

    void setNext(Node *next);

    virtual ~Node();

    friend std::ostream & operator<<(std::ostream &os,Node &n);
};


#endif //SD_TEMA2_NODE_H


#ifndef SD_TEMA2_LINKEDLIST_H
#define SD_TEMA2_LINKEDLIST_H
#include "Node.h"
#include "ostream"
#include "ExpressNode.h"

class LinkedList {
    ExpressNode* fastList;
    Node* list;
    int len;
    int maxim;
public:

    LinkedList();

    virtual ~LinkedList();

    Node *getList() const;

    void setList(Node *list);

    int getLen() const;

    void setLen(int len);

    friend std::ostream & operator<<(std::ostream &os,LinkedList &s);

    void push(int x);
};


#endif //SD_TEMA2_LINKEDLIST_H

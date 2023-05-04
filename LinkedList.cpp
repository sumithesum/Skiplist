
#include "LinkedList.h"



LinkedList::LinkedList() {
len = 0;
maxim =4;
}

LinkedList::~LinkedList() = default;

Node *LinkedList::getList() const {
    return list;
}

void LinkedList::setList(Node *list) {
    LinkedList::list = list;
}

int LinkedList::getLen() const {
    return len;
}

void LinkedList::setLen(int len) {
    LinkedList::len = len;
}

std::ostream & operator<<(std::ostream &os,LinkedList &s){
    for(int i = 0 ; i < s.getLen() ; i++)
        os << s.list[i];
    return os;
}


void LinkedList::push(int x) {
    len++;
    if(len == maxim -1)
        maxim*=2;
    if(len == 1){
        fastList = new ExpressNode[maxim];
        list = new Node[maxim];
        list[0].setValoare(x);
        list[0].setNext(&list[1]);
        list[0].setPrev(nullptr);
        list[1].setNext(nullptr);
        list[1].setPrev(&list[0]);
        fastList[0].setDown(&list[0]);
        fastList[0].setValoare(x);
        fastList[0].setNext(&fastList[1]);
        fastList[0].setPrev(nullptr);
        fastList[1].setDown(&list[1]);
        fastList[1].setNext(nullptr);
        fastList[1].setPrev(&fastList[0]);

    }
}

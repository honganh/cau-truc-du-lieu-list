#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include "Node.h"

class Dlinkedlist
{
    public:
        Dlinkedlist();
        virtual ~Dlinkedlist();
        bool insert(int x ,int y ,int value);
        //this method change follow queue or stack
        //class drive override
        virtual Node* remove()= 0 ;
        bool isempty();
        void print();
    protected:
        //pointer head of list
        Node *head;
        //pointer end list
        Node *tail;
        //size of list
        int size;
};

#endif // DLINKEDLIST_H

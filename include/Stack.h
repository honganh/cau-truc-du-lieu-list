#ifndef STACK_H
#define STACK_H
#include "Dlinkedlist.h"

class Stack:public Dlinkedlist
{
    public:
    Stack();
    virtual ~Stack();
     Node* remove();
};

#endif // STACK_H

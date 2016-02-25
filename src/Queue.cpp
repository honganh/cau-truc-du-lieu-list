#include "../include/Queue.h"

Queue::Queue():Dlinkedlist(){}
Queue::~Queue(){}
Node* Queue::remove()
{
    if( this->isempty() )
    {
        return NULL;
    }
    else
    {
        Node *tmp = new Node();
        tmp = this->tail->getPrev();
        (tmp->getPrev())->setPnext(this->tail);
        this->tail->setPrev(tmp->getPrev());
        this->size--;
        return tmp;
    }
}

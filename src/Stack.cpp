#include "../include/Stack.h"

Stack::Stack():Dlinkedlist(){}
Stack::~Stack(){}
Node* Stack::remove()
{
    if( this->isempty() )
    {
        return NULL;
    }
    else
    {
        Node *tmp = new Node();
        tmp = this->head->getPnext();
        (tmp->get_pnext())->setPrev(this->head);
        this->head->setPnext(tmp->getPnext());
        this->size--;
        return tmp;
    }
}

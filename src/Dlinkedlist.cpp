#include "../include/Dlinkedlist.h"

Dlinkedlist::Dlinkedlist()
{
    this->size = 0;
    this->head = new Node();
    this->tail = new Node();
}

Dlinkedlist::~Dlinkedlist()
{
    delete this->head;
    delete this->tail;
}
bool Dlinkedlist::isempty()
{
    if(this->size == 0)
    {
        return true ;
    }
    else
    {
        return false ;
    }

}
bool Dlinkedlist::insert(int x ,int y ,int value)
{
    Node *tmp = new Node(x,y,value);
    
    if( tmp == NULL )
    {
        printf("\nKhong the tao node");
        return false;
    }
    else
    {
        if( this->isempty() )
        {
            //list empty
            this->head->setPnext(tmp);
            this->tail->setPrev(tmp);
            tmp->setPrev(this->head);
            tmp->setPnext(this->tail);
        }
        else
        {
            //not empty
            tmp->setPnext(this->head->getPnext());
            tmp->getPnext()->setPrev(tmp);
            tmp->setPrev(this->head);
            this->head->set_pnext(tmp);

        }
        this->size++;
        //delete tmp;
        return true;
    }
}
void Dlinkedlist::print()
{
    if( this->isempty() )
    {
        printf("\n Empty .");
    }
    else
    {
        Node *tmp = new Node();
        tmp = this->head->getPnext();
        while( tmp != this->tail && tmp != NULL )
        {
            tmp->print();
            tmp = tmp->getPnext();
        }
        //delete tmp;
    }

}

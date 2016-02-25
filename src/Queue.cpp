#include "../include/Queue.h"

Queue::Queue():Dlinkedlist(){}
Queue::~Queue(){}
Node* Queue::remove(){
    if(this->isempty()){
        return NULL;
    }else{
        Node *tmp = new Node();
        tmp = this->tail->get_prev();
        (tmp->get_prev())->set_pnext(this->tail);
        this->tail->set_prev(tmp->get_prev());
        this->size--;
        return tmp;
    }
}

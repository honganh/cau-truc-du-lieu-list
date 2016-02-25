#include "../include/Stack.h"

Stack::Stack():Dlinkedlist(){}
Stack::~Stack(){}
Node* Stack::remove(){
    if(this->isempty()){
        return NULL;
    }else{
        Node *tmp = new Node();
        tmp = this->head->get_pnext();
        (tmp->get_pnext())->set_prev(this->head);
        this->head->set_pnext(tmp->get_pnext());
        this->size--;
        return tmp;
    }
}

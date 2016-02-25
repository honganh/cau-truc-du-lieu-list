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
bool Dlinkedlist::isempty(){
    if(this->size == 0){
        return true ;

    }else{
        return false ;
    }

}
bool Dlinkedlist::insert(int x ,int y ,int value){
    Node *tmp = new Node(x,y,value);

    if(tmp == NULL){
        printf("\nKhong the tao node");
        return false;
    }else{
        if(this->isempty()){
            //list empty
            this->head->set_pnext(tmp);
            this->tail->set_prev(tmp);
            tmp->set_prev(this->head);
            tmp->set_pnext(this->tail);


        }else{
            //not empty
            tmp->set_pnext(this->head->get_pnext());
            tmp->get_pnext()->set_prev(tmp);
            tmp->set_prev(this->head);
            this->head->set_pnext(tmp);

        }
        this->size++;
        //delete tmp;
        return true;
    }
}
void Dlinkedlist::print()
{
    if(this->isempty()){
        printf("\n Empty .");
    }else{
        Node *tmp = new Node();
        tmp = this->head->get_pnext();
        while(tmp != this->tail && tmp != NULL){
            tmp->print();
            tmp = tmp->get_pnext();
        }
        //delete tmp;
    }

}

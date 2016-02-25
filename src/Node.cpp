#include "../include/Node.h"

Node::Node()
{
    this->X = -1;
    this->Y = -1;
    this->value = -1;
    this->pNext = NULL;
    this->pRev = NULL;
}

Node::~Node()
{
    this->pNext = NULL;
   this->pRev = NULL;
}
Node::Node(int x ,int y,int value){
    this->X = x;
    this->Y = y;
    this->value = value;
    this->pNext = this;
    this->pRev = this;
}
Node* Node::get_pnext(){
    return this->pNext;
}
Node* Node::get_prev(){
    return this->pRev;
}
void Node::set_pnext(Node *pnext){
    this->pNext = pnext;
}
void Node::set_prev(Node *prev){
    this->pRev = prev;
}
void Node::print()
{
    printf("\nX:%d,Y:%d,VALUE:%d",this->X,this->Y,this->value);
}
int Node::get_X(){return this->X ;}
int Node::get_Y(){return this->Y ;}
int Node::get_VALUE(){return this->value ;}
void Node::set_X(int x){this->X = x ;}
void Node::set_Y(int y){this->Y = y ;}
void Node::set_VALUE(int value){this->value = value ;}
void Node::set(int x, int y ,int value){
    this->X = x;this->Y = y ;this->value = value ;
}

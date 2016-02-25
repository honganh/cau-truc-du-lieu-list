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
Node* Node::getPnext(){
    return this->pNext;
}
Node* Node::getPrev(){
    return this->pRev;
}
void Node::setPnext(Node *pnext){
    this->pNext = pnext;
}
void Node::setPrev(Node *prev){
    this->pRev = prev;
}
void Node::print()
{
    printf("\nX:%d,Y:%d,VALUE:%d",this->X,this->Y,this->value);
}
int Node::getX(){return this->X ;}
int Node::getY(){return this->Y ;}
int Node::getValue(){return this->value ;}
void Node::setX(int x){this->X = x ;}
void Node::setY(int y){this->Y = y ;}
void Node::setValue(int value){this->value = value ;}
void Node::set(int x, int y ,int value){
    this->X = x;this->Y = y ;this->value = value ;
}

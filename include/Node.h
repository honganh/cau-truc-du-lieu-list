#ifndef NODE_H
#define NODE_H
#include <stdio.h>

class Node
{
    public:
        Node();
        virtual ~Node();
        Node(int x ,int y,int value);
        Node* getPnext();
        Node *getPrev();
        int getX();
        int getY();
        int getValue();
        void setPnext(Node *pnext);
        void setPrev(Node *prev);
        void setX(int x);
        void setY(int y);
        void setValue(int value);
        void set(int x,int y,int value);
        void print();
    private:
        int X;
        int Y;
        int value;
        Node *pNext;
        Node *pRev;
};

#endif // NODE_H

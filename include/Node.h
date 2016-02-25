#ifndef NODE_H
#define NODE_H
#include <stdio.h>

class Node
{
    public:
        Node();
        virtual ~Node();
        Node(int x ,int y,int value);
        Node* get_pnext();
        Node *get_prev();
        int get_X();
        int get_Y();
        int get_VALUE();
        void set_pnext(Node *pnext);
        void set_prev(Node *prev);
        void set_X(int x);
        void set_Y(int y);
        void set_VALUE(int value);
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

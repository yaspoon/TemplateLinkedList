#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include "GraphData.h"
#include <algorithm>


class LinkedListNode
{
    public:
        LinkedListNode();
        LinkedListNode(GraphData copyEdge);
        virtual ~LinkedListNode();

        GraphData getEdge();
        LinkedListNode *getNext();

        void setNext(LinkedListNode *node);
    protected:
    private:
        LinkedListNode *next;
        GraphData edge;

};

#endif // LINKEDLISTNODE_H

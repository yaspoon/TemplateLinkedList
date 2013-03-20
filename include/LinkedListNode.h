#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include "GraphData.h"
#include <algorithm>

template <class T>
class LinkedListNode
{
    public:
        LinkedListNode()
        {
            next = NULL;
        }

        LinkedListNode(T nodeData)
        {
            next = NULL;
            T *tmp = new T(nodeData);
            data = tmp;
        }

        ~LinkedListNode()
        {

        }

        T getData()
        {
            T tmp(*data);
            return tmp;
        }

        LinkedListNode *getNext()
        {
            return next;
        }

        void setNext(LinkedListNode *node)
        {
            next = node;
        }
    protected:
    private:
        LinkedListNode *next;
        T *data;

};

#endif // LINKEDLISTNODE_H

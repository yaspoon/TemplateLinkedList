#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedListNode.h"




class LinkedList
{
    public:
        LinkedList();
        virtual ~LinkedList();

        void pushEdgeFront(int vertex1, int vertex2, int weight);
        void pushEdgeBack(int vertex1, int vertex2, int weight);
        GraphData popEdgeFront();
        GraphData popEdgeBack();

        bool isEmpty();

        void readList(const char* filepath);


    protected:
    private:
        LinkedListNode *head;
        int count;

        void pushFront(GraphData newEdge);
        void pushBack(GraphData newEdge);
        LinkedListNode* popNodeFront();
        LinkedListNode* popNodeBack();

};

#endif // LINKEDLIST_H

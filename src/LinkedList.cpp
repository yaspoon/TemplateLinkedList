#include "LinkedList.h"

#include <vector>
#include <cstdlib>

template <class T>
void LinkedList<T>::pushFront(T newEdge)
{
    LinkedListNode *newNode = new LinkedListNode(newEdge);

    if(count == 0)  //if the list if empty
    {
        head = newNode;
    }
    else   //Oh man pushing to the head is so much faster
    {
        newNode->setNext(head);
        head = newNode;
    }

    count += 1;
}

template <class T>
void LinkedList<T>::pushBack(T newEdge)
{
    LinkedListNode *newNode = new LinkedListNode(newEdge);

    if(count == 0)  //if the list if empty
    {
        head = newNode;
    }
    else
    {
        LinkedListNode *lastNode = NULL;
        LinkedListNode *currentNode = head;

        while(currentNode != NULL)  //Find the last node;
        {
            lastNode = currentNode;
            currentNode = currentNode->getNext();
        }

        lastNode->setNext(newNode);
    }

    count += 1;
}

template <class T>
T LinkedList<T>::popFront()
{

}

template <class T>
T LinkedList<T>::popBack()
{

}

template <class T>
LinkedListNode *LinkedList<T>::popNodeFront()
{
    LinkedListNode *node = NULL;

    if( count > 0)
    {
        node = head;
        head = head->getNext();
        count -= 1;
    }

    return node;
}

template <class T>
LinkedListNode *LinkedList<T>::popNodeBack()
{

    LinkedListNode *node = NULL;

    if(count == 1)
    {
        node = head;
        count -= 1;
    }
    else if(count > 0)      //if this gets to below zero we are in serious trouble and should probably just abort anyway :/
    {
        LinkedListNode *lastNode = NULL;
        node = head;

        while(node->getNext() != NULL)
        {
            lastNode = node;
            node = node->getNext();
        }

    return node;

}

template <class T>
bool LinkedList<T>::isEmpty()
{
    bool retVal = true;

    if(count > 0)
    {
        retVal = false;
    }

    return retVal;


}
        count -= 1;
        lastNode->setNext(NULL);
    }

    return node;

}


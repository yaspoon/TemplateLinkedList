#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedListNode.h"



template <class T>
class LinkedList
{
    public:

        LinkedList()
        {
            head = NULL;
            count = 0;
        }

        ~LinkedList()
        {
            //int i = 0;
            //LinkedListNode<T>* currentNode = head;

            /*for(i = 0; i < count; i++)
            {
                    LinkedListNode<T>* temp = currentNode;
                    currentNode = currentNode->getNext();

                    delete temp;
            }*/
            delete head;
            count = 0;
        }


        void pushFront(T newData)
        {
            LinkedListNode<T> *newNode = new LinkedListNode<T>(newData);

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


        void pushBack(T newEdge)
        {
            LinkedListNode<T> *newNode = new LinkedListNode<T>(newEdge);

            if(count == 0)  //if the list if empty
            {
                head = newNode;
            }
            else
            {
                LinkedListNode<T> *lastNode = NULL;
                LinkedListNode<T> *currentNode = head;

                while(currentNode != NULL)  //Find the last node;
                {
                    lastNode = currentNode;
                    currentNode = currentNode->getNext();
                }

                lastNode->setNext(newNode);
            }

            count += 1;
        }


        T popFront()
        {
            LinkedListNode<T> *node = popNodeFront();
            T data;
            if(node != NULL)
            {
                data = T(node->getData());
            }

            delete node;

            return data;
        }


        T popBack()
        {
            LinkedListNode<T> *node = popNodeBack();
            T data;
            if(node != NULL)
            {
                data = T(node->getData());
            }


            //delete node;

            return data;
        }

        bool isEmpty()
        {
            bool retVal = true;

            if(count > 0)
            {
                retVal = false;
            }

            return retVal;
        }

        int noElements()
        {
            return count;
        }

    protected:
    private:
        LinkedListNode<T> *head;
        int count;

        LinkedListNode<T> *popNodeFront()
        {
            LinkedListNode<T> *node = NULL;

            if( count > 0)
            {
                node = head;
                head = head->getNext();
                count -= 1;
            }

            return node;
        }


        LinkedListNode<T> *popNodeBack()
        {

            LinkedListNode<T> *node = NULL;

            if(count == 1)
            {
                node = head;
                count -= 1;
            }
            else if(count > 1)      //if this gets to below zero we are in serious trouble and should probably just abort anyway :/
            {
                LinkedListNode<T> *lastNode = NULL;
                node = head;

                while(node->getNext() != NULL)
                {
                    lastNode = node;
                    node = node->getNext();
                }

                lastNode->setNext(NULL);

                count -= 1;

            }

            return node;
        }
};

#endif // LINKEDLIST_H

#include "LinkedList.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <sstream>

LinkedList::LinkedList()
{
    head = NULL;
    count = 0;
}

LinkedList::~LinkedList()
{
    int i = 0;
    LinkedListNode* currentNode = head;

    for(i = 0; i < count; i++)
    {
            LinkedListNode* temp = currentNode;
            currentNode = currentNode->getNext();

            delete temp;
    }
}

void LinkedList::pushEdgeFront(int vertex1, int vertex2, int weight)
{
    GraphData edge;
    edge.setVertex1(vertex1);
    edge.setVertex2(vertex2);
    edge.setWeigth(weight);

    pushFront(edge);
}

void LinkedList::pushEdgeBack(int vertex1, int vertex2, int weight)
{
    GraphData edge;
    edge.setVertex1(vertex1);
    edge.setVertex2(vertex2);
    edge.setWeigth(weight);

    pushBack(edge);
}

GraphData LinkedList::popEdgeFront()
{
    LinkedListNode* currentHead = popNodeFront();

    GraphData retEdge;

    if(currentHead != NULL)
    {
        retEdge.copyEdge(currentHead->getEdge());
    }

    delete currentHead;

    return retEdge;
}

GraphData LinkedList::popEdgeBack()
{
    LinkedListNode *currentTail = popNodeBack();

    GraphData retEdge;

    if(currentTail != NULL) //there was something left in the list
    {
        retEdge.copyEdge(currentTail->getEdge());   //Copy the returned nodes data into out edge to return
    }

    delete currentTail;

    return retEdge;
}

void LinkedList::pushFront(GraphData newEdge)
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

void LinkedList::pushBack(GraphData newEdge)
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

LinkedListNode *LinkedList::popNodeFront()
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

LinkedListNode *LinkedList::popNodeBack()
{

    LinkedListNode *node = NULL;

    if( count > 0)      //if this gets to below zero we are in serious trouble and should probably just abort anyway :/
    {
        LinkedListNode *lastNode = NULL;
        node = head;

        while(node->getNext() != NULL)
        {
            lastNode = node;
            node = node->getNext();
        }
        count -= 1;
        lastNode->setNext(NULL);
    }

    return node;

}

bool LinkedList::isEmpty()
{
    bool retVal = true;

    if(count > 0)
    {
        retVal = false;
    }

    return retVal;


}

void LinkedList::readList(const char* filepath)
{
    std::ifstream listFile;
    listFile.open(filepath, std::ios::in);

    if(listFile.is_open())
    {
        while( !listFile.eof())
        {
            std::string line;
            std::getline(listFile, line); //Get a line of the input file;

            std::stringstream convert(line);

            int vertex1;
            int vertex2;
            int weight;

            convert >> vertex1;

            convert >> vertex2;

            convert >> weight;

            pushEdgeBack(vertex1, vertex2, weight);

        }
        listFile.close();
    }
    else
    {
        std::cout << "Failed to open file\n";
    }
}

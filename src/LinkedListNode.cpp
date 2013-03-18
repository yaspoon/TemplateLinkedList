#include "LinkedListNode.h"

LinkedListNode::LinkedListNode()
{
    next = NULL;
}

LinkedListNode::LinkedListNode(GraphData copyEdge)
{
    edge.copyEdge(copyEdge);
}

LinkedListNode::~LinkedListNode()
{
    //dtor
}

GraphData LinkedListNode::getEdge()
{
    return edge;
}

LinkedListNode *LinkedListNode::getNext()
{
    return next;
}

void LinkedListNode::setNext(LinkedListNode *node)
{
    next = node;
}

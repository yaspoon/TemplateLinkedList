#include "GraphData.h"

GraphData::GraphData()
{
    vertex1 = 0;
    vertex2 = 0;
    weight = 0;
}

GraphData::~GraphData()
{
    //dtor
}

void GraphData::setVertex1(int vertex)
{
    vertex1 = vertex;
}

void GraphData::setVertex2(int vertex)
{
    vertex2 = vertex;
}

void GraphData::setWeigth(int newWeight)
{
    weight = newWeight;
}

int GraphData::getVertex1()
{
    return vertex1;
}

int GraphData::getVertex2()
{
    return vertex2;
}

int GraphData::getWeight()
{
    return weight;
}

void GraphData::copyEdge(GraphData edge)
{
    vertex1 = edge.getVertex1();
    vertex2 = edge.getVertex2();
    weight = edge.getWeight();
}

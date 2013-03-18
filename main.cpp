#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "LinkedList.h"

using namespace std;

void printEdge(GraphData edge)
{
    printf("Edge:%d:%d:%d\n", edge.getVertex1(), edge.getVertex2(), edge.getWeight());
}

int main(void)
{
    cout << "Hello world!" << endl;


    LinkedList myList;

    myList.readList("./tutorial2-graph_info.txt");

    while(!myList.isEmpty())
    {
        GraphData edge = myList.popEdgeFront();
        printEdge(edge);
    }
    return 0;
}

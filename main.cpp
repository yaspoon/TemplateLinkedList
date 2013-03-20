#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <string>
#include <fstream>

#include "LinkedList.h"
#include "GraphData.h"

using namespace std;

void readList(const char* filepath, LinkedList<GraphData> *theList);

void printEdge(GraphData edge)
{
    printf("Edge:%d:%d:%d\n", edge.getVertex1(), edge.getVertex2(), edge.getWeight());
}

int main(void)
{
    cout << "Hello world!" << endl;


    LinkedList<GraphData> myList;

    readList("./tutorial2-graph_info.txt", &myList);

    printf("Number elements:%d\n", myList.noElements());

    while(!myList.isEmpty())
    {
        GraphData edge = myList.popFront();
        printf("%d %d %d\n", edge.getVertex1(), edge.getVertex2(), edge.getWeight());
    }

    return 0;
}

void readList(const char* filepath, LinkedList<GraphData> *theList)
{
    std::ifstream listFile;
    listFile.open(filepath, std::ios::in);

    if(listFile.is_open())
    {
        while( !listFile.eof())
        {
            std::string line;
            std::getline(listFile, line) ;//Get a line of the input file;

            if(!listFile.fail())
            {
                std::stringstream convert(line);

                int vertex1;
                int vertex2;
                int weight;

                convert >> vertex1;

                convert >> vertex2;

                convert >> weight;

                GraphData edge(vertex1, vertex2, weight);

                theList->pushBack(edge);
            }

        }
        listFile.close();
    }
    else
    {
        std::cout << "Failed to open file\n";
    }
}

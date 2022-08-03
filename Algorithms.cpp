// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Algorithm.h"
#include "Graph.h"
int main()
{
#define ARRAY_SIZE  10000
    int Data[ARRAY_SIZE];
    std::cout << "Hello World!\n";
    int arrayToSort[] = {1,2,3,4,5,6};
    uint32_t StartNanos = GetNanos();
    auto bubble = BinarySearch(arrayToSort, 6);
    uint32_t EndNanos = GetNanos();
    std::cout <<"Finding took "<<EndNanos-StartNanos<< " nanaoseconds "<< bubble << std::endl;
    int ArrayToFill[ARRAY_SIZE];
    FillArray(ArrayToFill,ARRAY_SIZE);
  
    Edge edge = Edge("a", "b", 5);

    vector<Edge> edges;
    edges.push_back(edge);
    edges.insert(edges.end(), { Edge("b", "c", 1),
        Edge("a", "d", 7),
        Edge("c", "d", 1) });
    Graph graph = Graph(edges);
    auto test = graph.GetAdjacentList();
    auto testt = test;
    Node startNode = { "a" };
    Node endNode = { "d" };
    graph.AStar(startNode, endNode);
}

int* ChallengeOne(int InputArray[]) {
    uint32_t StartNanos = GetNanos();
    SelectionSort(InputArray,ARRAY_SIZE);
    uint32_t EndNanos = GetNanos();
    std::cout << "Selection Sorting Algorithm on  "<<ARRAY_SIZE << " Data Size took " << EndNanos - StartNanos << " nanaoseconds " << std::endl;
    int* result = InputArray;
    return result;
}
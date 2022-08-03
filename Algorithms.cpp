// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//#include "Algorithm.h"
//#include "Algorithms.h"
#include "Graph.h"
int main()
{
  /*  std::cout << "Hello World!\n";
    int arrayToSort[] = {1,2,3,4,5,6};
    uint32_t StartNanos = GetNanos();
    auto bubble = BinarySearch(arrayToSort, 6);
    uint32_t EndNanos = GetNanos();
    std::cout <<"Finding took "<<EndNanos-StartNanos<< " nanaoseconds "<< bubble << std::endl;
    int ArrayToFill[ARRAY_SIZE];
    FillArray(ArrayToFill);

    int* challengeOne = ChallengeOne(ArrayToFill);*/
  
    Edge edge = Edge("a", "b", 5);

    vector<Edge> edges;
    edges.push_back(edge);
    edges.insert(edges.end(), { Edge("b", "c", 1),
        Edge("a", "d", 7),
        Edge("c", "d", 1) });
    Graph graph = Graph(edges);
    auto test = graph.GetAdjacentList();
    auto testt = test;
    graph.AStar("a", "d");
}

//int* ChallengeOne(int InputArray[]) {
//    uint32_t StartNanos = GetNanos();
//    SelectionSort(InputArray);
//    uint32_t EndNanos = GetNanos();
//    std::cout << "Selection Sorting Algorithm on  "<<ARRAY_SIZE << " Data Size took " << EndNanos - StartNanos << " nanaoseconds " << std::endl;
//    int* result = InputArray;
//    return result;
//}
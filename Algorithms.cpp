// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Algorithm.h"
#include "Graph.h"
#include <vector>
#include <string>
#include <numeric>
using namespace std;
#define ARRAY_SIZE  10000
int ArrayToFill[ARRAY_SIZE];
int main()
{

    std::cout << "Hello World!\n";
    int arrayToSort[] = { 1,2,3,4,5,6 };
    uint32_t StartNanos = GetNanos();
    auto bubble = BinarySearch(arrayToSort, 6);
    uint32_t EndNanos = GetNanos();
    std::cout << "Finding took " << EndNanos - StartNanos << " nanaoseconds " << bubble << std::endl;
    FillArray(ArrayToFill, ARRAY_SIZE);
  
    Edge edge = Edge("a", "b", 5);

    vector<Edge> edges;
    edges.push_back(edge);
    edges.insert(edges.end(), { Edge("b", "c", 1),
        Edge("a", "d", 7),
        Edge("c", "d", 1) });
    Graph graph = Graph(edges);
    auto adjacentList = graph.GetAdjacentList();
    Node startNode = { "a" };
    Node endNode = { "d" };
    graph.AStar(startNode, endNode);
    vector<string> traversePath = graph.GetTraversePath();
    string path = accumulate(begin(traversePath), end(traversePath), string(),
        [](string lhs, const string& rhs) { return lhs.empty() ? rhs : rhs + " => " + lhs; }
    );
    cout << path << endl;
}

int* ChallengeOne(int InputArray[]) {
    uint32_t StartNanos = GetNanos();
    SelectionSort(InputArray,ARRAY_SIZE);
    uint32_t EndNanos = GetNanos();
    std::cout << "Selection Sorting Algorithm on  "<<ARRAY_SIZE << " Data Size took " << EndNanos - StartNanos << " nanaoseconds " << std::endl;
    int* result = InputArray;
    return result;
}
#pragma once
#include <map>
#include <string>
#include "Node.h"
#include "Edge.h"
#include <vector>
#include <iostream>
using namespace std;
class Graph {
public:
	Graph(vector<Edge> edges) {
		for (Edge edge : edges) {
			Node node = { edge.GetDestination(), edge.GetCost() };
			AdjacentList[edge.GetSource()].push_back(node);
		}
	}
	~Graph() {
		cout << "Destructor called " << endl;
	}

	void SetAdjacentList(map<string, vector<Node>> data) {
		AdjacentList = data;
	}
	void SetTraversePath(vector<string> reconstruct) {
		this->traversePath = reconstruct;
	}
	void SetTraverseCost(int costSoFar) {
		this->traversePathCost = costSoFar;
	}
	vector<string> GetTraversePath() {
		return traversePath;
	}
	int GetTraverseCost() {
		return traversePathCost;
	}
	map<string, vector<Node>> GetAdjacentList() {
		return AdjacentList;
	}
	void DepthFirstTraversal(Node startNode, Node goalNode);
	void BreathFirstTraversal(Node startNode, Node goalNode);
	void BreathFirstTraversal(Node startNode);
	void BreathFirstTraversal();
	int Heuristic(Node source, Node destination);
	void AStar(Node startNode, Node goalNode);
	vector<string> ReconstructPath(map<string, Coordinates> cameFrom, string current);
	vector<string> ReconstructPath(priority_queue<pair<string, string>> cameFrom);
	vector<string> ReconstructPath(priority_queue<string> cameFrom);
	/*int TotalCostForTravel(map<string, int> costSoFar);*/
private:
	map<string, vector<Node>> AdjacentList;
	vector<string> traversePath;
	int traversePathCost = 0;
};
#pragma once
#include <map>
#include <string>
#include "Node.h"
#include "Edge.h"
#include <vector>
using namespace std;
class Graph {
public:
	Graph(vector<Edge> edges) {
		for (Edge edge : edges) {
			Node node = { edge.GetDestination(), edge.GetCost() };
			AdjacentList[edge.GetSource()].push_back(node);
		}
	}

	void SetAdjacentList(map<string, vector<Node>> data) {
		AdjacentList = data;
	}
	void SetTraversePath(vector<string> reconstruct) {
		traversePath = reconstruct;
	}
	void SetTraverseCost(int costSoFar) {
		traversePathCost = costSoFar;
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
	string DepthFirstTraversal();
	string BreathFirstTraversal();
	int Heuristic(Node source, Node destination);
	void AStar(Node startNode, Node goalNode);
	vector<string> ReconstructPath(map<string, Coordinates> cameFrom, string current);
	vector<string> ReconstructPath(priority_queue<pair<string, string>> cameFrom, string current);
	/*int TotalCostForTravel(map<string, int> costSoFar);*/
private:
	map<string, vector<Node>> AdjacentList;
	vector<string> traversePath;
	int traversePathCost = 0;
};
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
	vector<string> GetTraversePath() {
		return traversePath;
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
private:
	map<string, vector<Node>> AdjacentList;
	vector<string> traversePath;
};
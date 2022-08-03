#pragma once
#include <map>
#include <string>
#include "Node.h"
#include "Edge.h"
#include <vector>

class Graph {
public:
	Graph(vector<Edge> edges) {
		for (Edge edge : edges) {
			Node node = { edge.GetDestination(), edge.GetCost() };
			AdjacentList[edge.GetSource()].push_back(node);
		}
	}

	void SetAdjacentList(std::map<std::string, std::vector<Node>> data) {
		AdjacentList = data;
	}
	std::string DepthFirstTraversal();
	std::string BreathFirstTraversal();
	int Heuristic(Node source, Node destination);
	void AStar(Node startNode, Node goalNode);
		// The set of discovere)
	std::map<std::string, std::vector<Node>> GetAdjacentList() {
		return AdjacentList;
	}
	vector<std::string> ReconstructPath(map<string, Coordinates> cameFrom, string current);
private:
	std::map<std::string, std::vector<Node>> AdjacentList;
};
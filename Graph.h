#pragma once
#include <map>
#include <string>
#include "Node.h"
#include "Edge.h"
//for (int i = 0; i < edges.size(); ++i) {
//	char *key = edges[i].GetSource();
//	if (*key != 0) {
//		auto  _iterator = AdjacentList.find(key);
//		auto 
//		std::vector<Node> items = _iterator->second;
//		if (!items.empty()) {
//			items.push_back()
//		}
//		items.push_back()
//	}
//
//	/*AdjacentList.insert(key, )*/
//}

class Graph {
public:
	Graph(vector<Edge> edges) {
		for (Edge edge : edges) {
			Node node = { edge.GetDestination(), edge.GetCost() };
			AdjacentList[edge.GetSource()].push_back(node);
		}
	}
	//~ Graph();
	//void AddEdge(Node Source, Node Target, int Cost);
	//void AddNode(Node NodeItem);
	//void AddNode(Node NodeItem, std::vector<Node> Edges);
	//Node GetNode(Node NodeItem);
	//Node GetNodeItem(Node TargetItem);
	void SetAdjacentList(std::map<char*, std::vector<Node>> data) {
		AdjacentList = data;
	}

	std::map<char*, std::vector<Node>> GetAdjacentList() {
		return AdjacentList;
	}
private:
	std::map<char*, std::vector<Node>> AdjacentList;
};
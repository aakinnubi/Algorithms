#include "Graph.h"
#include <queue>

//void AddEdge(Node Source, Node Target, int Cost) {
//	//"A -> B (5)"
//}
//void AddNode(Node NodeItem) {
//	Node vertex = NodeItem;
//}
//
//void AddNode(Node NodeItem, std::vector<Node> Edges) {
//
//}
//Node GetNode(Node NodeItem) {
//
//}
//
//Node GetNodeItem(Node TargetItem) {
//
//}

string Graph::DepthFirstTraversal()
{
	return string();
}

void Graph::AStar(std::string start, std::string goal)
{
	std::map<std::string, std::vector<Node>> graph = GetAdjacentList();
	priority_queue<pair<std::string,int>> frontier = {};
	frontier.push(make_pair(start,0));
	map<std::string, std::string> cameFrom;
	map<std::string, int> costSoFar;
	cameFrom[start];
	costSoFar[start] = 0;
	while (!frontier.empty()) {
		pair<std::string, int> current = frontier.top();
		frontier.pop();
		if (current.first == goal) {
			break;
		}
		vector<Node> neighbours = graph[current.first];
		for (Node next : neighbours) {
			int newCost = costSoFar[current.first] + next.GetCost();
			auto it = costSoFar.find(next.GetName());
			// || newCost < it->second
			if (it == costSoFar.end()) {
				costSoFar[next.GetName()] = newCost;
				//TODO: I need to also pass the current node coordinate hence my data structure has to change
				int priority = newCost + heuristic(next, next);
				frontier.push(make_pair(next.GetName(),  priority));
				cameFrom[next.GetName()] = current.first;
			}
		}
	}
}

int Graph::heuristic(Node source, Node destination)
{
	int xDifference = source.GetCoordinate().x-destination.GetCoordinate().x;
	int yDifference = source.GetCoordinate().y - destination.GetCoordinate().y;
	return abs(xDifference) + abs(yDifference);
}

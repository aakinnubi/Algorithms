#include "Graph.h"
#include <queue>

string Graph::DepthFirstTraversal()
{
	//
	return string();
}

void Graph::AStar(Node startNode, Node goalNode)
{
	std::string start = startNode.GetName();
	std::string goal = goalNode.GetName();
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
			if (it == costSoFar.end() || newCost < it->second) {
				costSoFar[next.GetName()] = newCost;
				//TODO: I need to also pass the current node coordinate hence my data structure has to change
				int priority = newCost + Heuristic(goalNode, next);
				frontier.push(make_pair(next.GetName(),  priority));
				cameFrom[next.GetName()] = current.first;
			}
		}
	}
}

int Graph::Heuristic(Node source, Node destination)
{
	int xDifference = source.GetCoordinate().x-destination.GetCoordinate().x;
	int yDifference = source.GetCoordinate().y - destination.GetCoordinate().y;
	return abs(xDifference) + abs(yDifference);
}
vector<string> ReconstructPath(map<string, Coordinates> cameFrom, string current)
{
	vector<string> totalPath ={};
	std::map<string, Coordinates>::iterator isPresent = cameFrom.find(current);
	while (isPresent != cameFrom.end()) {
		cameFrom.erase(isPresent);
		totalPath.push_back(isPresent->first);
	}
	return totalPath;
}
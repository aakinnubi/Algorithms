#include "Graph.h"
#include <queue>

string Graph::DepthFirstTraversal()
{
	//
	return string();
}

void Graph::AStar(Node startNode, Node goalNode)
{
	string start = startNode.GetName();
	string goal = goalNode.GetName();
	map<string, vector<Node>> graph = GetAdjacentList();
	priority_queue<pair<string,int>> pathTraveled = {};
	pathTraveled.push(make_pair(start,0));
	priority_queue<pair<string, string>> cameFrom = {};
	map<string, int> costSoFar;
	cameFrom.push(make_pair(start,""));
	costSoFar[start] = 0;
	while (!pathTraveled.empty()) {
		pair<string, int> current = pathTraveled.top();
		pathTraveled.pop();
		if (current.first == goal) {
			auto path = this->ReconstructPath(cameFrom, current.first);
			Graph::SetTraversePath(path);
			break;
		}
		vector<Node> neighbours = graph[current.first];
		for (Node next : neighbours) {
			int newCost = costSoFar[current.first] + next.GetCost();
			auto it = costSoFar.find(next.GetName());
			if (it == costSoFar.end() || newCost < it->second) {
				costSoFar[next.GetName()] = newCost;
				int priority = newCost + Heuristic(goalNode, next);
				pathTraveled.push(make_pair(next.GetName(),  priority));
				cameFrom.push(make_pair(next.GetName(), current.first));
				//cameFrom[next.GetName()] = current.first;
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
vector<string> Graph::ReconstructPath(map<string, Coordinates> cameFrom, string current)
{
	vector<string> totalPath ={};
	map<string, Coordinates>::iterator isPresent = cameFrom.find(current);
	while (isPresent != cameFrom.end()) {
		cameFrom.erase(isPresent);
		totalPath.push_back(isPresent->first);
	}
	return totalPath;
}

vector<string> Graph::ReconstructPath(priority_queue<pair<string, string>> cameFrom, string current)
{
	vector<string> totalPath = {};
	while (!cameFrom.empty()) {
		auto item = cameFrom.top();
		string key = item.first;
		totalPath.push_back(key);
		cameFrom.pop();
	}
	return totalPath;
}
#include "Graph.h"
#include <queue>
#include <set>
#include <numeric>
int TotalCostForTravel(map<string, int> costSoFar);
void Graph::DepthFirstTraversal(Node startNode, Node goalNode)
{
	//
	string start = startNode.GetName();
	string goal = goalNode.GetName();
	map<string, vector<Node>> graph = GetAdjacentList();

}
void Graph::BreathFirstTraversal(Node startNode, Node goalNode) {
	string start = startNode.GetName();
	string goal = goalNode.GetName();
	map<string, vector<Node>> graph = GetAdjacentList();
	priority_queue<string> pathTraveled = {};
	pathTraveled.push(start);
	set<string> visited;
	visited.insert(start);
	vector<int> costSoFar = { startNode.GetCost() };
	while (!pathTraveled.empty()) {
		string current = pathTraveled.top();
		pathTraveled.pop();
		if (current == goal) {
			vector<string> traversepaths;
			traversepaths.assign(visited.begin(), visited.end());
			Graph::SetTraversePath(traversepaths);

			int totalCost = accumulate(costSoFar.begin(), costSoFar.end(), 0);
			Graph::SetTraverseCost(totalCost);
			break;
		}
		vector<Node> neighbours = graph[current];
		for (Node next : neighbours) {
			auto currentIterator = visited.find(next.GetName());
			if (currentIterator == visited.end()) {
				pathTraveled.push(next.GetName());
				visited.insert(next.GetName());
				costSoFar.push_back(next.GetCost());

			}
		}
	}
}
void Graph::BreathFirstTraversal(Node startNode) {
	string start = startNode.GetName();
	map<string, vector<Node>> graph = GetAdjacentList();
	priority_queue<string> pathTraveled;
	pathTraveled.push(start);
	set<string> visited;
	visited.insert(start);
	vector<int> costSoFar = { startNode.GetCost() };
	while (!pathTraveled.empty()) {
		string current = pathTraveled.top();
		pathTraveled.pop();
		vector<Node> neighbours = graph[current];
		for (Node next : neighbours) {
			auto currentIterator = visited.find(next.GetName());
			if (currentIterator == visited.end()) {
				pathTraveled.push(next.GetName());
				visited.insert(next.GetName());
				costSoFar.push_back(next.GetCost());
			}
		}
	}
	vector<string> traversepaths;
	traversepaths.assign(visited.begin(), visited.end());
	Graph::SetTraversePath(traversepaths);
	int totalCost = accumulate(costSoFar.begin(), costSoFar.end(), 0);
	Graph::SetTraverseCost(totalCost);
}
void Graph::BreathFirstTraversal() {
	map<string, vector<Node>> graph = GetAdjacentList();
	priority_queue<string> pathTraveled = {};
	set<string> visited;
	//string start = startNode.GetName();
	//string goal = goalNode.GetName();
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
			auto path = this->ReconstructPath(cameFrom);
			Graph::SetTraversePath(path);
			int totalCost = TotalCostForTravel(costSoFar);
			Graph::SetTraverseCost(totalCost);
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

vector<string> Graph::ReconstructPath(priority_queue<pair<string, string>> cameFrom)
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


int TotalCostForTravel(map<string, int> costSoFar) {
	int total = 0;
	for (auto cost : costSoFar) {
		total += cost.second;
	}
	return total;
}

int TotalCostForTravel(vector<int> costSoFar) {
	int total = 0;
	for (auto cost : costSoFar) {
		total += cost;
	}
	return total;
}
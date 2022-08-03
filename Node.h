#pragma once
#include <string>
#include "Algorithm.h"
using namespace std;
struct Coordinates {
	int x;
	int y;
	int cost;
};
class Node {
private:
	string Name;
	Coordinates Coordinate;
	int Cost;
public:
	Node(string name, Coordinates coords, int cost) :Name(name),
		Coordinate (coords),Cost(cost) {

	}
	Node(string name, int cost) :Name(name), Cost(cost) {

	}
	void SetName(string Name);
	void SetCoordinate(Coordinates Coordinate);
	Coordinates GetCoordinate();
	string GetName();
	void SetCost(int cost);
	int GetCost();
	/*bool operator<(const Node& rhs) const noexcept
	{
		return this->Name < rhs.Name;
	}*/
};


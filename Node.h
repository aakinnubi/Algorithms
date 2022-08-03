#pragma once
#include <string>
#include "Algorithm.h"
using namespace std;
struct Coordinates {
	int x; int y;
};
class Node {
private:
	string Name;
	Coordinates Coordinate;
	int Cost;
public:
	Node(string name,  int cost = 0,const Coordinates &coords  = { 0,0 }) :Name(name),
		Coordinate (coords),Cost(cost) {

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


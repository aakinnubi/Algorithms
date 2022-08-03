#pragma once
#include <string>
#include "Algorithm.h"
using namespace std;

class Node {
private:
	char* Name;
	Coordinates Coordinate;
	int Cost;
public:
	Node(char* name, Coordinates coords, int cost) :Name(name), 
		Coordinate (coords),Cost(cost) {

	}
	Node(char* name, int cost) :Name(name), Cost(cost) {

	}
	void SetName(char* Name);
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


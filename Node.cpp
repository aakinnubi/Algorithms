#include "Node.h"

void Node::SetName(string Name)
{
	this->Name = Name;
}

void Node::SetCoordinate(Coordinates Coordinate)
{
	this->Coordinate = Coordinate;
}

Coordinates Node::GetCoordinate()
{
	return this->Coordinate;
}

std::string Node::GetName()
{
	return this->Name;
}

void Node::SetCost(int cost)
{
	this->Cost = cost;
}

int Node::GetCost()
{
	return this->Cost;
}


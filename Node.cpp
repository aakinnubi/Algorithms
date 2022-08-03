#include "Node.h"

void Node::SetName(char* Name)
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

string Node::GetName()
{
	return Node::Name;
}

void Node::SetCost(int cost)
{
	this->Cost = cost;
}

int Node::GetCost()
{
	return this->Cost;
}


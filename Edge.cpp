#include "Edge.h"

void Edge::SetSource(std::string src)
{
	this->Source = src;
}

void Edge::SetDestination(std::string dest)
{
	this->Destination = dest;
}

void Edge::SetCost(int cost)
{
	this->Cost = cost;
}

int Edge::GetCost()
{
	return this->Cost;
}

std::string Edge::GetSource()
{
	return this->Source;
}

std::string Edge::GetDestination()
{
	return this->Destination;
}

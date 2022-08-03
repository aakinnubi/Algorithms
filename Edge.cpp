#include "Edge.h"

void Edge::SetSource(char *src)
{
	this->Source = src;
}

void Edge::SetDestination(char *dest)
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

char* Edge::GetSource()
{
	return this->Source;
}

char* Edge::GetDestination()
{
	return this->Destination;
}

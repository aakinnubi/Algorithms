#pragma once
#include <string>
class Edge {
   
public:
    Edge(std::string src, std::string dest, int cost) : Source(src), Destination(dest), Cost(cost) {
        this->Source = src;
        this->Destination = dest;
        this->Cost = cost;
    }
    void SetSource(std::string src);
    void SetDestination(std::string dest);
    void SetCost(int cost);
    int GetCost();
    std::string GetSource();
    std::string GetDestination();
private:
    std::string Source;
    std::string Destination;
    int Cost;
};
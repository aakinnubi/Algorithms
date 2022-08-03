#pragma once
class Edge {
    Edge(char *src, char *dest, int cost) : Source(src), Destination(dest), Cost(cost) {

    }
public:
    void SetSource(char *src);
    void SetDestination(char *dest);
    void SetCost(int cost);
    int GetCost();
    char* GetSource();
    char* GetDestination();
private:
    char *Source;
    char *Destination;
    int Cost;
};
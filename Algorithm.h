#pragma once
#include <array>
#include <chrono>
#include <vector>
#include <map>
#include <queue>
#include <math.h>
using namespace std;
using namespace std::chrono;
int* BubbleSort(int ArrayToSort[], int SizeOfArray);
void SelectionSort(int ArrayToSort[]);


const int n = 60; // horizontal size of the map
const int m = 60; // vertical size size of the map
static int _map[n][m];
static int closed_nodes_map[n][m]; // map of closed (tried-out) nodes
static int open_nodes_map[n][m]; // map of open (not-yet-tried) nodes
static int dir_map[n][m]; // map of directions
const int dir = 8; // number of possible directions to go at any position
static int dx[dir] = { 1, 1, 0, -1, -1, -1, 0, 1 };
static int dy[dir] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct Coordinates {
	string x;
	string y;
	int cost;
};

class NCoordinate
{
    // current position
    int xPos;
    int yPos;
    // total distance already travelled to reach the node
    int level;
    // priority=level+remaining distance estimate
    int priority;  // smaller: higher priority

public:
    NCoordinate(int xp, int yp, int d, int p)
    {
        xPos = xp; yPos = yp; level = d; priority = p;
    }
    bool operator<(const NCoordinate& rhs) const noexcept
    {
        return this->xPos < rhs.xPos;
    }
    int getxPos() const { return xPos; }
    int getyPos() const { return yPos; }
    int getLevel() const { return level; }
    int getPriority() const { return priority; }

    void updatePriority(const int& xDest, const int& yDest)
    {
        priority = level + estimate(xDest, yDest) * 10; //A*
    }

    // give better priority to going strait instead of diagonally
    void nextLevel(const int& i) // i: direction
    {
        level += (dir == 8 ? (i % 2 == 0 ? 10 : 14) : 10);
    }

    // Estimation function for the remaining distance to the goal.
    const int& estimate(const int& xDest, const int& yDest) const
    {
        static int xd, yd, d;
        xd = xDest - xPos;
        yd = yDest - yPos;
        d = static_cast<int>(sqrt(xd * xd + yd * yd));

        return(d);
    }
};


auto AStar(Coordinates start, Coordinates goal,map<string,Coordinates > data);
auto ReconstructPath(map<string, Coordinates> cameFrom, string current);


#define ARRAY_SIZE  10000
int Data[ARRAY_SIZE];

void FillArray(int ArrayToFile[]);


uint32_t GetNanos() {
	return static_cast<uint32_t>(
		duration_cast<nanoseconds>
		(
			system_clock::now()
			.time_since_epoch()
			).count()
		);
}

int BinarySearch(int ArrayToSearch[], int SearchItem);


 int* BubbleSort(int ArrayToSort[], int SizeOfArray)
{
	for (int pass = 0; pass < SizeOfArray; ++pass) {
		for (int i = 0; i < SizeOfArray - 1; ++i) {
			if (ArrayToSort[i] > ArrayToSort[i + 1]) {
				int temp = ArrayToSort[i];

				ArrayToSort[i] = ArrayToSort[i + 1];

				ArrayToSort[i + 1] = temp;
			}
		}
	}
	return ArrayToSort;
}


 //1. Implement a sorting algorithm using the chrono library profile, sometimes using varying sample sizes


 inline void SelectionSort(int ArrayToSort[])
 {
	 for (int index = 0; index < ARRAY_SIZE; ++index) {
		 int lowerNumberIndex = index;
		 for (int index2 = index + 1; index2 < ARRAY_SIZE; ++index2) {
			 if (ArrayToSort[index2] < ArrayToSort[lowerNumberIndex]) {
				 lowerNumberIndex = index2;
			 }
		 }
		 if (lowerNumberIndex != index) {
			 int temporary = ArrayToSort[index];
			 ArrayToSort[index] = ArrayToSort[lowerNumberIndex];
			 ArrayToSort[lowerNumberIndex] = temporary;
		}
	 
	 }
 }



 inline auto AStar(Coordinates start, Coordinates goal,map<string, Coordinates> data)
 {
	 vector<vector<Coordinates>> openList;
	 vector<vector<Coordinates>> closedList;
     vector<Coordinates> startVector;
     startVector.push_back(start);
	 openList.push_back(startVector);
     map<string, Coordinates>  openSet;
	 while (openSet.size() > 0)
	 {
         vector<Coordinates> current = openList[0];
		 int currentIndex = 0;
		 for (int index = 0; index < openList.size(); ++index) {
			 if (openList[index][index].cost < current[index].cost) {
				 current = openList[index];
				 currentIndex = index;
			 }
		 }
         auto it = openSet.begin();
         std::advance(it, currentIndex);
         openSet.erase(it);
         for (Coordinates neighbor : current)
         {
         //tentative_gScore: = gScore[current] + d(current, neighbor)
         //    if tentative_gScore < gScore[neighbor]
         //        // This path to neighbor is better than any previous one. Record it!
         //        cameFrom[neighbor] : = current
         //        gScore[neighbor] : = tentative_gScore
         //        fScore[neighbor] : = tentative_gScore + h(neighbor)
         //        if neighbor not in openSet
         //            openSet.add(neighbor);
         }
	 }

 }



 inline auto ReconstructPath(map<string, Coordinates> cameFrom, string current)
 {
	 int totalPath = 0;
	 std::map<string,Coordinates>::iterator isPresent = cameFrom.find(current);
	 while (isPresent != cameFrom.end()) {
		 cameFrom.erase(isPresent);
		 totalPath = totalPath + 1;
	 }
	 return totalPath;
 }



 string pathFind(const int& xStart, const int& yStart,
     const int& xFinish, const int& yFinish)
 {
     static priority_queue<NCoordinate> pq[2]; // list of open (not-yet-tried) nodes
     static int pqi; // pq index
     static NCoordinate* n0;
     static NCoordinate* m0;
     static int i, j, x, y, xdx, ydy;
     static char c;
     pqi = 0;

 

     for (y = 0; y < m; y++)
     {
         for (x = 0; x < n; x++)
         {
             closed_nodes_map[x][y] = 0;
             open_nodes_map[x][y] = 0;
         }
     }

     // create the start node and push into list of open nodes
     n0 = new NCoordinate(xStart, yStart, 0, 0);
     n0->updatePriority(xFinish, yFinish);
     pq[pqi].push(*n0);
     open_nodes_map[x][y] = n0->getPriority(); // mark it on the open nodes map

     // A* search
     while (!pq[pqi].empty())
     {
         // get the current node w/ the highest priority
         // from the list of open nodes
         n0 = new NCoordinate(pq[pqi].top().getxPos(), pq[pqi].top().getyPos(),
             pq[pqi].top().getLevel(), pq[pqi].top().getPriority());

         x = n0->getxPos(); y = n0->getyPos();

         pq[pqi].pop(); // remove the node from the open list
         open_nodes_map[x][y] = 0;
         // mark it on the closed nodes map
         closed_nodes_map[x][y] = 1;

         // quit searching when the goal state is reached
         //if((*n0).estimate(xFinish, yFinish) == 0)
         if (x == xFinish && y == yFinish)
         {
             // generate the path from finish to start
             // by following the directions
             string path = "";
             while (!(x == xStart && y == yStart))
             {
                 j = dir_map[x][y];
                 c = '0' + (j + dir / 2) % dir;
                 path = c + path;
                 x += dx[j];
                 y += dy[j];
             }

        
             delete n0;
    

             while (!pq[pqi].empty()) pq[pqi].pop();
             return path;
         }

        
         for (i = 0; i < dir; i++)
         {
             xdx = x + dx[i]; ydy = y + dy[i];

             if (!(xdx<0 || xdx>n - 1 || ydy<0 || ydy>m - 1 || _map[xdx][ydy] == 1
                 || closed_nodes_map[xdx][ydy] == 1))
             {
                 // generate a child node
                 m0 = new NCoordinate(xdx, ydy, n0->getLevel(),
                     n0->getPriority());
                 m0->nextLevel(i);
                 m0->updatePriority(xFinish, yFinish);


                 if (open_nodes_map[xdx][ydy] == 0)
                 {
                     open_nodes_map[xdx][ydy] = m0->getPriority();
                     pq[pqi].push(*m0);
           

                     dir_map[xdx][ydy] = (i + dir / 2) % dir;
                 }
                 else if (open_nodes_map[xdx][ydy] > m0->getPriority())
                 {
                
                     open_nodes_map[xdx][ydy] = m0->getPriority();
        

                     dir_map[xdx][ydy] = (i + dir / 2) % dir;

                   
                     while (!(pq[pqi].top().getxPos() == xdx &&
                         pq[pqi].top().getyPos() == ydy))
                     {
                         pq[1 - pqi].push(pq[pqi].top());
                         pq[pqi].pop();
                     }
                     pq[pqi].pop(); 

                 
                     if (pq[pqi].size() > pq[1 - pqi].size()) pqi = 1 - pqi;
                     while (!pq[pqi].empty())
                     {
                         pq[1 - pqi].push(pq[pqi].top());
                         pq[pqi].pop();
                     }
                     pqi = 1 - pqi;
                     pq[pqi].push(*m0); 
                 }
                 else delete m0; 
             }
         }
         delete n0; 
     }
     return ""; 
 }


 void FillArray(int ArrayToFill[])
 {
	 for (int i = 0; i < ARRAY_SIZE; ++i) {
		 ArrayToFill[i] = rand() % ARRAY_SIZE + 1;
	 }
 }



 int LinearSearch(int ArrayToSearch[], int searchItem) {
	 int Size = sizeof(ArrayToSearch);
	 for (int index = 0; index < Size; ++index) {
		 int current = ArrayToSearch[index];
		 if (current == searchItem) {
			 return index;
		 }
	 }
	 return -1;
 }
 int BinarySearch(int ArrayToSearch[], int SearchItem)
{
	int Low = 0;
	int d = sizeof(ArrayToSearch)-1;
	int High = d ;

	while (Low <= High) {
		int Middle = (Low + High) / 2;
		int current = ArrayToSearch[Middle];
		if (SearchItem == current) {
			return Middle;
		}
		else if (SearchItem < current) {
			High = Middle - 1;
		}
		else {
			Low = Middle + 1;
		}
	}

	return -1;
}

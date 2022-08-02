#pragma once
#include <array>
#include <chrono>
#include <vector>
#include <map>
using namespace std;
using namespace std::chrono;
int* BubbleSort(int ArrayToSort[], int SizeOfArray);
void SelectionSort(int ArrayToSort[]);
struct Coordinates {
	string x;
	string y;
	int cost;
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
	 vector<Coordinates> openList;
	 vector<Coordinates> closedList;
	 openList.push_back(start);
	 while (openList.size() > 0)
	 {
		 Coordinates current = openList[0];
		 int currentIndex = 0;
		 for (int index = 0; index < openList.size(); ++index) {
			 if (openList[index].cost < current.cost) {
				 current = openList[index];
				 currentIndex = index;
			 }
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

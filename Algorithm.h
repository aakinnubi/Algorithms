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
void SelectionSort(int ArrayToSort[], int SizeOfArray);
int BinarySearch(int ArrayToSearch[], int SearchItem);
void FillArray(int ArrayToFile[], int SizeOfArray);
int* ChallengeOne(int InputArray[]);
uint32_t GetNanos();




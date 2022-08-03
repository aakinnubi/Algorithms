#include <stdlib.h>
#include "Algorithm.h"

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


void SelectionSort(int ArrayToSort[],int SizeofArray)
{
	int size = SizeofArray;
	for (int index = 0; index < SizeofArray; ++index) {
		int lowerNumberIndex = index;
		for (int index2 = index + 1; index2 < SizeofArray; ++index2) {
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




void FillArray(int ArrayToFill[],int SizeOfArray)
{

	for (int i = 0; i < SizeOfArray; ++i) {
		ArrayToFill[i] = rand() % SizeOfArray + 1;
	}
}

uint32_t GetNanos()
{
		return static_cast<uint32_t>(
			duration_cast<nanoseconds>
			(
				system_clock::now()
				.time_since_epoch()
				).count()
			);
	
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
	int d = sizeof(ArrayToSearch) - 1;
	int High = d;

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

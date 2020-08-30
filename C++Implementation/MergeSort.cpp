#include <iostream>
using namespace std;

int* mergesort(int[], int);

int main() {

	int myArray[] = {24, 67, 50, 8, 29, 116, 125, 48, 110, 82, 145, 6, 63, 59, 80, 26, 105, 33, 15, 129 };
	int arraySize = size(myArray);
	int* sortedArray; // Create a pointer which will hold first address of sortedArray
	sortedArray = mergesort(myArray, arraySize); // mergesort will return pointer representing first element of sorted array
	return 0;
}

int* mergesort(int myArray[], int arraySize) {

	// Base condition. If the array has a single element, then the recursive function will return the single element in array
	if (arraySize < 2) {
		return myArray;
	}
	else {
		int middle = arraySize / 2; // The middle value will tell us where to split the array from.

		
	}


	return 
}
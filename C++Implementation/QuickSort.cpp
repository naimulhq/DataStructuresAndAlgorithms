// Quick Sort Algorithm
// The Time Complexity is O(n^2) in the worst case scenario and Space Complexity is O(1)
// However, the Time Complexity for the average case is O(n log n)
// If implemented properly and pivots are chosen properly, we can make the Time Complexity O(n log n)
// This is extremely power not only for its Time Complexity but Space Complexity is O(1) unlike Merge Sort

#include <iostream>
using namespace std;

void QuickSort(int[], int, int);
int partition(int[], int, int);

int main() {

	int myArray[] = { 24, 67, 50, 8, 29, 116, 125, 48, 110, 82, 145, 6, 63, 59, 80, 26, 105, 33, 15, 129 };
	int arraySize = size(myArray);
	QuickSort(myArray, 0 , arraySize - 1);
	cout << endl;
	for (int i = 0; i < arraySize; i++) {
		cout << myArray[i] << " ";
	}
	return 0;
}
// QuickSort is a recursive function which sorts an array. This is done by partitioning array to different parts and recursively sorting each part seperatly
void QuickSort(int myArray[], int start, int end) {
	if (start < end) {
		int pIndex = partition(myArray, start, end); // This will return the partition index which will be used to recursively work on different portions of the array
		QuickSort(myArray, start, pIndex - 1); // Recursive call QuickSort which will create partition with new start and end if valid
		QuickSort(myArray, pIndex + 1, end); // Recursive call QuickSort which will create partition with new start and end if valid
	}
}

// This function partitions an array about a pivot index. Everything left to pivot is less than pivot value and everything greater than pivot is to the right
int partition(int myArray[], int start, int end) {

	int pivot = myArray[end]; // For my implementation, the last value will be the pivot value.
	int pIndex = start;  // Holds the partition index. Will be necessary to determine where the partition will occur

	// Iterate through array
	for (int i = start; i < end; i++) {
		// If value <= pivot, perform swap. Swap will bring larger value closer and closer to right
		if (myArray[i] <= pivot) {
			int temp = myArray[i];
			myArray[i] = myArray[pIndex];
			myArray[pIndex] = temp;
			pIndex++;
		}
	}
	// Once complete, must put the pivot value in the correct position
	int temp = myArray[end];
	myArray[end] = myArray[pIndex];
	myArray[pIndex] = temp;
	return pIndex; // This index will determine future partitions through the recursive call.
}
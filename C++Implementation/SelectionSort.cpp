// Selection Sort Algorithm
// Time Complexity is O(n^2) Space Complexity is O(1)
// Easy to implement. Slower than Insertion Sort but faster than Bubble Sort

#include <iostream>
using namespace std;

void selectionSort(int[], int);

int main() {

	int myArray[] = { 24, 67, 50, 8, 29, 116, 125, 48, 110, 82, 145, 6, 63, 59, 80, 26, 105, 33, 15, 129 };
	int arraySize = size(myArray);

	selectionSort(myArray, arraySize);

	cout << endl;
	for (int i = 0; i < arraySize; i++) {
		cout << myArray[i] << " ";
	}
	return 0;
}

void selectionSort(int myArray[], int size) {
	// Iterate through the array. We stop one element before the last because the last element will be sorted
	for (int i = 0; i < size - 1; i++) {
		int minIndex = i; // Set minIndex as i
		for (int j = i + 1; j < size; j++) { // Iterate through array starting after i + 1
			// If there exists a smaller value, save index of smaller value
			if (myArray[j] < myArray[minIndex]) {
				minIndex = j;
			}
		};
		// Swap the smallest value in the array with item in the first element.
		int temp = myArray[minIndex];
		myArray[minIndex] = myArray[i];
		myArray[i] = temp;
	}
}
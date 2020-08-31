#include <iostream>
using namespace std;

void insertionSort(int[], int);

int main() {

	int myArray[] = { 24, 67, 50, 8, 29, 116, 125, 48, 110, 82, 145, 6, 63, 59, 80, 26, 105, 33, 15, 129 };
	int arraySize = size(myArray);
	insertionSort(myArray, arraySize);
	cout << endl;
	for (int i = 0; i < arraySize; i++) {
		cout << myArray[i] << " ";
	}

	return 0;
}

void insertionSort(int myArray[], int size) {
	// Iterate through entire array. We assume first element is sorted and start at i = 1
	for (int i = 1; i < size; i++) {
		int currentValue = myArray[i]; // Get value from array
		int j = i - 1; // j is an index which decrements to see where currentValue should be inserted
		// While j >= 0 and the value to left is greater than currentValue, shift value to right
		while ((j >= 0) && (myArray[j] > currentValue)) {
			myArray[j + 1] = myArray[j]; // Shifting value on left to right and then decrement
			j--;
		}
		// Once while loop exits, j + 1 gives us position of where value should be inputted.
		myArray[j + 1] = currentValue;
	}
}
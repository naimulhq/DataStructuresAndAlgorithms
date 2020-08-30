// Binary Search Algorithm in C++. We will be using Merge Sort to sort array prior to performing binary search. 
// Time Complexity is O(log n) and Space Complexity is O(1)
// This algorithm is a fundamental search algorithm every programmer should know.

#include <iostream>
using namespace std;

// Function Declarations
int* mergesort(int[], int);
int* merge(int*, int*, int, int);
int binarySearch(int*, int, int);

int main() {

	int myArray[] = { 24, 67, 50, 8, 29, 116, 125, 48, 110, 82, 145, 6, 63, 59, 80, 26, 105, 33, 15, 129 };
	int arraySize = size(myArray);
	int* sortedArray; // Create a pointer which will hold first address of sortedArray
	sortedArray = mergesort(myArray, arraySize); // mergesort will return pointer representing first element of sorted array
	for (int i = 0; i < arraySize; i++) {
		cout << sortedArray[i] << " ";
	}
	
	// Call binary search algorithm. Returns index if found. If not found, index of -1 is returned.
	int index = binarySearch(sortedArray, 105, arraySize);
	if (index == -1)
		cout << "\nNot Found";
	else
		cout << "\nFound at index " << index;

	return 0;
}

// mergesort takes two arguments: the array i.e. address of first element in array and arraySize
int* mergesort(int myArray[], int arraySize) {

	// Base condition. If the array has a single element, then the recursive function will return the single element in array
	if (arraySize < 2) {
		return myArray;
	}
	else {
		int middle = arraySize / 2; // The middle value will tell us where to split the array from.
		// Determine the size of each sublist
		int leftSize = middle;
		int rightSize = arraySize - middle;
		// Use the sizes to construct the sublists of specified lengths
		int* left, * right;
		left = new int[leftSize];
		right = new int[rightSize];
		// Use a for loop to create the different splits
		for (int i = 0; i < leftSize; i++) {
			left[i] = myArray[i];
		}
		for (int i = 0; i < rightSize; i++) {
			right[i] = myArray[i + middle];
		}
		// Utilize recursion and call mergesort using the split arrays.
		int* newLeft, * newRight, * newList;
		newLeft = mergesort(left, leftSize);
		newRight = mergesort(right, rightSize);
		// Call merge which will merge the two arrays to one large array
		newList = merge(newLeft, newRight, leftSize, rightSize);
		return newList;
	}
}

// Merge takes the address of the first element in the left and right subarray. It also takes their respective sizes.
int* merge(int* left, int* right, int leftSize, int rightSize) {
	int* mergedList;
	mergedList = new int[leftSize + rightSize]; // Create a merged list which is the size of the sum of left Array Size and right Array Size

	int i = 0, j = 0, k = 0;
	// While the indexes are less than their respective array lengths, add new values to merged list.
	while ((i < leftSize) && (j < rightSize)) {
		// We will add the smallest value between two values from the left subarray and right subarray
		if (left[i] <= right[j]) {
			mergedList[k] = left[i];
			i++;
			k++;
		}
		else {
			mergedList[k] = right[j];
			j++;
			k++;
		}
	}
	// The last two while loops are designed to deal with any values that have been left over
	while (i < leftSize) {
		mergedList[k] = left[i];
		i++;
		k++;
	}
	while (j < rightSize) {
		mergedList[k] = right[j];
		j++;
		k++;
	}
	return mergedList;
}

int binarySearch(int* mySortedArray, int value, int size) {
	bool found = false; // if found, will set to true, else remains false
	// first and last are necessary to calculate middle. index will be used to return location where item is found or -1
	int first = 0, last = size, index = -1;
	while ((found == false) && (first <= last)) {
		int middle = (first + last) / 2; // Calculate middle
		if (middle > size - 1) { // Case where middle is greater than length of array
			break;
		}
		if (mySortedArray[middle] == value) { // If exact value is found, set index to middle and found to true
			found = true;
			index = middle;
		}
		else if (value < mySortedArray[middle]) // If value < mySortedArray[middle], everything to the right does not matter
			last = middle - 1;
		else
			first = middle + 1; // If value > mySortedArray[middle], everything to the left does not matter
	}

	return index;
}
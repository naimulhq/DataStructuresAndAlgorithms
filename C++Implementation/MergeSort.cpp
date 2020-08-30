#include <iostream>
using namespace std;

// Function Declarations
int* mergesort(int[], int);
int* merge(int*, int*, int, int);

int main() {

	int myArray[] = {24, 67, 50, 8, 29, 116, 125, 48, 110, 82, 145, 6, 63, 59, 80, 26, 105, 33, 15, 129 };
	int arraySize = size(myArray);
	int* sortedArray; // Create a pointer which will hold first address of sortedArray
	sortedArray = mergesort(myArray, arraySize); // mergesort will return pointer representing first element of sorted array
	for (int i = 0; i < arraySize; i++) {
		cout << sortedArray[i] << " ";
	}
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
		int *left, *right;
		left = new int[leftSize];
		right = new int[rightSize];
		// Use a for loop to create the different splits
		for (int i = 0; i < leftSize; i++) {
			left[i] = myArray[i];
		}
		for (int i = 0; i < rightSize; i++) {
			right[i] = myArray[i+middle];
		}
		// Utilize recursion and call mergesort using the split arrays.
		int *newLeft, *newRight, *newList;
		newLeft = mergesort(left, leftSize);
		newRight = mergesort(right, rightSize);
		// Call merge which will merge the two arrays to one large array
		newList = merge(newLeft, newRight, leftSize, rightSize);
		return newList;
	}
}

// Merge takes the address of the first element in the left and right subarray. It also takes their respective sizes.
int* merge(int* left, int* right, int leftSize, int rightSize) {
	int *mergedList;
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
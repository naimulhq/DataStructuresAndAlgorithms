#include <iostream>
using namespace std;


int main() {

	int myArray[21] = { 41, 58, 97, 53, 98, 29, 23, 19, 10, 85, 3, 90, 81, 16, 47, 78, 37, 59, 60, 43 };
	bool sorted = false; // Determines if array has been sorted, currently set to false
	// As long as array is not sorted, sort the array
	while (!sorted) {
		sorted = true; // Set sorted to true. If no change is required, will remain at true. Otherwise, it will be set to false
		// Iterate through array. We subtract by 1 to prevent index out of bounds error
		for (int i = 0; i < size(myArray) - 1; i++) {
			// If the current value is greater than next value, swap value. This is for least->greatest implementation. Flip inequality for greatest->least implementation
			if (myArray[i] > myArray[i + 1]) {
				int temp = myArray[i];
				myArray[i] = myArray[i + 1];
				myArray[i + 1] = temp;
				sorted = false;
			}
		}
	}

	for (int i = 0; i < size(myArray); i++) {
		cout << myArray[i] << endl;
	}
	return 0;
}
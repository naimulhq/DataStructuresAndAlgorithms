# Insertion Sort Algorithm
# Time Complexity is O(n^2) and Space Complexity is O(1)
# Although the complexity is the same as Bubble Sort, the Insertion works two times faster and has performs less amounts of swaps than Bubble Sort

def main():
     myList = [24, 67, 50, 8, 29, 116, 125, 48, 110, 82, 145, 6, 63, 59, 80, 26, 105, 33, 15, 129]
     mySortedList = insertionSort(myList)
     print("Sorted List")
     print(mySortedList)

# This function will implement insertion sort algorithm and return list containing sorted elements.
def insertionSort(myList):
    # This for loop will iterate through value in each list
    # We start from 1 and end at length of myList - 1
    for i in range(1, len(myList)):
        value = myList[i] # This value is the number we will be inserting at specific position to sort
        j = i - 1 # This index will be used to iterate through the sorted portions of the list
        # As long as j >= 0 and if value to the left > value, then we will be shifting value in the left to the right
        while(j >= 0 and value < myList[j]):
            myList[j + 1] = myList[j] # Value gets shifted from left to right
            j -= 1 # Decrement by 1 to view next left element

        myList[j+1] = value # if it happens to be the next left element does not satisfy while loop, this means j+1 is correct position for value
    return myList

main()
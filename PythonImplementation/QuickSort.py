# Quick Sort Algorithm in Python
# Worst Case Time Complexity is O(n^2) and Space Complexity is O(1)
# If pivots are chosen properly, average case occurs more often which is O(n log n) making this a powerful sorting algorithm

def main():
    myList = [24, 67, 50, 8, 29, 116, 125, 48, 110, 82, 145, 6, 63, 59, 80, 26, 105, 33, 15, 129]
    QuickSort(myList, 0, len(myList) - 1)
    print(myList)

def QuickSort(myList, start, end):
    if(start < end): # If start < end, we will call partition function. This will sort the list about a pivot value. Then, it will return a partition index indicating where partition takes place
        pIndex = partition(myList,start,end)
        QuickSort(myList,start,pIndex - 1) # Recursive call Quicksort to repeat partition process on left portion of List
        QuickSort(myList,pIndex + 1, end) # Recursive call Quicksort to repeart partition process on right portion of List

def partition(myList,start,end):
    pivotValue = myList[end] # For my implementation, I will choose the pivotValue to be last value in list
    pIndex = 0
    # Iterate through list
    for i in range(end):
        # If you find a value less than or equal to pivot value, perform swap so value will end up on left side of pivot
        if(myList[i] <= pivotValue):
            temp = myList[i]
            myList[i] = myList[pIndex]
            myList[pIndex] = temp
            pIndex += 1 # Increment pIndex by 1 so when this condition occurs again, we will know what values to swap
    # Put pivot in correct position after completion of loop
    temp = myList[pIndex]
    myList[pIndex] = myList[end]
    myList[end] = temp
    return pIndex

main()
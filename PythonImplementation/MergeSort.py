# This program will demonstrate Merge Sort which is best utilized when sorting Linked Lists
# Unlike other sorting algorithms, Merge Sort has a Time Complexity of O(n log n)
# However, due to the way in which Merge Sort works, it also has Space Complexity of O(n)

def main():
    myList = [24, 67, 50, 8, 29, 116, 125, 48, 110, 82, 145, 6, 63, 59, 80, 26, 105, 33, 15, 129]
    # We will call a function called mergesort which takes unsorted list as argument. This function will return sorted list in O(n log n) time
    mySortedList = mergesort(myList)
    print(mySortedList)

# In order to perform mergesort, the mergesort function utilizes a concept called recursion. Recursion is when a function calls itself and is useful for situations such as this.
def mergesort(a_list):
    # In recursive functions, there is a base condition which determines when function should exit recursion
    # In our case, when the len of the list is less than 2, return the list
    if len(a_list) < 2:
        return a_list
    else:
        middle = int(len(a_list) / 2) # The middle represents a point where we split the list into two sublists
        left = a_list[:middle] # Create the left sublist by splitting on middle index
        right = a_list[middle:] # Create the right sublist by splitting on midde index
        newLeft = mergesort(left) # Recursive call sending left sublist
        newRight = mergesort(right) # Recursive call sending right sublist
        newList = merge(newLeft,newRight) # Merge will merge the two sorted sublists
        return newList

def merge(list_a, list_b):
    # These variables will represent the indexes used to merge the two sublists to one whole list
    i = 0
    j = 0
    mergedList = []
    # As long as the length of the list has not been met, we will compare each value and decide which value to put before
    while i < len(list_a) and j < len(list_b):
        if list_a[i] <= list_b[j]: # If this condition is met, list_a[i] will be put into mergedList and index will be incremented.
            mergedList.append(list_a[i])
            i += 1
        else:
            mergedList.append(list_b[j]) # If condition was not met, list_b[i] will be put into mergedList and index will be incremented
            j += 1
    # This next portion will handle any thing that was left over in list_a or list_b
    # Since the previous while loop exited due to one of the conditions failing, only one of the while loops on the bottom will run.
    while i < len(list_a):
        mergedList.append(list_a[i])
        i += 1
    while j < len(list_b):
        mergedList.append(list_b[j])
        j += 1
    return mergedList

main()
# Binary Search Algorithm is one of the most important and fundamental search algorithms every programmer should know.
# In order to perform binary search, it is crucial that the list is sorted first.
# We will be using our merge sort algorithm to sort our list.
# Then, we will perform binary search.
# Time Complexity is O(log n). Space Complexity is O(1)

def main():
    myList = [83, 50, 14, 39, 59, 127, 75, 43, 34, 125, 27, 18, 23, 4, 28, 60, 36, 61, 123, 95, 37, 103, 19, 116, 99]
    mySortedList = mergesort(myList)
    # Now that we have obtained our sorted list, we can call the binary search function to perform search. 
    # If found, index will be returned. Else, -1 will be returned.
    print(mySortedList)
    index = binarySearch(mySortedList, 23)
    if index == -1:
        print("Not Found")
    else:
        print("Found at index " + str(index))


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


def binarySearch(mySortedList, value):
    found = False # If found, will become true
    index = -1 # If never found, index returned will be -1
    # First and Last are necessary to calculate middle point
    first = 0 
    last = len(mySortedList)
    # If the value has not been found and first <= last, check to see if value is in list
    while not found and first <= last:
        middle = int((first + last)/2) # We will use the middle value to find the value
        # It is possible for middle to end up being greater than the length - 1. If thats the case, the value was not found
        if(middle > len(mySortedList) - 1):
            break
        if mySortedList[middle] == value: # If middle index is where value is located, set found to True and set index to middle
            found = True
            index = middle
        elif mySortedList[middle] < value: # If value in middle index is less than value, everything to left of middle does not matter
            first = middle + 1
        else:
            last = middle - 1 # If value in middle index is greater than value, everything to right of middle does not matter.
    return index


main()

# This program will demonstrate a basic sorting algorithm called Bubble Sort.
# Bubble Sort is extremely easy to implement and should be used by very beginners. 
# However, Bubble Sort is not used in practice due to its runtime
# The Time Complexity for Bubble Sort is : O(n^2)
# The Space Complexity for Bubble Sort is : O(1)

def main():
    myList = [4, 6, 5, 2, 9, 3, 1, 9, 25, 13, 17, 15] # Values can be changed if desired

    sorted = False # sorted represents whether the list has been sorted or not.
    while not sorted: # While the list has not been sorted
        sorted = True # We set sort to True. If the list needs to be sorted, it will be set to False
        # Iterate through entire list. Since we are comparing with value ahead, to prevent accessing out of bounds error, we subtract our len by 1
        for i in range(len(myList) - 1):
            # If the current value is greater than the next value, a swap needs to take place. If we want to sort from greatest to least, flip the inequality
            if(myList[i] > myList[i + 1]):
                # Perform a basic swap
                temp = myList[i]
                myList[i] = myList[i+1]
                myList[i+1] = temp
                sorted = False # Since we had to enter this conditional, it means our list was not sorted completely yet.
    
    print(myList) # Print list to see result. 
# Call main
main()

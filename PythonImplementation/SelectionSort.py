

def main():
     myList = [24, 67, 50, 8, 29, 116, 125, 48, 110, 82, 145, 6, 63, 59, 80, 26, 105, 33, 15, 129]
     mySortedList = selectionSort(myList)
     print(mySortedList)

def selectionSort(myList):
    for i in range(0,len(myList)-1):
        smallestIndex = i
        for j in range(i+1,len(myList)):
            if(myList[j] < myList[smallestIndex]):
                smallestIndex = j
        temp = myList[i]
        myList[i] = myList[smallestIndex]
        myList[smallestIndex] = temp
    return myList

main()
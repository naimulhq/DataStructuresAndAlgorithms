# This program will demonstrate a Linked List Implementation in Python
# In addition, we will develop member functions that go over basic insertion, deletion, access, search of elements within linked list
# This implementation will be a singly linked list.

# Create a node class. This will hold the value and point to next Node in linked list
class Node:
    def __init__(self,val):
        self.value = val
        self.next = None

class LinkedList:
    def __init__(self):
        self.root = None

    # Insert node, Insert in the beginning for O(1) insertion
    def addNode(self,val):
        newNode = Node(val)
        newNode.next = self.root
        self.root = newNode

    # Print Linked List. Runs in O(n) time where O(n) is length of list
    def printList(self):
        current = self.root
        print("My Linked List")
        while current is not None:
            print(str(current.value) + " ",end = ' ')
            current = current.next
        print('\n')

    # Search for value in Linked List. Takes O(n) time
    def search(self,val):
        current = self.root
        found = False
        while current is not None:
            if(current.value == val):
                print(str(val) + " was found.")
                found = True
                break
            else:
                current = current.next
        if not found:
            print(str(val) +  " was not found.")
    # Deletion is O(1) if we delete first element in Linked List
    def deletion(self):
        current = self.root
        self.root = current.next
        current = None

    # Deletion is O(n) because we need to iterate through linked list till value is found
    # Must consider beginning case, middle case, and end case
    def deleteSpecific(self,val):
        current = self.root
        deleted = False
        while current is not None:
            if current.value == val:
                pass
            else:
                current = current.next
        if(deleted == False):
            print(str(val) + " is not in linked list.")


    


# Main Program
myLinkedList = LinkedList()
myList = [5,4,3,8,9]
for i in range(len(myList)):
    myLinkedList.addNode(myList[i])
# Print List
myLinkedList.printList()
# Delete First Element
myLinkedList.deletion()
# Print List again
myLinkedList.printList()
# Look for values
myLinkedList.search(9)
myLinkedList.search(5)
# Delete specific values
myLinkedList.deleteSpecific(11)
# Print Linked List
myLinkedList.printList()

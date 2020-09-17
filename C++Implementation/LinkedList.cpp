// Linked List Implementation C++
// Node Class represents a node in a Linked List
#include <iostream>
using namespace std;

class Node {
public:
	int value;
	Node* next;
};

class LinkedList {

private:
	Node* root; // Root Node i.e beginning of Linked List

public:
	LinkedList() {
		root = NULL;
	}

	// O(1) insertion. Insert in beginning of Linked List
	void insertNode(int value) {
		if (root == NULL) {
			root = new Node();
			root->value = value;
			root->next = NULL;
		}
		else {
			Node* curr = new Node();
			curr->value = value;
			curr->next = root;
			root = curr;
		}
	}

	// O(n) search. Iterate through list to find value
	bool search(int value) {
		Node* curr = root;
		while (curr != NULL) {
			if (curr->value == value) {
				return true;
			}
			curr = curr->next;
		}
		return false;
	}

	// O(1) Deletion i.e Deletes first node
	void deletion() {
		Node* curr = root;
		curr = curr->next;
		root = curr;
	}


	// O(n) Deletion i.e Delete Specific Node
	void deleteSpecific(int value) {
		Node* curr = root;
		bool deleted = false;
		// Case where value is first node
		if (curr->value == value) {
			curr = curr->next;
			root = curr;
			return;
		}

		while (curr != NULL && deleted == false) {
			// deal with case where last node is deleted
			if ((curr->next->next == NULL) && (curr->next->value == value)) {
				curr->next = NULL;
				deleted = true;
			}
			// deal with normal case
			else if (curr->next->value == value) {
				curr->next = curr->next->next;
				deleted = true;
			}
			else {
				curr = curr->next;
			}
		}
	}

	// Basic Print Function Iterates through list. O(n) time complexity
	void printList() {
		Node* curr = root;
		cout << "Printed List\n";
		while (curr != NULL) {
			cout << curr->value << " ";
			curr = curr->next;
		}
	}
};

int main() {
	LinkedList myLinkedList;
	myLinkedList.insertNode(5);
	myLinkedList.insertNode(10);
	myLinkedList.insertNode(7);
	myLinkedList.insertNode(13);
	myLinkedList.insertNode(20);
	myLinkedList.insertNode(8);
	bool result = myLinkedList.search(10);
	result ? cout << "Found\n" : cout << "Not Found\n";
	myLinkedList.printList();
	cout << endl;
	myLinkedList.deleteSpecific(5);
	cout << endl;
	myLinkedList.printList();
	cout << endl;
	myLinkedList.deleteSpecific(8);
	cout << endl;
	myLinkedList.printList();
	cout << endl;
	myLinkedList.deleteSpecific(13);
	cout << endl;
	myLinkedList.printList();
	return 0;
}
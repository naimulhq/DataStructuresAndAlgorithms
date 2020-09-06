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
	myLinkedList.printList();
	return 0;
}
// C++ program to implement
// a multilevel linked list

#include <bits/stdc++.h>
using namespace std;

// Representation of node
class Node {
public:
	int data;
	Node* next;
	Node* child;
};

// A function to create a linked list
// with n(size) nodes returns head pointer
Node* createList(int* arr, int n)
{
	Node* head = NULL;
	Node* tmp;

	// Traversing the passed array
	for (int i = 0; i < n; i++) {
		// Creating a node if the list
		// is empty
		if (head == NULL) {
			tmp = head = new Node();
		}
		else {
			tmp->next = new Node();
			tmp = tmp->next;
		}
		// Created a node with data and
		// setting child and next pointer
		// as NULL.
		tmp->data = arr[i];
		tmp->next = tmp->child = NULL;
	}
	return head;
}

// To print the linked list
void printMultiLevelList(Node* head)
{
	// While head is not null
	while (head) {
		if (head->child) {
			printMultiLevelList(head->child);
		}
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver code
int main()
{
	// Initializing the data in arrays(row wise)
	int arr1[3] = { 1, 2, 3 };
	int arr2[2] = { 5, 6 };
	int arr3[1] = { 4 };
	int arr4[3] = { 7, 8, 9 };

	// creating Four linked lists
	// Passing array and size of array
	// as parameters
	Node* head1 = createList(arr1, 3);
	Node* head2 = createList(arr2, 2);
	Node* head3 = createList(arr3, 1);
	Node* head4 = createList(arr4, 3);

	// Initializing children and next pointers
	// as shown in given diagram
	head1->child = head2;
	head1->next->next->child = head3;
	head2->next->child = head4;

	// Creating a null pointer.
	Node* head = NULL;
	head = head1;

	// Function Call to print
	printMultiLevelList(head);

	return 0;
}

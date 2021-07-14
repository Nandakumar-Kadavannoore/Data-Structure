// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Doubly linked list node
struct Node {
	int data;
	struct Node *next, *prev;
};

// Function to insert a new node at
// the beginning of doubly linked
// list
void insert(struct Node** head, int data)
{
	// Allocate node
	struct Node* temp = new Node();

	// Fill the data value in it
	temp->data = data;
	temp->next = temp->prev = NULL;

	// If head is NULL change
	// head to temp
	if ((*head) == NULL) {
		(*head) = temp;
	}

	// Insert the node before head
	else {
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

// Function to find sum of triplet
// closest to X
void closestTripletSum(struct Node* head, int X)
{
	// Points to the first node
	// of the triplet
	struct Node* first = head;

	// Points to the second node
	// of the triplet
	struct Node* second = head->next;

	// Stores the last node of
	// doubly linked list
	struct Node* tail = head;

	// Traverse till end of the list
	while (tail->next != NULL) {
		tail = tail->next;
	}

	// Stores the sum closest to X
	int diff = INT_MAX;

	// Points to the third node
	// of the triplet
	struct Node* third = tail;

	// Iterate till the end of the list
	while (first != NULL) {
		second = first->next;
		third = tail;

		while (second != NULL && third != NULL
			&& third != second) {
			int sum = (first->data + second->data
					+ third->data);

			// Check if the current sum
			// is closest to X
			if (abs(X - sum) < abs(X - diff)) {

				// Update the value of diff
				diff = sum;
			}

			// Check if sum is less than X
			if (sum < X) {

				// Increment the second
				// pointer
				second = second->next;
			}
			else {

				// Decrement the third
				// pointer
				third = third->prev;
			}
		}

		// Move the first pointer
		// ahead
		first = first->next;
	}

	// Print the closest sum
	cout << diff;
}

// Driver Code
int main()
{
	// Given Input
	struct Node* head = NULL;
	insert(&head, 4);
	insert(&head, 3);
	insert(&head, 2);
	insert(&head, 1);
	int X = 3;

	// Function Call
	closestTripletSum(head, X);

	return 0;
}

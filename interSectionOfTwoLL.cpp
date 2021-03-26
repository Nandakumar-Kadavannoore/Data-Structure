// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Structure of a node
// of a Linked List
class Node {
public:
	int data;
	Node* next;

	// Constructor
	Node(int x)
	{
		data = x;
		next = NULL;
	}
};

// Function to find the intersection
// point of the two Linked Lists
Node* intersectingNode(Node* headA,
					Node* headB)
{

	// Traverse the first linked list
	// and multiply all values by -1
	Node* a = headA;

	while (a) {

		// Update a -> data
		a->data *= -1;

		// Update a
		a = a->next;
	}

	// Traverse the second Linked List
	// and find the value of the first
	// node having negative value
	Node* b = headB;

	while (b) {

		// Intersection point
		if (b->data < 0)
			break;

		// Update b
		b = b->next;
	}

	return b;
}

// Function to create linked lists
void formLinkList(Node*& head1,
				Node*& head2)
{
	// Linked List L1
	head1 = new Node(3);
	head1->next = new Node(6);
	head1->next->next = new Node(9);
	head1->next->next->next = new Node(15);
	head1->next->next->next->next = new Node(30);

	// Linked List L2
	head2 = new Node(10);
	head2->next = head1->next->next->next;

	return;
}

// Driver Code
int main()
{
	Node* head1;
	Node* head2;
	formLinkList(head1, head2);

	cout << abs(intersectingNode(head1,
								head2)
					->data);

	return 0;
}

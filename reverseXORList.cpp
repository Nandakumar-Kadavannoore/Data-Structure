// C program for the above approach 

#include <inttypes.h> 
#include <stdio.h> 
#include <stdlib.h> 

// Structure of a node 
// of XOR Linked List 
struct Node { 

	// Stores data value 
	// of a node 
	int data; 

	// Stores XOR of previous 
	// pointer and next pointer 
	struct Node* nxp; 
}; 

// Function to calculate 
// Bitwise XOR of the two nodes 
struct Node* XOR(struct Node* a, 
				struct Node* b) 
{ 
	return (struct Node*)((uintptr_t)(a) 
						^ (uintptr_t)(b)); 
} 

// Function to insert a node with 
// given value at given position 
struct Node* insert(struct Node** head, 
					int value) 
{ 
	// If XOR linked list is empty 
	if (*head == NULL) { 

		// Initialize a new Node 
		struct Node* node 
			= (struct Node*)malloc( 
				sizeof(struct Node)); 

		// Stores data value in the node 
		node->data = value; 

		// Stores XOR of previous 
		// and next pointer 
		node->nxp = XOR(NULL, NULL); 

		// Update pointer of head node 
		*head = node; 
	} 

	// If the XOR linked 
	// list is not empty 
	else { 

		// Stores the address 
		// of the current node 
		struct Node* curr = *head; 

		// Stores the address 
		// of the previous node 
		struct Node* prev = NULL; 

		// Initialize a new Node 
		struct Node* node 
			= (struct Node*)malloc( 
				sizeof(struct Node)); 

		// Update address of current node 
		curr->nxp = XOR(node, 
						XOR( 
							NULL, curr->nxp)); 

		// Update address of the new node 
		node->nxp = XOR(NULL, curr); 

		// Update the head node 
		*head = node; 

		// Update the data 
		// value of current node 
		node->data = value; 
	} 
	return *head; 
} 

// Function to print elements 
// of the XOR Linked List 
void printList(struct Node** head) 
{ 
	// Stores XOR pointer 
	// in the current node 
	struct Node* curr = *head; 

	// Stores XOR pointer 
	// in the previous Node 
	struct Node* prev = NULL; 

	// Stores XOR pointer in the 
	// next node 
	struct Node* next; 

	// Traverse XOR linked list 
	while (curr != NULL) { 

		// Print the current node 
		printf("%d ", curr->data); 

		// Forward traversal 
		next = XOR(prev, curr->nxp); 

		// Update the prev pointer 
		prev = curr; 

		// Update the curr pointer 
		curr = next; 
	} 
} 

// Function to reverse the linked 
// list in the groups of K 
struct Node* reverseK(struct Node** head, 
					int K, int len) 
{ 
	struct Node* curr = *head; 

	// If head is NULL 
	if (curr == NULL) 
		return NULL; 

	// If the size of XOR linked 
	// list is less than K 
	else if (len < K) 
		return *head; 
	else { 

		int count = 0; 

		// Stores the XOR pointer 
		// in the previous Node 
		struct Node* prev = NULL; 

		// Stores the XOR pointer 
		// in the next node 
		struct Node* next; 

		while (count < K) { 

			// Forward traversal 
			next = XOR(prev, curr->nxp); 

			// Update the prev pointer 
			prev = curr; 

			// Update the curr pointer 
			curr = next; 

			// Count the number of 
			// nodes processed 
			count++; 
		} 

		// Remove the prev node 
		// from the next node 
		prev->nxp = XOR(NULL, 
						XOR(prev->nxp, 
							curr)); 

		// Add the head pointer with prev 
		(*head)->nxp = XOR(XOR(NULL, 
							(*head)->nxp), 
						curr); 

		// Add the prev with the head 
		if (curr != NULL) 
			curr->nxp = XOR(XOR(curr->nxp, 
								prev), 
							*head); 
		return prev; 
	} 
} 

// Function to reverse last K nodes 
// of the given XOR Linked List 
void reverseLL(struct Node* head, 
			int N, int K) 
{ 

	// Reverse the given XOR LL 
	head = reverseK(&head, N, N); 

	// Reverse the first K nodes of 
	// the XOR LL 
	head = reverseK(&head, K, N); 

	// Reverse the given XOR LL 
	head = reverseK(&head, N, N); 

	// Print the final linked list 
	printList(&head); 
} 

// Driver Code 
int main() 
{ 
	// Stores number of nodes 
	int N = 6; 

	// Given XOR Linked List 

	struct Node* head = NULL; 
	insert(&head, 1); 
	insert(&head, 3); 
	insert(&head, 11); 
	insert(&head, 8); 
	insert(&head, 6); 
	insert(&head, 7); 

	int K = 3; 

	reverseLL(head, N, K); 

	return (0); 
} 

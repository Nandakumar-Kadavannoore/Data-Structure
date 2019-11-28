// C++ implementation of the approach 
#include <iostream> 
using namespace std; 
  
// Structure for the node 
// of the linked list 
struct node { 
    char data; 
    node* next; 
}; 
  
// Utility function to add a new 
// node to the linked list 
node* add(char data) 
{ 
    node* newnode = new node; 
  
    // Assign the data to the data part 
    // and assign NULL to the address part 
    newnode->data = data; 
    newnode->next = NULL; 
    return newnode; 
} 
  
// Function to print the linked list 
void print(node* head) 
{ 
    while (head != NULL) { 
        cout << head->data << " -> "; 
        head = head->next; 
    } 
    cout << "NULL"; 
} 
  
// Function that returns true if 
// ch is a special character 
bool isSpecialChar(char ch) 
{ 
  
    // If lower-case character 
    if (ch >= 'a' && ch <= 'z') 
        return false; 
  
    // If upper-case character 
    if (ch >= 'A' && ch <= 'Z') 
        return false; 
  
    // If digit 
    if (ch >= '0' && ch <= '9') 
        return false; 
  
    // ch is a special character 
    return true; 
} 
  
// Function to remove the special 
// characters from the linked list 
node* removeFromLL(node* head) 
{ 
  
    // Declare two variables curr and 
    // prev both pointing to head 
    node *curr = head, *prev = head; 
  
    // The following loop removes special 
    // characters from the head of the linked list 
    // In case the special character is present at 
    // the head of the linked list, make head point 
    // to the next valid character 
    while (curr != NULL && isSpecialChar(curr->data)) { 
        node* temp = curr; 
        head = curr->next; 
        curr = curr->next; 
        delete temp; 
    } 
  
    // Make prev point to head 
    prev = head; 
  
    // Repeat the process for 
    // the entire Linked list 
    while (curr != NULL) { 
  
        // Repeat the process for all the elements 
        // of linked list, in case a special character 
        // is encountered then make the previous valid 
        // character point to the next valid character 
        // and remove the current node from the linked list 
        while (curr != NULL && isSpecialChar(curr->data)) { 
            node* temp = curr; 
            prev->next = curr->next; 
            curr = curr->next; 
            delete temp; 
        } 
  
        // If the end is reached 
        if (curr == NULL) 
            break; 
        prev = curr; 
        curr = curr->next; 
    } 
    return head; 
} 
  
// Driver code 
int main() 
{ 
  
    // Create the linked list 
    node* head = NULL; 
    head = add('('); 
    head->next = add('G'); 
    head->next->next = add('E'); 
    head->next->next->next = add('E'); 
    head->next->next->next->next = add('*'); 
    head->next->next->next->next->next = add('K'); 
    head->next->next->next->next->next->next = add('S'); 
    head->next->next->next->next->next->next->next = add('*'); 
  
    // Remove the special characters 
    // from the linked list 
    head = removeFromLL(head); 
  
    // Print the updated list 
    print(head); 
  
    return 0; 
} 

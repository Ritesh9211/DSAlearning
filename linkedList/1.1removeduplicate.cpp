/* C++ Program to remove duplicates in an unsorted
linked list */
#include <bits/stdc++.h>
using namespace std;

/* A linked list node */
class Node {
    public:
	int data;
	 Node* next;
	 /*
	 Node(int d){
		data=d;
		next=NULL;
	 }
	 */
};

// Utility function to create a new Node
 Node* newNode(int data)
{
	Node* temp = new Node;
	// Node* temp = new Node(data); we have to make a default constructor

	temp->data = data;
	temp->next = NULL;
	return temp;
}

void removeDuplicates(Node* start)
{
    // Hash to store seen values
    unordered_set<int> st;
 
    /* Pick elements one by one */
    Node* curr = start;
    Node* prev = NULL;
    while (curr != NULL) {
        // If current value is seen before
        if (st.find(curr->data) != st.end()) {
            prev->next = curr->next;
            delete (curr);
        }
        else {
            st.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

/* Function to print nodes in a given linked list */
void printList( Node* node)
{
	while (node != NULL) {
		printf("%d-> ", node->data);
		node = node->next;
	}
    printf("Null");
}

// Driver code
int main()
{
	/* The constructed linked list is:
	10->12->11->11->12->11->10*/
	Node* start = newNode(10);
	start->next = newNode(12);
	start->next->next = newNode(11);
	start->next->next->next = newNode(11);
	start->next->next->next->next = newNode(12);
	start->next->next->next->next->next = newNode(11);
	start->next->next->next->next->next->next = newNode(10);

	printf("Linked list before removing duplicates ");
	printList(start);

	removeDuplicates(start);

	printf("\nLinked list after removing duplicates ");
	printList(start);
	return 0;
}

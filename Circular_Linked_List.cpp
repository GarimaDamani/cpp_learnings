/**
    This circular linked list program performs the following :
        1. Print all the elements
        2. Check if list is empty
        3. Insert node at head of the list
**/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
	int data;
	struct node *next;
};

// Check if linkedlist is empty
bool isEmpty(node *head) {
	return head == NULL;
}

// Insert node at the head of the linkedlist
node* insertBeforeFirst(node *head, int data) {
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = temp;

	if (head != NULL) {
		temp->next = head;
		node *curr = head;
		do {
			curr = curr->next;
		} while (curr->next != head);
		curr->next = temp;
	}
	head = temp;
	return head;
}

// Print elements of LinkedList
void printList(node *head) {
	if (isEmpty(head) == true)
		cout << "\nprintList: List is empty";
	else {
		node *ptr = head;
		cout << "\nLinkList: H -> ";
		if (ptr != NULL) {
			do {
				cout << ptr->data << " ";
				ptr = ptr->next;
			} while (ptr != head);
		}
	}
}

int main(int argc, char** argv) {
	node *head = NULL;
	for (int i = 10 ; i <= 100; i+=10)
		head = insertBeforeFirst(head, i);
	printList(head);
	cout << endl;
	return 0;
}

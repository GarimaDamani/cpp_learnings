/**
    This linked list program performs the following :
        1. Print all the elements - DONE
        2. Check if list is empty - DONE
        3. Insert node at the head - DONE
        4. Insert node at the tail - DONE
        5. Insert node at given position - DONE
        6. Delete node at the head - DONE
        7. Delete node at the tail - DONE
        8. Delete node at given position - DONE
        9. Check if list contains a cycle - DONE
        10. Search in list for given data - DONE
        11. Print elements in reverse order - DONE
        12. Reverse the list - DONE
        13. Get node data counting from backward - DONE
        14. Compare two linked list - DONE
**/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
	int data;
	struct node *next;
};

bool isEmpty(node *head);

// Print elements of LinkedList
void printList(node *head) {
	if (isEmpty(head) == true)
		cout << "\nprintList: List is empty";
	else {
		node *ptr = head;
		cout << "\nLinkList: H -> ";
		while (ptr != NULL) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout << "-> null";
	}
}

// Insert node at the head of the linkedlist
node* insertFirst(node *head, int data) {
	struct node *link = (struct node *) malloc(sizeof(struct node));
	link->data = data;
	link->next = head;
	head = link;
	return head;
}

// Insert node at the tail of the linkedlist
node* insertLast(node *head, int data) {
	struct node *link = (struct node *) malloc(sizeof(struct node));
	link->data = data;
	link->next = NULL;

	if (head == NULL) {
		head = link;
		printList(head);
		return head;
	}
	node *current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = link;
	return head;
}

// Insert node in linkedlist with given position
node* insertAtPosition(node *head, int position, int data) {
	node *temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
	}
	else if (position == 0) {
		temp->next = head;
		head = temp;
	}
	else {
		node *current = head;
		node *previous = NULL;

		int count = 0;
		while (current != NULL && count != position) {
			previous = current;
			current = current->next;
			count++;
		}
		if (count == position) {
			temp->next = current;
			previous->next = temp;
		}
	}
	return head;
}

// Delete node from the head of linkedlist
node* deleteFirst(node *head) {
	if (isEmpty(head) == true)
		cout << "\ndeleteFirst: List is empty";
	else {
		node *current = head;
		if (current->next != NULL) {
			cout << "\nDeleted data: " << current->data;
			current = current->next;
			head = current;
		}
		else {
			cout << "\nDeleted data: " << current->data;
			head = current = NULL;
		}
	}
	return head;
}

// Delete node from the tail of linkedlist
node* deleteLast(node *head) {
	if (isEmpty(head) == true)
		cout << "\ndeleteLast: List is empty";
	else {
		node *current = head;
		node *previous = NULL;
		if (current->next == NULL) {
			cout << "\nDeleted data: " << current->data;
			head = NULL;
			return head;
		}
		while (current->next != NULL) {
			previous = current;
			current = current->next;
		}
		cout << "\nDeleted data: " << current->data;
		previous->next = NULL;
	}
	return head;
}

// Delete node from linkedlist with given position
node* deleteNode(node *head, int position) {
	cout << "\nDelete Node at Pos: " << position;
	node *current = head;
	node *previous = NULL;
	if (isEmpty(head) == true) {
		cout << "\nDeleteNode: List is empty";
		return head;
	}

	int count = 1;
	while (count != position) {
		if (current->next == NULL) {
			if (count == position)
				head = current = NULL;
			else
				cout << " not found.";
			return head;
		}
		else {
			previous = current;
			current = current->next;
			count++;
		}
	}
	if (current == head) {
		head = head->next;
	}
	else {
		previous->next = current->next;
	}
	return head;
}

// Search for node with given data
void searchData(node *head, int data) {
	if (isEmpty(head) == true)
		cout << "\nsearchData: List is empty";
	else {
		node *current = head;
		while (current->data != data) {
			if (current->next == NULL) {
				cout << "\nData: " << data << " not found.";
				break;
			}
			else
				current = current->next;
		}
		if (current->data == data)
			cout << "\nData: " << current->data << " found.";
	}
}

// Print the linkedlist data in reverse order using recursion
void printReverse(node *head) {
	if (head == NULL)
		return;
	printReverse(head->next);
	cout << head->data << " ";
}

// Reverse the order of linkedlist
/**
1st Itr
Current and head points to start of list; make next point to 2nd element;
make current's link point to nothing; make prev point to current;
make current point to same as next (2nd element);
2nd Itr
Make next point to 3rd elem; make 2nd elemenet point to prev element 1st;
make prev point to 2nd element; make current point to same as next (3rd);
after last Itr
head points to prev;
**/
node* reverseList(node *head) {
	node *current = head;
	node *prev = NULL;
	node *next;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

// Detect cycle in linkedlist
bool isCycle(node *head) {
	if (head == NULL)
		return false;
	node *fast = head->next;
	node *slow = head;
	while (fast != NULL && slow != NULL && fast->next != NULL) {
		if (fast == slow)
			return true;
		fast = fast->next->next;
		slow = slow->next;
	}
	return false;
}

// Get the length of linkedlist
int getLength(node *head) {
	int count = 0;
	if (isEmpty(head) != true) {
		for (node *current = head; current != NULL; current = current->next)
			count++;
	}
	return count;
}

// get the node at the given position counting backwards from the tail
node* getNode(node *head, int positionFromTail, node *nodePosition) {
	int count = 0;
	node *current = head;
	while (current->next != NULL) {
		count++;
		current = current->next;
	}
	current = head;
	for (int i = count - positionFromTail; i > 0; i--) {
		current = current->next;
	}
	nodePosition = current;
	return nodePosition;
}

// Check if linkedlist is empty
bool isEmpty(node *head) {
	return head == NULL;
}

//Compare two lists. return 0 if they DON'T match else 1.
//Lists are equal if they equal no.of nodes and same data.
int compareList(node *headA, node *headB) {
	int status = -1;
	if (headA == NULL && headB == NULL)
		status = 1;
	else if (headA == NULL && headB != NULL)
		status = 0;
	else if (headA != NULL && headB == NULL)
		status = 0;
	else if (headA != NULL && headB != NULL) {
		node *curr1 = headA; int c1 = 0;
		node *curr2 = headB; int c2 = 0;
		while (curr1 != NULL && curr2 != NULL) {
			if (curr1->data != curr2->data) {
				status = 0;
				return status;
			}
			curr1 = curr1->next; c1++;
			curr2 = curr2->next; c2++;
		}
		if (curr1 == NULL && curr2 == NULL && c1 == c2)
			status = 1;
		else
			status = 0;
	}
	return status;
}

int main(int argc, char** argv) {
	node *head1 = NULL;
	//Functions are called as per requirement/operation.
	return 0;
}

#include<iomanip>
#include "IntList.h"
using namespace std;

IntList::IntList(){
	head = NULL;
	tail = NULL;
}
void IntList::appendNode(int n) {
	ListNode* nNode = new ListNode;
	nNode->value = n;
	nNode->next = NULL;

	if (head == NULL) { // Add to list if list is empty
		head = nNode; 
		return;
	} else if (tail == NULL) {
		findTail(head);
	}
	tail->next = nNode;
	tail = nNode;
}
void IntList::insertNode(int n) {
	ListNode* nNode = new ListNode;

	nNode->value = n;
	nNode->next = NULL;
	if (head == NULL) { // Add to list if list is empty
		head = nNode; 
	}
	else {
		nodePlacement(nNode);
	}
		
}
void IntList::deleteNode(int n) {
	ListNode* currentNode = head;
	ListNode* previousNode = head;
	int counter = 0;

	while (currentNode) {
		if (currentNode->value == n) { // value found
			counter++;
			if (currentNode == head) {
				head = currentNode->next;
				delete currentNode;
				return;
			}
			previousNode->next = currentNode->next;
			delete currentNode;
			return;
		}
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	if (counter == 0) {
		cout << "Data value " << n << " not found.";
	}
}
void IntList::print() {
	ListNode* currentNode = head;

	cout << "head=" << head << endl;
	cout << setw(5) << fixed << left;
	while (currentNode) {
		cout << currentNode
			<< ": value= " << currentNode->value
			<< " next= " << currentNode->next << endl;
		currentNode = currentNode->next;
	}
	cout << endl;
}
void IntList::nodePlacement(ListNode* node) {
	ListNode* currentNode = head;
	ListNode* previousNode = head;
	int counter = 0;

	while (currentNode) {
		if ((currentNode->value) > (node->value)) { // If value is less-than current list, insert infront.
			if (currentNode == head) {
				node->next = currentNode;
				head = node;
				return;
			}
			else {
				previousNode->next = node;
				node->next = currentNode;
				return;
			}
		}
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	if (!tail) {
		findTail(head);
	}
	tail->next = node;
	tail = node;
}
void IntList::findTail(ListNode* list) {
	ListNode* currentNode = head;
	while (currentNode != NULL) {
		tail = currentNode;

		currentNode = currentNode->next;
	}
}
IntList::~IntList() {
	cout << "Deleting list " << head;

	while (head) {
		cout << "Deleting node at " << head << endl;
		head = head->next;
		delete head;
	}
}
#ifndef INT_LIST
#define INT_LIST
#include<iostream>
using namespace std;

struct ListNode {
	int value;
	struct ListNode* next;
};
class IntList {
private:
	ListNode *head, *tail;
public:
	IntList(); // Default constructor
	~IntList();
	void appendNode(int n); // Append a new node at the end of the list.
	void insertNode(int n); // Insert a new node into the list, maintaining a sorted order.
	void deleteNode(int n); // remove a node from the list.
	void print(); // output the contents of the list to the screen
	void nodePlacement(ListNode* node);
	void findTail(ListNode* list);
};
#endif
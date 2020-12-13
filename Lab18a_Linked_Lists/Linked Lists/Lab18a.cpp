// This Lab Exercise involves designing and implementing a class called IntList, which creates a linked list of
// integer values. The general “policy” of this linked list is to maintain the list in sorted order
//
// Prof. Peter Morgan
// CSC237 Lab18: Linked List
// Yelsin Sepulveda
// December 13, 2020.

#include<iostream>
#include<string>
#include "IntList.h"
using namespace std;

void printSupportedCommands();

int main() {
	system("color 70");

	int num;
	string choice = "";
	IntList* newList = new IntList();

	cout << "Command: "; 
	getline(cin, choice);

	while (choice[0] != 'q' || choice[0] != 'Q') {
		switch (choice[0]) {
		case 'a': 
			cout << "Enter number to append to the list: ";
			cin >> num; cin.ignore(100, '\n');
			newList->appendNode(num);
			break;
		case 'd':
			cout << "Enter number to delete from the list: ";
			cin >> num; cin.ignore(100, '\n'); 
			newList->deleteNode(num);
			break;
		case 'i':
			cout << "Enter number to insert into the list: ";
			cin >> num; cin.ignore(100, '\n'); 
			newList->insertNode(num);
			break;
		case 'p':
			newList->print();
			break;
		case 'h': printSupportedCommands();
			break;
		case 'q':
			newList->~IntList();
			cout << "Exitting program with status = 0" << endl;
			break;
		default: printSupportedCommands();
			break;
		}
		cout << "Command: "; 
		getline(cin, choice);
	}

	system("pause");
	return 0;
}

void printSupportedCommands() {
	cout << "a" << "\t APPEND a new node at the end of the list" << endl
		<< "d" << "\t DELETE a node from the list" << endl
		<< "i" << "\t INSERT a node into the list, maintaining the sorted order." << endl
		<< "p" << "\t PRINT the contents of the list on the console." << endl
		<< "h" << "\t HELP text" << endl
		<< "q" << "\t QUIT (end the program)" << endl;
}

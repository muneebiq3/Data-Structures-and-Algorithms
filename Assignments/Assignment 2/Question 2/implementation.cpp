#include <iostream>
#include "header.h"

using namespace std;

int control::fibonacci(int num) {
	if(num <= 1)
		return num;
	else
		return fibonacci(num-1) + fibonacci(num-2);
}

int control::recursiveSum(node* start) {
	if (start == NULL)
		return 0;
	return start->number + recursiveSum(start->link);
}

node* control::reverseList(node *start) {
	node *prev = NULL;
	node *current = start;
	node *next;
	
	while (current != NULL) {
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	return prev;
}

void control::printList(node *start) {
	node *current = start;
	while (current != NULL) {
		cout << current->number << " ";
		current = current->link;
	}
	cout << endl;
}

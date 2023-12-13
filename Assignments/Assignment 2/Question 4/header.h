#ifndef header_H
#define header_H

#include <iostream>

using namespace std;

struct node {
	
	int number;
	
	int fibonacci(int);
	struct node *link;
};

struct control {
	public:
		
		struct node *start;
		
		int fibonacci(int);
		int recursiveSum(node *start);
		node *reverseList(node *start);
		void printList(node *start);
};
#endif

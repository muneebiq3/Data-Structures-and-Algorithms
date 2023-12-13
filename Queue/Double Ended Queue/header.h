#ifndef header_H
#define header_H

#include <iostream>

using namespace std;

struct node {
	int num;
	struct node *link;
};

struct control {
	public:
		
		struct node *left = NULL;
		struct node *right = NULL;
		
		int rearCount = 0;
		int size = 10;
		
		void insertRight();
		void insertLeft();
		void deleteLeft();
		void deleteRight();
		void display();
};

#endif

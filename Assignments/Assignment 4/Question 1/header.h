#ifndef header_H
#define header_H

#include <iostream>

using namespace std;

struct node {
	
	char data;
	bool visited;
	
	struct node *next = NULL;
	struct edge *adj = NULL;
	   
};

struct edge {
	
	char data;
	
	struct edge *link = NULL;
};

struct stack {
	
	node *data;
	
	struct stack *link = NULL;
	
};

struct control {
	
	public:
		
		struct node *start = NULL;
		struct stack *top = NULL;
		
		struct node *find(char);
		void insert_node(char);
		void insert_edge(char, char);
		void display();
		
		void push(node *data);
		node *pop();
		void depth_first_search(char);

};

#endif

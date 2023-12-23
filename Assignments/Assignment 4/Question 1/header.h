#ifndef header_H
#define header_H

#include <iostream>

using namespace std;

struct vertex {
	
	int info;
	
	struct edge *head = NULL; //for edges of every vertex
	struct vertex *next = NULL;
	   
};

struct edge {
	
	int info;
	
	struct edge *link = NULL;
};

struct stack {
	
	int info;
	
	struct stack *link = NULL;
	
};

struct control {
	
	public:
		struct stack *top = NULL;
		struct vertex *start = NULL;
		
		void push(int);
		void pop();
		
		void insertVertex(int);
		void insertEdge(vertex *v1, vertex *v2);
		void display();
		
		void push(stack **top, int);
		int pop(stack **top);
		bool isEmpty(stack *top);
		
		void depthFirstSearch(vertex *start);
};

//starting node for graph

#endif

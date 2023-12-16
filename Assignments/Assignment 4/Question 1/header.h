#ifndef header_H
#define header_H

#include <iostream>

using namespace std;

struct vertex {
	
	int info;
	
	struct vertex *next = NULL;
	struct vertex *previous = NULL;
	
	struct edge *edgeList = NULL; //for edges of every vertex
};

struct edge {
	
	int info;
	
	struct edge *link = NULL;
};

struct control {
	
	public:
		struct vertex *start = NULL;
		
		void insertVertex(int);
		void insertEdge(vertex *v1, vertex *v2);
		void deleteVertex(int);
		void deleteEdge(vertex *v1, vertex *v2);
		void display();
	
};

//starting node for graph

#endif

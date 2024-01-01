#ifndef header_H
#define header_H

#include <iostream>

using namespace std;

struct node{
	
	char name;
	int dist;
	char pred;
	char color;
	struct edge *adj = NULL;
	
	struct node *next = NULL;
};

struct edge{
	
	char dest;
	int dist;
	edge *link = NULL;;
	
	
};

struct queue{
	
	struct node *add_node = NULL;
	struct queue *link = NULL;
	
};

struct control {
	
	public:
		
		struct node *start = NULL;
		struct queue *front = NULL;
		struct queue *rear = NULL;
		
		struct node *find(char);
		void insert_node(char);
		void insert_edge(char, char, int);
		void display();
		
		void sort();
		void dequeue();
		void enqueue(node **c);
		void traverse_path(char, char);
		void find_path(char);
		
};

#endif

#ifndef header_H
#define header_H

#include <iostream>

using namespace std;

struct node{
	
	
	char name;
	int dist;
	char pred;
	struct edge *adj = NULL;
	
	struct node *next = NULL;
};

struct edge{
	
	char dest;
	int dist;
	
	struct edge *link = NULL;;
	
	
};

struct queue{
	
	char origin;
	char dest;
	int weight;
	
	struct queue *link = NULL;
	
};

struct control {
	
	public:
		
		int father[30];
		int wt_tree=0;
		int count=0;
		int num;
		
		struct node *start = NULL;
		struct queue *front = NULL;
		struct queue *rear = NULL;
		struct queue *front1 = NULL;
		struct queue *rear1 = NULL;
		
		struct node *find(char);
		void insert_node(char);
		void insert_edge(char, char, int);
		void display();

		void sort();
		queue *dequeue();
		void enqueue(int, int, int, queue **c, queue **d);
		void displayQ();
		void make_tree();
		
};

#endif

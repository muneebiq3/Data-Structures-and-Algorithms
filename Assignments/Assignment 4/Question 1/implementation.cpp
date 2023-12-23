#include <iostream>
#include "header.h"

using namespace std;

void control::insertVertex(int data) {
	
	struct vertex *temp = new struct vertex;
	temp->info = data;
	
	if(start == NULL)
		start = temp;
		
	else {
		
		vertex *q = start;
		while(q->next != NULL)
			q = q->next;
			
		q->next = temp;
		temp->next = NULL;
	}
	
}

void control::insertEdge(vertex *v1, vertex *v2) {
	
	struct edge *temp = new struct edge;
	temp->info = v2->info;
	
	if(v1->head == NULL)
		v1->head = temp;
		
	else {
		
		edge *q = v1->head;
		while(q->link != NULL)
			q = q->link;
			
		q->link = temp;
		
	}
	
	temp = new edge;
	temp->info = v1->info;
	
	if(v2->head == NULL)
		v2->head = temp;
		
	else {
		
		edge *q =v2->head;
		while(q->link != NULL)
			q = q->link;
			
		q->link = temp;
		
	}
	
}

void control::display() {
	
	vertex *tempVertex  = start;
	
	while(tempVertex != NULL) {
		
		cout << "Vertex " << tempVertex->info << " is connected to: ";
		
		edge *tempEdge = tempVertex->head;
		
		if(tempEdge == NULL)
			cout << tempVertex->info;
			
		else {
			
			while(tempEdge != NULL) {
			
				cout << tempEdge->info << "	";
				tempEdge = tempEdge->link;
			
			}	
		}

		cout << endl;
		tempVertex = tempVertex->next;
		
	}
	
}

void control::push(stack** top, int data) {
    stack* newNode = new stack;
    newNode->info = data;
    newNode->link = *top;
    *top = newNode;
}

int control::pop(stack** top) {
    if (*top == NULL) {
        cerr << "Error: stack is empty." << endl;
        return -1; // Assuming -1 is not a valid vertex index
    }

    int data = (*top)->info;
    stack* temp = *top;
    *top = (*top)->link;
    delete temp;
    return data;
}
bool control::isEmpty(stack* top) {
    return top == NULL;
}

void control::depthFirstSearch(vertex* start) {
    if (start == NULL) {
        cout << "Graph is empty." << endl;
        return;
    }

    stack* dfsstack = NULL;
    bool* visited = new bool[1000]; // Assuming a maximum of 1000 vertices
    for (int i = 0; i < 1000; i++) {
        visited[i] = false;
    }

    push(&dfsstack, start->info);
    visited[start->info] = true;

    cout << "Depth First Search:" << endl;

    while (!isEmpty(dfsstack)) {
        int currentVertex = pop(&dfsstack);

        cout << currentVertex << " ";

        edge* currentEdge = start[currentVertex].head;
        while (currentEdge != NULL) {
            if (!visited[currentEdge->info]) {
                visited[currentEdge->info] = true;
                push(&dfsstack, currentEdge->info);
            }
            currentEdge = currentEdge->link;
        }
    }

    cout << endl;

    delete[] visited;
}

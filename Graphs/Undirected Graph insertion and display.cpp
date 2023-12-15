#include <iostream>
using namespace std;

struct vertex {
	
	int info;
	
	struct vertex *next = NULL;
	struct vertex *previous = NULL;
	struct edge *edgeList = NULL;
};

struct edge {
	
	int info;
	
	struct edge *link = NULL;
};

vertex *start = NULL;

void insertVertex(int data) {
	
	struct vertex *temp = new struct vertex;
	temp->info = data;
	
	if(start == NULL)
		start = temp;
		
	else {
		
		vertex *q = start;
		while(q->next != NULL)
			q = q->next;
			
		temp->previous = q;
		q->next = temp;
		
	}
	
}

void insertEdge(vertex *v1, vertex *v2) {
	
	struct edge *temp = new struct edge;
	temp->info = v2->info;
	
	if(v1->edgeList == NULL)
		v1->edgeList = temp;
		
	else {
		
		edge *q = v1->edgeList;
		while(q->link != NULL)
			q = q->link;
			
		q->link = temp;
		
	}
	
	temp = new edge;
	temp->info = v1->info;
	
	if(v2->edgeList == NULL)
		v2->edgeList = temp;
		
	else {
		
		edge *q =v2->edgeList;
		while(q->link != NULL)
			q = q->link;
			
		q->link = temp;
		
	}
	
}

void display() {
	
	vertex *v  = start;
	while(v != NULL) {
		
		cout << "Vertex " << v->info << " is connected to: ";
		edge *e = v->edgeList;
		while(e != NULL) {
			
			cout << e->info << "	";
			e = e->link;
			
		}
		
		cout << endl;
		v = v->next;
		
	}
	
}

int main() {
	
	insertVertex(1);
	insertVertex(2);
	insertVertex(3);
	
	insertEdge(start, start->next);
	insertEdge(start->next, start->next->next);
	insertEdge(start->next->next, start);
	
	display();
	
	return 0;
}

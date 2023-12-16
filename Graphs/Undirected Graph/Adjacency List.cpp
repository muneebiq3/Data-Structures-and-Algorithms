#include <conio.h>
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

struct vertex *start = NULL;

void insertVertex(int data) {
	
	struct vertex *duplicateCheck = new struct vertex;
	duplicateCheck = start;
    while (duplicateCheck != NULL) {
        if (duplicateCheck->info == data) {
            cout << "Vertex " << data << " already exists!" << endl;
            return;
        }
        duplicateCheck = duplicateCheck->next;
    }
	
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
	
	if(v1 == v2) {
		cout << "Cannot insert an edge between same vertex!" << endl;
		return;
	}
	
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
	
	cout << "Edge inserted between vertices " << v1->info << " and " << v2->info << endl;
	
}

void display() {
	
	vertex *tempVertex  = start;
	
	while(tempVertex != NULL) {
		
		cout << "Vertex " << tempVertex->info << " is connected to: ";
		
		edge *tempEdge = tempVertex->edgeList;
		
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

int main() {
	
	int choice;
	
	while(1) {
		
		cout << "\nAdjacency List for Undirected Graph\n";
		cout << "\n1. Insert Vertex";
		cout << "\n2. Insert Edge";
		cout << "\n3. Display";
		cout << "\n4. Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) {
			
			case 1: {
				
				int data;
				cout << "Enter the vertex: "; cin >> data;
				insertVertex(data);
				
				getch();
				system("cls");
				break;
				
			} case 2: {
				
				int vertex1, vertex2;
				cout << "Enter the first vertex: "; cin >> vertex1;
				cout << "Enter the second vertex: "; cin >> vertex2;
				
				vertex *v1 = NULL, *v2 = NULL;
				vertex *temp = start;
				
				while(temp != NULL) {
					
					if(temp->info == vertex1)
						v1 = temp;
					if(temp->info == vertex2)
						v2 = temp;
						
					temp = temp->next;
					
				}
				
				if(v1 == NULL && v2 == NULL)
					cout << "Both Vertices " << vertex1 << " and " << vertex2 << " not found in the Graph!";
				else if(v1 == NULL)
					cout << "First Vertex " << vertex1 << " not found in the Graph!";
				else if(v2 == NULL)
					cout << "Second Vertex " << vertex2 << " not found in the Graph!";
				else 
					insertEdge(v1, v2);
				
				getch();
				system("cls");
				break;
				
			} case 3: {
				
				if(start == NULL) {
					cout << "Graph is empty!";
					getch();
					system("cls");
					break;
				}
				
				else
					display();
				
				getch();
				system("cls");
				break;
				
			} case 4:
				exit(0);
				
			default: {
				cout << "Wrong Choice!";
				getch();
				system("cls");
			}
		}
	}
}


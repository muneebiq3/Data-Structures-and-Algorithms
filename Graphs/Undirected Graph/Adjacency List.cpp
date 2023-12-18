#include <iostream>
#include <conio.h>

using namespace std;

struct vertex {
	
	int info;
	
	struct edge *head = NULL;
	struct vertex *next = NULL;
	   
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
			
		q->next = temp;
		temp->next = NULL;
	}
	
}

void insertEdge(vertex *v1, vertex *v2) {
	
	if(v1 == v2) {
		cout << "Cannot insert an edge between same vertex!" << endl;
		return;
	}
	
	edge *existingEdge = v1->head;
    while (existingEdge != NULL) {
        if (existingEdge->info == v2->info) {
            cout << "Edge already exists between vertices " << v1->info << " and " << v2->info << endl;
            return;
        }
        existingEdge = existingEdge->link;
    }
	
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
	
	cout << "Edge inserted between vertices " << v1->info << " and " << v2->info << endl;
	
}

void deleteVertex(int data) {
	
    // Find the vertex to be deleted
    vertex *current = start;
    vertex *prev = NULL;

    while (current != NULL && current->info != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Vertex " << data << " not found." << endl;
        return;
    }

    // Delete all edges connected to the vertex
    edge *currentEdge = current->head;
    while (currentEdge != NULL) {
        edge *tempEdge = currentEdge;
        currentEdge = currentEdge->link;

        // Update the edge list of the other vertex
        vertex *connectedVertex = start;
        while (connectedVertex != NULL && connectedVertex->info != tempEdge->info) {
            connectedVertex = connectedVertex->next;
        }

        if (connectedVertex != NULL) {
            // Find and delete the corresponding edge in the connected vertex
            edge *prevEdge = NULL;
            edge *currentEdge2 = connectedVertex->head;
            while (currentEdge2 != NULL && currentEdge2->info != data) {
                prevEdge = currentEdge2;
                currentEdge2 = currentEdge2->link;
            }

            if (prevEdge == NULL) {
                connectedVertex->head = currentEdge2->link;
            } else {
                prevEdge->link = currentEdge2->link;
            }

            delete currentEdge2;
        }

        delete tempEdge;
    }

    // Delete the vertex
    if (prev == NULL) 
        // If the vertex to be deleted is the first one
        start = current->next;
    else 
        prev->next = current->next;
    

    delete current;

    cout << "Vertex " << data << " and its edges deleted." << endl;
}

void deleteEdge(vertex *v1, vertex *v2) {
	
    if (v1 == v2) {
        cout << "Cannot delete an edge between the same vertex!" << endl;
        return;
    }

    // Check if the edge exists from v1 to v2
    edge *prev1 = NULL;
    edge *current1 = v1->head;
    while (current1 != NULL && current1->info != v2->info) {
        prev1 = current1;
        current1 = current1->link;
    }

    if (current1 == NULL) {
        cout << "Edge does not exist between vertices " << v1->info << " and " << v2->info << endl;
        return;
    }

    // Delete edge from v1 to v2
    if (prev1 == NULL) {
        v1->head = current1->link;
    } else {
        prev1->link = current1->link;
    }

    // Check if the edge exists from v2 to v1
    edge *prev2 = NULL;
    edge *current2 = v2->head;
    while (current2 != NULL && current2->info != v1->info) {
        prev2 = current2;
        current2 = current2->link;
    }

    if (current2 == NULL) {
        cout << "Edge does not exist between vertices " << v2->info << " and " << v1->info << endl;
        return;
    }

    // Delete edge from v2 to v1
    if (prev2 == NULL) {
        v2->head = current2->link;
    } else {
        prev2->link = current2->link;
    }

    delete current1;
    delete current2;

    cout << "Edge deleted between vertices " << v1->info << " and " << v2->info << endl;
}

void display() {
	
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

int main() {
	
	int choice;
	
	while(1) {
		
		cout << "\nAdjacency List for Undirected Graph\n";
		cout << "\n1. Insert Vertex";
		cout << "\n2. Insert Edge";
		cout << "\n3. Delete Vertex";
		cout << "\n4. Delete Edge";
		cout << "\n5. Display";
		cout << "\n6. Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) {
			
			case 1: {
				
				int data;
				cout << "Enter the vertex to be added: "; cin >> data;
				insertVertex(data);
				
				getch();
				system("cls");
				break;
				
			} case 2: {
				
				if(start == NULL) {
					cout << "Graph is empty!" << endl;
					
					getch();
					system("cls");
					break;
				}
				
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
					cout << "Graph is empty!" << endl;
					getch();
					system("cls");
					break;;
				}
				
				int data;
				cout << "Enter the vertex to be deleted: "; cin >> data;
				deleteVertex(data);
				
				getch();
				system("cls");
				break;
				
				
			} case 4: {
				
				if(start == NULL) {
					cout << "Graph is empty!" << endl;
					
					getch();
					system("cls");
					break;
				}
				
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
					deleteEdge(v1, v2);
				
				getch();
				system("cls");
				break;
				
			} case 5: {
				
				if(start == NULL) {
					cout << "Graph is empty!" << endl;
					
					getch();
					system("cls");
					break;
				}
				
				else
					display();
				
				getch();
				system("cls");
				break;
				
			} case 6:
				exit(0);
				
			default: {
				cout << "Wrong Choice!";
				getch();
				system("cls");
			}
		}
	}
}

#include <iostream>
#include "header.h"

using namespace std;

void control::insertVertex(int data) {
	
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

void control::insertEdge(vertex *v1, vertex *v2) {
	
	if(v1 == v2) {
		cout << "Cannot insert an edge between same vertex!" << endl;
		return;
	}
	
	edge *existingEdge = v1->edgeList;
    while (existingEdge != NULL) {
        if (existingEdge->info == v2->info) {
            cout << "Edge already exists between vertices " << v1->info << " and " << v2->info << endl;
            return;
        }
        existingEdge = existingEdge->link;
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

void control::deleteVertex(int data) {
	
    // Find the vertex to be deleted
    vertex *current = start;
    vertex *prev = NULL;

    while (current != NULL && current->info != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Vertex with data " << data << " not found." << endl;
        return;
    }

    // Delete all edges connected to the vertex
    edge *currentEdge = current->edgeList;
    while (currentEdge != NULL) {
        edge *tempEdge = currentEdge;
        currentEdge = currentEdge->link;

        // Update the edge list of the other vertex
        vertex *connectedVertex = start;
        while (connectedVertex != NULL) {
            if (connectedVertex->info == tempEdge->info) {
                // Delete the edge from the other vertex's edge list
                edge *prevEdge = NULL;
                edge *currentEdge2 = connectedVertex->edgeList;
                while (currentEdge2 != NULL && currentEdge2->info != data) {
                    prevEdge = currentEdge2;
                    currentEdge2 = currentEdge2->link;
                }

                if (prevEdge == NULL) {
                    connectedVertex->edgeList = currentEdge2->link;
                } else {
                    prevEdge->link = currentEdge2->link;
                }

                delete currentEdge2;
                break;
            }

            connectedVertex = connectedVertex->next;
        }

        delete tempEdge;
    }

    // Update links to bypass the vertex to be deleted
    if (prev == NULL) {
        start = current->next;
    } else {
        prev->next = current->next;
        if (current->next != NULL) {
            current->next->previous = prev; // Update the previous link of the next vertex
        }
    }

    // Delete the vertex
    delete current;

    cout << "Vertex with data " << data << " and its edges deleted." << endl;
}

void control::deleteEdge(vertex *v1, vertex *v2) {
	
    if (v1 == v2) {
        cout << "Cannot delete an edge between the same vertex!" << endl;
        return;
    }

    // Check if the edge exists from v1 to v2
    edge *prev1 = NULL;
    edge *current1 = v1->edgeList;
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
        v1->edgeList = current1->link;
    } else {
        prev1->link = current1->link;
    }

    // Check if the edge exists from v2 to v1
    edge *prev2 = NULL;
    edge *current2 = v2->edgeList;
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
        v2->edgeList = current2->link;
    } else {
        prev2->link = current2->link;
    }

    delete current1;
    delete current2;

    cout << "Edge deleted between vertices " << v1->info << " and " << v2->info << endl;
}

void control::display() {
	
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

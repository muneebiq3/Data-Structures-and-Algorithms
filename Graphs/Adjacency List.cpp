#include <iostream>
#include <conio.h>

using namespace std;

struct node {
	
	char data;
	
	struct node *next = NULL;
	struct edge *adj = NULL;
	
};

struct edge {
	
	char data;
	
	struct edge *link = NULL;
	
};

struct node *start = NULL;

struct node *find(char item_name) {
	
	node *ptr = start;
	while(ptr != NULL) {

		if (item_name == ptr->data)
			return ptr;
		
		else
			ptr = ptr->next;
		
	}
	return NULL;
	
}

void insert_node(char item_name) {
	
	struct node *temp = new struct node;
	struct node *ptr = new struct node;

	temp->data = item_name;
	temp->next = NULL;
	temp->adj = NULL;
	
	if(start ==  NULL)
		start = temp;
		
	else {
	
		ptr = start;
		while(ptr->next != NULL)
			ptr = ptr->next;
		
		ptr->next = temp;	
	}
	cout << "Node with data " << item_name << " inserted in the graph." << endl;
}

void insert_edge(char u, char v) {

    if (start == NULL) {
        cout << "Graph is empty!" << endl;
        return;
    }

    struct node* locu = find(u);
    struct node* locv = find(v);

    if (locu == NULL) {
        cout << "Node with data " << u << " not found in the graph!" << endl;
        return;
    }
    if (locv == NULL) {
        cout << "Node with data " << v << " not found in the graph!" << endl;
        return;
    }

    // Check if the edge already exists
    struct edge* ptr = locu->adj;
    while (ptr != NULL) {
        if (ptr->data == v) {
            cout << "Edge between Node " << u << " and Node " << v << " already exists." << endl;
            return;
        }
        ptr = ptr->link;
    }

    // Insert edge from location u to locution v
    struct edge* temp = new edge;
    temp->data = v;
    temp->link = NULL;

    if (locu->adj == NULL)
        locu->adj = temp;
    else {
        ptr = locu->adj;
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = temp;
    }

    // Check if the edge already exists
    ptr = locv->adj;
    while (ptr != NULL) {
        if (ptr->data == u) {
            cout << "Edge between Node " << u << " and Node " << v << " already exists!" << endl;
            // If the edge already exists, undo
            delete temp;
            return;
        }
        ptr = ptr->link;
    }

    // Insert edge from locv to locu
    temp = new edge;
    temp->data = u;
    temp->link = NULL;

    if (locv->adj == NULL)
        locv->adj = temp;
    else {
        ptr = locv->adj;
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = temp;
    }

    cout << "Edge inserted between Node " << u << " and Node " << v << endl;
}

void delete_node(char u) {
	
	if (start == NULL) {
		
		cout << "Graph is empty!" << endl;
		return;
		
	}
	
	struct node *temp = new struct node;
	struct node *q = new struct node;
	
	//if the node to be deleted is the starting node
	if(start->data == u) {
		temp = start;
		start = start->next;
		delete temp;
		return;
	}
	
	q = start;
	while(q->next->next != NULL) {
		
		if(q->next->data == u) {			
			temp = q->next;
			q->next = temp->next;
			delete temp;
			return;
		}
		q = q->next;
	}
	if(q->next->data == u) {
		temp = q->next;
		delete temp;
		q->next = NULL;
	}
	cout << "Node with data " << u << " and its edges has been deleted." << endl;
}

void delete_node_edge(char u) {
	
	// delete all edges connected to the vertex
	struct node *ptr = new struct node;
	
	struct edge *temp = new struct edge;
	struct edge *q = new struct edge;
	
	ptr = start;
	
	while(ptr != NULL) {
		
		// delete first edge of a node if that node makes an edge with current node to be deleted
		if(ptr->adj->data == u) {
			temp = ptr->adj;
			ptr->adj = ptr->adj->link;
			delete temp;
			continue;
		}
		
		// delete edge of a node if that node makes an edge with current node to be deleted if it's not the first edge
		q = ptr->adj;
		while(q->link->link != NULL) {
			
			if(q->link->data = u) {
				temp = q->link;
				q->link = temp->link;
				delete temp;
				continue;
			}
			q = q->link;
		}
		if(q->link->data == u) {
			temp = q->link;
			delete temp;
			q->link = NULL;
		}
		ptr = ptr->next;
	}
	
}

void delete_edge(char u, char v) {

    if (start == NULL) {
        cout << "Graph is empty!" << endl;
        return;
    }

    struct node* locu = find(u);
    struct node* locv = find(v);

    if (locu == NULL) {
        cout << "Node with data " << u << " not found!" << endl;
        return;
    }
    if (locv == NULL) {
        cout << "Node with data " << v << " not found!" << endl;
        return;
    }

    // Delete edge from locu to locv
    struct edge* q = locu->adj;
    struct edge* temp = NULL;
    if (q != NULL && q->data == v) {
        temp = q;
        locu->adj = q->link;
        delete temp;
    } else {
        while (q != NULL && q->link != NULL) {
            if (q->link->data == v) {
                temp = q->link;
                q->link = temp->link;
                delete temp;
            }
            q = q->link;
        }
        cout << "Edge between Node " << u << " and Node " << v << " not found!" << endl;
        return;
    }

    // Delete edge from locv to locu
    q = locv->adj;
    if (q != NULL && q->data == u) {
        temp = q;
        locv->adj = q->link;
        delete temp;
    } else {
        while (q != NULL && q->link != NULL) {
            if (q->link->data == u) {
                temp = q->link;
                q->link = temp->link;
                delete temp;
            }
            q = q->link;
        }
    }
    cout << "The edge between Node " << u << " and Node " << v << " has been deleted." << endl;
}

void display() {
	
	if(start == NULL) {
		cout << "Graph is empty!" << endl;
		return;
	}
	
	struct node *ptr  = new struct node;
	ptr = start;
	
	while(ptr != NULL) {
		
		cout << "Node with data " << ptr->data << " is connected to: ";
		
		edge *q = ptr->adj;
		
		if(q == NULL)
			cout << ptr->data;
			
		else {
			
			while(q != NULL) {
			
				cout << q->data << "	";
				q = q->link;
			
			}	
		}

		cout << endl;
		ptr = ptr->next;
		
	}
	
}

int main () {
	
	int choice;
	char node, origin, destination;
	
	while (1) {
		
		cout << "\nAdjacency List\n";
		cout << "\n1. Insert a node";
		cout << "\n2. Insert an edge";
		cout << "\n3. Delete a node";
		cout << "\n4. Delete an edge";
		cout << "\n5. Display";
		cout << "\n6. Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch(choice) {
			
			case 1: {
				
				cout << "Enter a node to be added: "; cin >> node;
				insert_node(node);
				getch();
				system("cls");
				break;
				
			} case 2: {
				
				cout << "Enter the first node: "; cin >> origin;
				cout << "Enter the second node: "; cin >> destination;
				insert_edge(origin, destination);
				getch();
				system("cls");
				break;
				
			} case 3: {
				
				cout << "Enter a node to be deleted: "; cin >> node;
				delete_node_edge(node);
				delete_node(node);
				getch();
				system("cls");
				break;
				
			} case 4: {
				
				cout << "Enter the first node: "; cin >> origin;
				cout << "Enter the second node: "; cin >> destination;
				delete_edge(origin, destination);
				getch();
				system("cls");
				break;
				
			} case 5: {
				
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
		
	return 0;
}

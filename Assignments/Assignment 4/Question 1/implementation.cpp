#include <iostream>
#include "header.h"

using namespace std;

struct node *control::find(char item_name) {
	
	struct node *ptr = new node;
	ptr = start;
	while(ptr != NULL) {

		if (item_name == ptr->data)
			return ptr;
		
		else
			ptr = ptr->next;
		
	}
	return NULL;
	
}

void control::insert_node(char item_name) {

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
}

void control::insert_edge(char u, char v) {

    struct node* locu = find(u);
    struct node* locv = find(v);
    
    struct edge* ptr = locu->adj;

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
}

void control::display() {
	
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

void control::push(node *info) {
	
	struct stack *temp = new struct stack;
	temp->data = info;
	temp->link = top;
	top = temp;
	
}

struct node *control::pop() {
	
	if(top == NULL) {
		cout << "Stack is empty!" << endl;
		return NULL;
	}
	struct stack *temp = top;
	struct node *data = temp->data;
	
    top = top->link;
    
    delete temp;
    return data;
}

void control::depth_first_search(char start_node_name) {
	
    node *start_node = find(start_node_name);

    if (start_node == NULL) {
        cout << "Node not found in the graph." << endl;
        return;
    }
    
    node *visited_array[5];
    int i = 0;
    int j = 0;
    struct stack *ptr;

    top = NULL;
    start_node->visited = true;
    push(start_node);
    
    cout << "\nStack after " << j + 1 << " pass:\n";
    cout << start_node->data << endl;

    while (top != NULL) {
        j++;
        node *current = pop();
        
        cout << "\nStack after " << j + 1 << " pass:\n";
        ptr = top;
        while(ptr != NULL) {
            cout << ptr->data->data << "\t";
            ptr = ptr->link;
        }
        
        cout << "\nVisited Array after " << j + 1 << " pass:\n";
        visited_array[i] = current;
        for(int k = 0; k <= i; k++)
            cout << visited_array[k]->data << "\t";
        i++;
        
        edge *temp = current->adj;
        while (temp != NULL) {
            node *adj_node = find(temp->data);
            if (adj_node != NULL && adj_node->visited == false) {
                j++;
                adj_node->visited = true;
                push(adj_node);
                cout << "\nStack after " << j + 1 << " pass:\n";
                ptr = top;
                while(ptr != NULL) {
                    cout << ptr->data->data << "\t";
                    ptr = ptr->link;
                }
            }
            temp = temp->link;
        }
    }

    node *reset_ptr = start;
    while (reset_ptr != NULL) {
        reset_ptr->visited = false;
        reset_ptr = reset_ptr->next;
    }
}



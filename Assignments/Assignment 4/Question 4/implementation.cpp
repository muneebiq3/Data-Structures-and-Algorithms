#include <iostream>
#include "header.h"

using namespace std;

struct node *control::find(char item) {
	
	struct node *ptr = new struct node;
	struct node *location = new struct node;
	
	ptr = start;
	while(ptr != NULL){
		if(item == ptr->name){
			location = ptr;
			return location;
			
		}
		else
			ptr = ptr->next;
	}
	location = NULL;
	return location;
	
}

void control::insert_node(char name) {

	struct node *temp = new struct node;
	struct node *ptr = new struct node;
	
	temp->name = name;
	temp->color = 'w';
	temp->dist = 9999;
	temp->pred = 'n';
	
	temp->next = NULL ;
	temp->adj = NULL;
	
    if(start == NULL){
    	start = temp;
    	return;
	}
	ptr = start;
	while(ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = temp;
}

void control::insert_edge(char u, char v, int d) {

    struct node* locu = find(u);
    struct node* locv = find(v);
    struct edge *ptr = new struct edge;

    // Insert edge from location u to locution v
    struct edge* temp = new edge;
    temp->dest = v;
    temp->dist = d;
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
    temp->dest = u;
    temp->dist = d;
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
		
		cout << "Node with data " << ptr->name << " is connected to: ";
		
		edge *q = ptr->adj;
		
		if(q == NULL)
			cout << ptr->name;
			
		else {
			
			while(q != NULL) {
			
				cout << q->dest << "	";
				q = q->link;
			
			}	
		}

		cout << endl;
		ptr = ptr->next;
		
	}
}

bool control::if_equal(node *q, node *p) {
	
	struct node *d = new struct node;
	bool flag;
	
	d = start;
	while(d != NULL){
		if(d->name == q->name){
			
			flag = true;
			break;
			
		}
		if(d->name == p->name){
			flag = false;
			break;
		}
		d = d->next;
	}
	return flag;
	
}

void control::sort() {
	
	struct queue *q = new struct queue;
	struct node *temp = new struct node;
	
	q = front;
	while(q !=NULL){
		
		queue *p = q->link;
		while(p != NULL){
			if(q->add_node->dist > p->add_node->dist){
				temp = p->add_node;
				p->add_node = q->add_node;
				q->add_node = temp;
			}
			if(q->add_node->dist == p->add_node->dist){
				bool a= if_equal(q->add_node, p->add_node);
				if(a == false){
					temp = p->add_node;
					p->add_node = q->add_node;
					q->add_node = temp;
				}
				
			}
			p = p->link;
		}
		q = q->link;
	}
	
}

node *control::dequeue() {
	
    if(front == NULL){
        cout << "Queue is empty!" << endl;
        return NULL;
    }
    struct queue *temp = new struct queue;
	temp = front;
    front = front->link;
    temp->link = NULL;
    
    return temp->add_node;
}

	
void control::enqueue(node **c) {
	
	queue *temp = new struct queue;
	
	temp->add_node = *c;
	if(front == NULL) {
		front = temp;
		rear = temp;
	}
	rear->link = temp;
	rear = temp;
	
}

void control::enqueue2(node **c) {
	
	struct queue *temp = new queue;
	
	temp->add_node = *c;
	if(front1 == NULL){
		front1 = temp;
		rear1 = temp;
	}
	rear1->link = temp;
	rear1 = temp;
	
}

void control::traverse_path(char s, char d) {
	
	struct node *locd = new struct node;
	locd = find(d);
	
	while(locd->pred != 'n') {
		cout << locd->name<< "----";
		cout << locd->dist;
		locd = find(locd->pred);
	
	}
	cout << s << endl;
}

void control::displayQ() {
	struct queue *w = new struct queue;
	w = front1;
	
	while(w != NULL){
		
		cout << w->add_node->name << "  " << w->add_node->dist << endl;
		w = w->link;
	}
}

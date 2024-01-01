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

void control::sort() {
	
	struct queue *q = new struct queue;
	struct node *temp = new struct node;
	q = front;
	
	while(q != NULL) {
		
		struct queue *p = new struct queue;
		p = q->link;
		
		while(p != NULL) {
			if(q->add_node->dist > p->add_node->dist) {
				temp = p->add_node;
				p->add_node = q->add_node;
				q->add_node = temp;
			}
			p = p->link;
		}
		q = q->link;
	}
	
}

void control::dequeue() {
	
    if(front == NULL) {
        cout << "Queue is empty!" << endl;
        return;
    }
    struct queue *temp = new struct queue;
    temp = front;
    
    front = front->link;
    temp->link = NULL;
    delete temp;
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
void control::find_path(char s){
	
	struct node *q = new struct node;
	q = start;
		
	while(q != NULL) {
		enqueue(&q);
		q = q->next;
	}

	struct node *ptr = new struct node;
	
	ptr=find(s);
	ptr->dist = 0;
	while(front!=NULL) {

		sort();
		
		struct node *source = new struct node;
		source = front->add_node;
		
		struct edge *e = new struct edge;
		e = source->adj;
		
		while(e != NULL) {
			
			struct node *qtr = new struct node;
			qtr = find(e->dest);
			
			if(qtr->color != 'B') {
				
				int add = source->dist + e->dist;
				
				if(qtr->dist > add) {	
					qtr->dist = add;
					qtr->pred = source->name;
			    }
			}
			e = e->link;
		}
		front->add_node->color = 'B';
		dequeue();
	}
	
}

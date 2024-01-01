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

	temp->name  =name;
	temp->dist = 9999;
	temp->pred = 'n';
	
	temp->next = NULL;
	temp->adj = NULL;
	
    if(start==NULL){
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
	int tmp_o;
	int tmp_d;
	int tmp_w;
	
	q = front;
	
	while(q != NULL) {
		
		struct queue *p = new struct queue;
		p = q->link;
		
		while(p != NULL){
			
			if(q->weight > p->weight){
				tmp_o = p->origin;
				tmp_d = p->dest;
				tmp_w = p->weight;
				
				p->origin = q->origin;
				p->dest = q->dest;
				p->weight = q->weight;
				
				q->origin = tmp_o;
				q->dest = tmp_d;
				q->weight = tmp_w;
				
			}
			p = p->link;	
		}
		q = q->link;
	}
	
}

queue *control::dequeue() {
	
    if(front == NULL){
        cout << "Queue is empty!" << endl;
        return NULL;
    }
    struct queue *temp = new struct queue;
	temp = front;
    front = front->link;
    temp->link = NULL;
    return temp;
}

	
void control::enqueue(int s, int d, int w, queue**f , queue **r) {
	
	struct queue *temp = new struct queue;
	
	temp->origin = s;
	temp->dest = d;
	temp->weight = w;
	temp->link = NULL;
	
	if(*f == NULL) {
		*f = temp;
		*r = temp;
		return;
	}
	(*r)->link = temp;
	*r = temp;
	
}

void control::displayQ() {
	
	struct queue *w = new struct queue;
	w = front1;
	
	while(w != NULL){
		
		cout << w->origin << "-->" << w->dest << "    " << w->weight << endl;
		w = w->link;
	}
}

void control::make_tree() {
	
	struct queue *temp = new struct queue;
	int node1, node2, root_n1, root_n2;
	
	while(count < num - 1) {
		
		temp = dequeue();
		node1 = temp->origin;
		node2 = temp->dest;
		
		while(node1 > 0) {
			
			root_n1 = node1;
			node1 = father[node1];
		}
		
		while (node2 > 0) {
			
			root_n2 = node2;
			node2 = father[node2];
		}
		
		if(root_n1 != root_n2) {
			
			count++;
			enqueue(temp->origin, temp->dest, temp->weight, &front1, &rear1);
			wt_tree = wt_tree + temp->weight;
			father[root_n2] = root_n1;
			
		}
		
	}
	
}

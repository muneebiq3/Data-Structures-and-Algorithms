#include <iostream>
#include "header.h"

using namespace std;

void control::insertRight() {
	
	if(rearCount == size) {
		
		cout << "Queue Overflown!" << endl;
		return;
		
	}
	
	struct node *temp = new struct node;
	int pushedItem;
	
	cout << "Enter the value to be inserted from the right: "; cin >> pushedItem;
	
	temp->num = pushedItem;
	temp->link = NULL;
	
	if(right == NULL) {
		
		left = temp;
		right = temp;
		
	} else {
		
		right->link = temp;
		right = temp;
		
	}
	
	rearCount++;
	
}
void control::insertLeft() {
		
	if(rearCount == size) {
		
		cout << "Queue Overflown!" << endl;
		return;
	}
	
	struct node *temp = new struct node;
	int pushedItem;
	
	cout << "Enter the value to be inserted from the left: "; cin >> pushedItem;
	
	temp->num = pushedItem;
	temp->link = NULL;
	
	if (left == NULL) {
		
		left = temp;
		right = temp;
		
	} else {
		
		temp->link = left;
		left = temp;
		
	}
	
	rearCount++;
	
}
void control::deleteLeft(){
	
	if (left == NULL) {
		
		cout << "Queue Underflown!" << endl;
		return;
		
	} else {
		
		cout << "Deleted item from the left: " << left->num << endl;
		
		struct node *temp = left;
		
		if (left == right) {
			
			left = NULL;
			right = NULL;
			
		} else {
			
			left = left->link;
			delete temp;
			rearCount--;
		}
	}
	
}
void control::deleteRight() {
	
	if (left == NULL) {
		
		cout << "Queue Underflown!" << endl;
		return;
		
	} else {
		
		cout << "Deleted item from the right: " << right->num << endl;
		
		struct node *temp = NULL;
		
		if (left == right) {
			
			left = NULL;
			right = NULL;
			
		} else {
			
			struct node *current = left;
			
			while (current->link != right)
				current = current->link;
			
			temp = right;
			right = current;
			current->link = NULL;
			delete temp;
			rearCount--;
		}
		
	}
	
}
void control::display() {
	
	if (left == NULL) 
		cout << "Queue is empty!" << endl;
	else {
		cout << "Queue elements: ";
		struct node *ptr = left;
		
		while(ptr != NULL) {
			cout << ptr->num << " ";
			ptr = ptr->link;
		}
		cout << endl;
	}
	
}

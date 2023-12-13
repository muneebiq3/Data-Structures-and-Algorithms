#include "header.h"
#include <iostream>

using namespace std;

void control::populateQueue(struct tree *tree) {
	
	struct queue *temp= new queue;
	temp->root = tree;
	temp->link = NULL;
	
    if (rear == NULL)
        front = rear = temp;
    else {
        rear->link = temp;
        rear = temp;
	}    
}

void control::swap() {
	
	if(front == NULL) {
		
		cout << "No swapping needed." << endl;
		return;
		
	}
	
	bool swapped = true;
	
	queue *helperNode;
	queue *greaterNode = NULL;
	
	do {
		
		swapped = false;
		helperNode = front;
		
		while(helperNode->link != greaterNode) {
			
			if (helperNode->root->info >= helperNode->link->root->info) {
				
				tree *temp = helperNode->root;
				helperNode->root = helperNode->link->root;
				helperNode->link->root = temp;
				swapped = true;
				
			} helperNode = helperNode->link;
		} greaterNode = helperNode;
		
	} while(swapped);
	
}

tree* control::pop() {
	
	if(front == NULL)
		return NULL;
		
	queue *temp = front;
	front = front->link;
	if(front == NULL)
		rear = NULL;	
	
	tree *tree = temp->root;
	
	delete temp;
	return tree;
	
}

void control::inorder(struct tree *root, int encodingValue) {
	
	if(root != NULL) {
		
		inorder(root->lchild, 0);
		cout << root->info << "-" << encodingValue << "		";
		inorder(root->rchild, 1);
		
	}
	
}

void control::buildTree() {
	
	struct queue *current = front;
	struct queue *nextNode = front->link;
	
		
	if(front != NULL) {
		 
		struct queue *temp = new struct queue;
		temp->root = new struct tree;
			
		temp->root->info = current->root->info + nextNode->root->info;
		temp->root->lchild = current->root;
		temp->root->rchild = nextNode->root;
			
		populateQueue(temp->root);
			
		pop();
		pop();
			
		swap();
			
		inorder(temp->root, 0);
		cout << endl << endl;
		
	}
	
}

void control::display() {
	
	if (front == NULL)
    	cout << "Queue is empty!" << endl;
    else {
    	
        cout << "Queue:" << endl;
        struct queue *current = front;
        
        while (current != NULL) {
            cout << current->root->info <<"		";
            current = current->link;
            
        } cout << endl;
    }
}


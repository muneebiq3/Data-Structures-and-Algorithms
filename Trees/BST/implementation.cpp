#include "header.h"
#include <iostream>

using namespace std;

void control::find(int item, node **parent, node **location) {
    struct node *ptr, *ptrSave;

    if (root == NULL) {
        *location = *parent = NULL;
        return;
    }

    if (item == root->info) {
        *location = root;
        *parent = NULL;
        return;
    }

    if (item < root->info)
        ptr = root->lchild;
    else
        ptr = root->rchild;

    ptrSave = root;

    while (ptr != NULL) {
        if (item == ptr->info) {
            *location = ptr;
            *parent = ptrSave;
            return;
        }
        ptrSave = ptr;

        if (item < ptr->info)
            ptr = ptr->lchild;
        else
            ptr = ptr->rchild;
    }

    *location = NULL;
    *parent = ptrSave;
}

void control::insert() {
	
    struct node *temp, *parent, *location;
    
    int item;
    
    cout << "Enter the value to be inserted: "; cin >> item;
    
    find(item, &parent, &location);

    if (location != NULL) {
        cout << "Item already inserted in the tree." << endl;
        return;
    }

	else {
		temp = new node;
	    temp->info = item;
	    temp->lchild = temp->rchild = NULL;
	
	    if (parent == NULL)
	        root = temp;
	    else {
	        if (item < parent->info)
	            parent->lchild = temp;
	        else
	            parent->rchild = temp;
	    }
	}
}

void control::del() {
    struct node *parent, *location;

    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return;
    }
    
    else {
    	
    	int item;
    
    	cout << "Enter the value to be deleted: "; cin >> item;

		find(item, &parent, &location);
	
	    if(location == NULL) {
	    	cout << "Item not found!";
	    	return;
		}
		
		if((location->lchild == NULL) && (location->rchild == NULL)) 
			caseA(parent, location);
		if((location->lchild != NULL) && (location->rchild == NULL)) 
			caseB(parent, location);
		if((location->lchild == NULL) && (location->rchild != NULL)) 
			caseB(parent, location);
		if((location->lchild != NULL) && (location->rchild != NULL)) 
			caseC(parent, location);
	}
}

void control::caseA(node *parent, node *location) {
	
	if(parent == NULL)
		root = NULL;
	else
		if(location == parent->lchild)
			parent->lchild = NULL;
		else 
			parent->rchild = NULL;
	
}

void control::caseB(node *parent, node *location) {
	
	struct node *child = NULL;
	
	if(location->lchild != NULL)
		child = location->lchild;
	else
		child = location->rchild;
	if(parent == NULL) 
		root = child;
	else
		if(location == parent->lchild)
			parent->lchild = child;
		else
			parent->rchild = child;
	
}

void control::caseC(node *parent, node *location) {
	
	struct node *ptr, *ptrSave, *successor, *parSuc;
	
	ptrSave = location;
	ptr = location->lchild;
	
	while(ptr->lchild != NULL) {
		ptrSave = ptr;
		ptr = ptr->lchild;
	}
	
	successor = ptr;
	parSuc = ptrSave;
	
	if((successor->lchild == NULL) && successor->rchild == NULL)
		caseA(parSuc, successor);
	else
		caseB(parSuc, successor);
		
	if(parent == NULL)
		root = successor;
	else
		if(location == parent->lchild)
			parent->lchild = successor;
		else
			parent->rchild = successor;
			
	successor->lchild = location->lchild;
	successor->rchild = location->rchild;
}

void control::preorder(node *ptr) {
	
	if (root == NULL) {
		cout << "Tree is empty!";
		return;
	}
	if(ptr != NULL) {
		cout << ptr->info << "	";
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
	
}

void control::inorder(node *ptr) {
	
	if (root == NULL) {
		cout << "Tree is empty!";
		return;
	}
	if(ptr != NULL) {
		inorder(ptr->lchild);
		cout << ptr->info << "	";
		inorder(ptr->rchild);
	}
	
}

void control::postorder(node *ptr) {
	
	if (root == NULL) {
		cout << "Tree is empty!";
		return;
	}
	if(ptr != NULL) {
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		cout << ptr->info << "	";
	}
	
}

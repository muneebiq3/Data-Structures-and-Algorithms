#include "header.h"
#include <iostream>

using namespace std;

void control::find(int item, tree **parent, tree **location) {
	
    struct tree *ptr, *ptrSave;

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

void control::caseA(tree *parent, tree *location) {
	
	if(parent == NULL) {
		cout << "Item with ID " << location->info <<  " and " << location->name << " deleted from the menu." << endl;
		root = NULL;
	}
	else
		if(location == parent->lchild) {
			cout << "Item with ID " << location->info << " and " << location->name << " deleted from the menu." << endl;
			parent->lchild = NULL;
		}
			
		else  {
			cout << "Item with ID " << location->info << " and " << location->name << " deleted from the menu." << endl;
			parent->rchild = NULL;
		}
}

void control::caseB(tree *parent, tree *location) {
	
	struct tree *child = NULL;
	
	if(location->lchild != NULL)
		child = location->lchild;
	else
		child = location->rchild;
	if(parent == NULL) {
		cout << "Item with ID " << location->info << " and " << location->name << " deleted from the menu." << endl;
		root = child;
	}
	else {
		
		if(location == parent->lchild) {
			cout << "Item with ID " << location->info << " and " << location->name << " deleted from the menu." << endl;
			parent->lchild = child;
		}
			
		else {
			cout << "Item with ID " << location->info << " and " << location->name << " deleted from the menu." << endl;
			parent->rchild = child;
		}	
	}
}

void control::caseC(tree *parent, tree *location) {
	
	struct tree *ptr, *ptrSave, *successor, *parSuc;
	
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

void control::insert(int item, string name) {
	
    struct tree *temp, *parent, *location;
    
    find(item, &parent, &location);

    if (location != NULL) {
        cout << "Item already inserted in the menu!" << endl;
        return;
    }

	else {
		temp = new tree;
	    temp->info = item;
	    temp->name = name;
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

void control::del(int item) {
	
    struct tree *parent, *location;

	find(item, &parent, &location);
	
	if(location == NULL) {
	    cout << "Item not found in the menu!" << endl;
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

tree* control::search(tree *ptr, int item) {
	
    if (ptr != NULL) {
      	
        if (item < ptr->info)
            return search(ptr->lchild, item);
        else if (item > ptr->info)
            return search(ptr->rchild, item);
        else if(item == ptr->info)
        {
        	cout << "\nItem ID: " << ptr->info << endl;
        	cout << "Menu Item: " << ptr->name << endl;
        	return ptr;		
    	}
    }
    else {
        	cout << "Item not found in the menu!" << endl;
        	return NULL;
    }
}

void control::display(tree *root) {
	
	if(root != NULL) {
		cout << root->info << "	";
		display(root->lchild);
		display(root->rchild);
	}
	
}

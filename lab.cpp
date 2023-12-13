#include <iostream>
#include <conio.h>

using namespace std;

struct node {
	
	int info;
	
	struct node *lchild = NULL;
	struct node *rchild = NULL;
	
};

node *root = NULL;

void find(int item, node **parent, node **location) {
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

void caseA(node *parent, node *location) {
	
	if(parent == NULL)
		root = NULL;
	else
		if(location == parent->lchild)
			parent->lchild = NULL;
		else 
			parent->rchild = NULL;
	
}

void caseB(node *parent, node *location) {
	
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

void caseC(node *parent, node *location) {
	
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


void insert(int item) {
	
    struct node *temp, *parent, *location;
    
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
	        if(item > parent->info) {
	        	temp->info = parent->info;
	        	parent->info = item;
	        	item = temp->info;
			} 
			if (parent->lchild == NULL)
				parent->lchild = temp;
			else 
				parent->rchild = temp;
	    }
	}
}
void del(int item) {
    struct node *parent, *location;

    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return;
    }
    
    else {

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


int main() {
	
	int choice;
	
	while(1) {
		
		cout << "\n	MAX HEAP\n\n";
		cout << "\n1. Insert";
		cout << "\n2. Delete";
		cout << "\n3. Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) {
			
			case 1: {
				int item;
    			cout << "Enter the value to be inserted: "; cin >> item;
				insert(item);
				getch();
				system("cls");
				break;
			}
			
			case 2: {
				int item;
    			cout << "Enter the value to be deleted: "; cin >> item;
				del(item);
				getch();
				system("cls");
				break;
			}
			
			case 3:
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
#include <iostream>
#include <conio.h>

using namespace std;

struct node{
	
	int info;
	int balance;
	
	struct node *lchild = NULL;
	struct node *rchild = NULL;
};

node *root = NULL;

node *search(node* ptr, int item) {
	
    if (ptr != NULL) {
    	
        if (item < ptr->info)
            return search(ptr->lchild, item);
        else
            return search(ptr->rchild, item);
            
    return ptr;
	}
}

node *insert(int item, node *pivotNode, bool *ht_inc)
{
	node *Aptr, *Bptr;
	if(pivotNode == NULL) {
		
		pivotNode = new node;
		pivotNode->info = item;
		pivotNode->lchild = pivotNode->rchild = NULL;
		pivotNode->balance = 0;
		*ht_inc = true;
		return pivotNode;
    }
    
	if(item<pivotNode->info)
	{
		pivotNode->lchild = insert(item, pivotNode->lchild, ht_inc);
		
		if(*ht_inc==true) {
			
			switch(pivotNode->balance) {
				
				case -1: {
					pivotNode->balance = 0;
					*ht_inc = false;
					break;
				}
		
				case 0: {
					pivotNode->balance = 1;
					break;
				}
	
				case 1: {
					
					Aptr = pivotNode->lchild;
					if(Aptr->balance == 1) {
						
						cout << "Left to Left Rotation: " << endl;
						pivotNode->lchild = Aptr->rchild;
						Aptr->rchild = pivotNode;
						pivotNode->balance = 0;
						Aptr->balance = 0;
						pivotNode = Aptr;
						
					}
					else {
						
						cout << "Left to Right Rotation: " << endl;
						Bptr = Aptr->rchild;
						Aptr->rchild = Bptr->lchild;
						Bptr->lchild = Aptr;
						pivotNode->lchild = Bptr->rchild;
						Bptr->rchild = pivotNode;
						
						if(Bptr->balance == 1)
							pivotNode->balance = -1;
						else
							pivotNode->balance = 0;
							
						if(Bptr->balance == -1)
							Aptr->balance = 1;
						else
							Aptr->balance = 0;
							
						Bptr->balance = 0;
						pivotNode = Bptr;
					}
					*ht_inc = false;	
					break;
				}
			}
		}
   }
   
    if(item > pivotNode->info) {
   	
		pivotNode->rchild = insert(item, pivotNode->rchild, ht_inc);
		
		if(*ht_inc == true)
	   	{
	   	 	switch(pivotNode->balance)
	   	 	{
	   	 		case 1: {
	   	 			pivotNode->balance = 0;
					*ht_inc = false;
					break;
				}
	   	 		
				case 0: {
					pivotNode->balance = -1;
					break;
				}
	
				case -1: {
					
					Aptr = pivotNode->rchild;
					if(Aptr->balance == -1) {
						
					   cout << "Right to Right Rotation: " << endl;
					   pivotNode->rchild = Aptr->lchild;
					   Aptr->lchild = pivotNode;
					   pivotNode->balance = 0;
					   Aptr->balance = 0;
					   pivotNode = Aptr;
					  	
				    }
					else {
					    cout << "Right to Left Rotation: " << endl;
						Bptr = Aptr->lchild;
						Aptr->lchild = Bptr->rchild;
						Bptr->rchild = Aptr;
						pivotNode->rchild = Bptr->lchild;
						Bptr->lchild = pivotNode;
						if(Bptr->balance == -1)
							pivotNode->balance = 1;
						else
							pivotNode->balance = 0;
							
						if(Bptr->balance == 1)
							Aptr->balance = -1;
						else
							Aptr->balance = 0;
							
						Bptr->balance = 0;
						pivotNode = Bptr;
						
					}
					*ht_inc = false;
					break;
				}		
			}
		}
		return pivotNode;
   } 
}

void display(node* ptr, int level) {
	
    if (ptr != NULL) {
    	
        display(ptr->rchild, level + 1);
        cout << endl;
        
        for(int i = 0; i < level; i++) 
        	cout << "	";
        	
        cout << ptr->info;
        display(ptr->lchild, level + 1);
        
    }
}

void inorder(node *ptr) {
	
	inorder(ptr->lchild);
	cout << ptr->info << "	";
	inorder(ptr->rchild);
	
}

int main() {
	
    bool ht_inc;
    int choice;
    
    while(1) {
    	
    	cout << "\n AVL Tree\n";
    	cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Quit" << endl << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
        	
        	case 1: {
        		
        		int item;
        		cout << "Enter the value to be inserted: ";
                cin >> item;
                
                if(search(root, item) == NULL)
                	root = insert(item, root, &ht_inc);
                else
                	cout << "Item already inserted in Tree!";
                	
                getch();
                system("cls");
				break;
				
			}
			
			case 2: {
				if(root == NULL) {
					
					cout << "Tree is empty!" << endl;
					continue;
					
				}
				
				cout << "Tree Information: " << endl;
				display(root, 1);
				
				cout << "\n\n";
				cout << "Inorder Traversal: " << endl;
				inorder(root);
				cout << "\n";
				
				getch();
				system("cls");
				break;
				
			}
			
			case 3 : {
				exit(0);
				break;
			}
			
			default : {
				cout << "Wrong Choice!";
				getch();
				system("cls");
			}
		}
	}

    return 0;
}

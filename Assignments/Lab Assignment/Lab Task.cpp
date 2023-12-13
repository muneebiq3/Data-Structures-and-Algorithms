#include <iostream>
#include <conio.h>
#include <queue>

using namespace std;

struct node {
	
	int info;
	
	struct node *lchild;
	struct node *rchild;
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
	
	if(parent == NULL) {
		cout << "Root with value " << location->info <<  " deleted from the tree." << endl;
		root = NULL;
	}
	else
		if(location == parent->lchild) {
			cout << "Node with value " << location->info <<  " rooted at " << root->info << " deleted from the tree." << endl;
			parent->lchild = NULL;
		}
			
		else  {
			cout << "Node with value " << location->info <<  " rooted at " << root->info << " deleted from the tree." << endl;
			parent->rchild = NULL;
		}
}

void caseB(node *parent, node *location) {
	
	struct node *child = NULL;
	
	if(location->lchild != NULL)
		child = location->lchild;
	else
		child = location->rchild;
	if(parent == NULL) {
		cout << "Root with value " << location->info <<  " deleted from the tree." << endl;
		root = child;
	}
	else {
		
		if(location == parent->lchild) {
			cout << "Node with value " << location->info <<  " rooted at " << root->info << " deleted from the tree." << endl;
			parent->lchild = child;
		}
			
		else {
			cout << "Node with value " << location->info <<  " rooted at " << root->info << " deleted from the tree." << endl;
			parent->rchild = child;
		}	
	}
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

node *minValue (node *root) {
	
	while(root != NULL && root->lchild != NULL)
		root = root->lchild;
	return root;
	
}


node *maxValue(node *root) {
	
    while (root != NULL && root->rchild != NULL)
        root = root->rchild;
    return root;
    
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
	        if (item < parent->info)
	            parent->lchild = temp;
	        else
	            parent->rchild = temp;
	    }
	}
}

void del(int item) {
	
    struct node *parent, *location;

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

void inorder(node *root) {
	
	if(root != NULL) {
		inorder(root->lchild);
		cout << root->info << "	";
		inorder(root->rchild);
	}	
}

void preorder(node *root) {
	
	if(root != NULL) {
		cout << root->info << "	";
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void postorder(node *root) {
	
	if(root != NULL) {
		postorder(root->lchild);
		postorder(root->rchild);
		cout << root->info << "	";
	}
}

int depth(node *root) {
	
	if(root == NULL)
		return 0;

	int leftDepth = depth(root->lchild);
	int rightDepth = depth(root->rchild);
		
	if(rightDepth > leftDepth)
		return rightDepth + 1;
	if(rightDepth == leftDepth)
		return leftDepth + 1;
	else
		return leftDepth + 1;
		
}

bool terminalNodes(node *root) {
	
	bool found = false;
	
	if(root == NULL)
		return found;
    
    if(root->lchild == NULL && root->rchild == NULL) {
    	cout << root->info << "	";
    	found = true;
	}
    	
	terminalNodes(root->lchild);
	terminalNodes(root->rchild);
	
	return found;
	
}

node *inorderSuccessor(node *root, node *target) {
	
	struct node *temp, *parent, *location = NULL;
 
    find(target->info, &parent, &location);
    	
    if (target->rchild != NULL) 
    	return minValue(target->rchild);
    
    temp = parent;
    while (temp != NULL && location == temp->rchild) {
    	
		location = temp;
		find(temp->info, &parent, &location);
		
	}
	
	return parent;
	
}

node *preorderSuccessor(node *root, node *target) {
	
    node *parent, *location, *temp = NULL;

    if(target->lchild != NULL)
    	return target->lchild;
    	
    if(target->rchild != NULL)
    	return target->rchild;
    
    temp = target;
    
    while(temp != root && (parent == NULL || parent->rchild == target)) {
    	
    	find(temp->info, &parent, &location);
    	temp = parent;
    	
	}
	
	if(temp == root)
		return NULL;

	return parent->rchild; 

}

node *postorderSuccessor(node *root, node *target) {
	
	node *parent, *location, *temp = NULL;

    find(target->info, &parent, &location);
    
    if (target == root)
    	return NULL;
    	
    if(parent->rchild == NULL || parent->rchild == target)
    	return parent;
    	
    temp = parent->rchild;
    while(temp->lchild != NULL)
    	temp = temp->lchild;
    	
    return temp;
    
}

node *inorderPredecessor(node *root, node *target) {
	
	node *parent, *location, *temp = NULL;
	
    find(target->info, &parent, &location);

    if (target->lchild != NULL) 
        return maxValue(target->lchild);

    temp = parent;
    
    while (temp != NULL && location == temp->lchild) {
    	
        location = temp;
        find(temp->info, &parent, &location);
        
    }
    
    if(temp == NULL || location == root->lchild)
    	return NULL;
    
    return parent;
}

node *preorderPredecessor(node *root, node *target) {
	
	node *parent, *location, *temp = NULL;
	
    find(target->info, &parent, &location);
    
    if(location == root)
    	return NULL;
    	
    if(parent->lchild == NULL || parent->lchild == target)
    	return parent;
    	
    temp = parent->lchild;
    
    while(temp->rchild != NULL)
    	temp = temp->rchild;
    	
    return temp;
	
}

node *postorderPredecessor(node *root, node *target) {
	
	node *parent, *location, *temp = NULL;
	
	find(target->info, &parent, &location);
	
	if(target->rchild)
		return target->rchild;
		
	temp = target;
	
	while(temp != root && (parent == NULL || parent->lchild == target)) {
		
		find(temp->info, &parent, &location);
		temp = parent;
		
	}
	
	if(temp == root)
		return NULL;
		
	return parent->lchild;
}

bool twoChildrenNodes(node *root) {
	
	bool found = false;
	
	if(root == NULL)
		return found;
	
    if(root->lchild != NULL && root->rchild != NULL) {
    	cout << root->info << "	";
    	found = true;
	}
    	
	twoChildrenNodes(root->lchild);
	twoChildrenNodes(root->rchild);
	
	return found;
	
}

bool oneChildNodes(node *root) {
	
	bool found = false;
	
	if(root == NULL) 
		return found;
	  
    if((root->lchild == NULL && root->rchild != NULL) || 
	(root->lchild != NULL && root->rchild == NULL)) {
		cout << root->info << "	";
		found = true;
	}
	    	
	oneChildNodes(root->lchild);
	oneChildNodes(root->rchild);
	
	return found;
	
}

void nodePosition(node *root, int item) {
	
    if (root->info == item) {
        cout << "Your requested node " << item << " is the root of the tree." << endl;
        return;
    }

    if (root->lchild != NULL && root->lchild->info == item) {
        cout << "Your requested node " << item << " is the left child of its parent node " << root->info << "." << endl;
        return;
    }

    if (root->rchild != NULL && root->rchild->info == item) {
        cout << "Your requested node " << item << " is the right child of its parent node " << root->info << "." << endl;
        return;
    }
    if (root->lchild != NULL) 
        nodePosition(root->lchild, item);
    if (root->rchild != NULL) 
        nodePosition(root->rchild, item);
    if (root->lchild == NULL && root->rchild == NULL) 
        cout << "Your requested node " << item << " is not found in the subtree rooted at " << root->info << "." << endl;

}

void levelOrderTraversal(node *root) {

	queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()) {
		
		node *node = q.front();
		q.pop();
		
		if(node != NULL) {
			
			cout << node->info << "	";
			
			if(node->lchild != NULL)
				q.push(node->lchild);
			if(node->rchild != NULL)
				q.push(node->rchild);
		}
		else if(q.empty() != NULL) 
			q.push(NULL);
					
	}
}

int numberOfNodes(node *root) {
	
	if (root == NULL)
		return 0;

	return 1 + numberOfNodes(root->lchild) + numberOfNodes(root->rchild);
	
}

int evenValuedNodes(node *root, int counter) {
	
	if(root == NULL)
		return counter;
	
	if(root->info %2 == 0)
		counter ++;
		
	counter = evenValuedNodes(root->lchild, counter);
	counter = evenValuedNodes(root->rchild, counter);
	
	return counter;
	
}

int nodeLevel(node *root, int value, int level) {
	
	if (root == NULL)
		return -1;

    if (root->info == value) 
        return level;

    int leftLevel = nodeLevel(root->lchild, value, level + 1);
    int rightLevel = nodeLevel(root->rchild, value, level + 1);

    if (leftLevel != -1) 
        return leftLevel;
    if (rightLevel != -1) 
        return rightLevel; 
        
    return -1;
    
}

int main() {
	
	int choice;
	
	while(1) {
		
		cout << "\n 1. Insert";
		cout << "\n 2. Delete";
		cout << "\n 3. Inorder";
		cout << "\n 4. Preorder";
		cout << "\n 5. Postorder";
		cout << "\n 6. Depth";
		cout << "\n 7. Terminal Nodes";
		cout << "\n 8. Inorder Successor";
		cout << "\n 9. Preorder Successor";
		cout << "\n10. Postorder Successor";
		cout << "\n11. Inorder Predecessor";
		cout << "\n12. Preorder Predecessor";
		cout << "\n13. Postorder Predecessor";
		cout << "\n14. Two Children Nodes";
		cout << "\n15. One Child Nodes";
		cout << "\n16. Position of node";
		cout << "\n17. Level Order Traversal";
		cout << "\n18. Total Nodes";
		cout << "\n19. Even Valued Nodes";
		cout << "\n20. Level of node";
		cout << "\n21. Quit" << endl << endl;
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
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				int item;
    			cout << "Enter the value to be deleted: "; cin >> item;
				del(item);
				getch();
				system("cls");
				break;
			}
				
			case 3: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				inorder(root);
				getch();
				system("cls");
				break;
			}
		
			case 4: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				preorder(root);
				getch();
				system("cls");
				break;
			}
			
			case 5: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				postorder(root);
				getch();
				system("cls");
				break;
			}
			
			case 6: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				int depthResult = depth(root);
				cout << "The current tree is " << depthResult << "-level deep." << endl;
				getch();
				system("cls");
				break;
			}
			
			case 7: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				bool result = terminalNodes(root);
				getch();
				system("cls");
				break;
			}
						
			case 8: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				node *parent, *location; 
				int item;
				
				cout << "Enter the node value to find its inorder successor: "; cin >> item;
				
				find(item, &parent, &location);
				
				if(location == NULL) {
					
					cout << "Node not found in Tree!" << endl;
					getch();
					system("cls");
					break;
					
				}
				
				else {
					
					node *successor = inorderSuccessor(root, location);
					
					if(successor != NULL)
						cout << "The Inorder Successor of node with value " << item << " : " << successor->info;
					else 
						cout << "No Inorder Successor of node with value " << item << " found!";
				}

				getch();
				system("cls");
				break;
			}
			
			case 9: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				node *parent, *location; 
				int item;
				
				cout << "Enter the node value to find its preorder successor: "; cin >> item;
				
				find(item, &parent, &location);
				
				if(location == NULL) {
					
					cout << "Node not found in Tree!" << endl;
					getch();
					system("cls");
					break;
					
				}
				
				else {
					
					node *successor = preorderSuccessor(root, location);
					
					if(successor != NULL)
						cout << "The Preorder Successor of node with value " << item << " : " << successor->info;
					else 
						cout << "No Preorder Successor of node with value " << item << " found!";
				}

				getch();
				system("cls");
				break;
			}
			
			case 10: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				node *parent, *location; 
				int item;
				
				cout << "Enter the node value to find its postorder successor: "; cin >> item;
				
				find(item, &parent, &location);
				
				if(location == NULL) {
					
					cout << "Node not found in Tree!" << endl;
					getch();
					system("cls");
					break;
					
				}
				
				else {
					
					node *successor = postorderSuccessor(root, location);
					
					if(successor != NULL)
						cout << "The Postorder Successor of node with value " << item << " : " << successor->info;
					else 
						cout << "No Postorder Successor of node with value " << item << " found!";
				}

				getch();
				system("cls");
				break;
			}
			
			case 11: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				node *parent, *location; 
				int item;
				
				cout << "Enter the node value to find its inorder predecessor: "; cin >> item;
				
				find(item, &parent, &location);
				
				if(location == NULL) {
					
					cout << "Node not found in Tree!" << endl;
					getch();
					system("cls");
					break;
					
				}
				
				else {
					
					node *predecessor = inorderPredecessor(root, location);
					
					if(predecessor != NULL)
						cout << "The Inorder Predecessor of node with value " << item << " : " << predecessor->info;
					else 
						cout << "No Inorder Predecessor of node with value " << item << " found!";
					
				}
				
				getch();
				system("cls");
				break;
			}
			
			case 12: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				node *parent, *location; 
				int item;
				
				cout << "Enter the node value to find its preorder predecessor: "; cin >> item;
				
				find(item, &parent, &location);
				
				if(location == NULL) {
					
					cout << "Node not found in Tree!" << endl;
					getch();
					system("cls");
					break;
					
				}
				
				else {
					
					node *predecessor = preorderPredecessor(root, location);
					
					if(predecessor != NULL)
						cout << "The Preorder Predecessor of node with value " << item << " : " << predecessor->info;
					else 
						cout << "No Preorder Predecessor of node with value " << item << " found!";
					
				}
				
				getch();
				system("cls");
				break;
			}
			
			case 13: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				node *parent, *location; 
				int item;
				
				cout << "Enter the node value to find its postorder predecessor: "; cin >> item;
				
				find(item, &parent, &location);
				
				if(location == NULL) {
					
					cout << "Node not found in Tree!" << endl;
					getch();
					system("cls");
					break;
					
				}
				
				else {
					
					node *predecessor = postorderPredecessor(root, location);
					
					if(predecessor != NULL)
						cout << "The Postorder Predecessor of node with value " << item << " : " << predecessor->info;
					else 
						cout << "No Postorder Predecessor of node with value " << item << " found!";
					
				}
				
				getch();
				system("cls");
				break;
			}

			case 14: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				bool result = twoChildrenNodes(root);
				if(result == false)
					cout << "No node with two children found!" << endl;
					
				getch();
				system("cls");
				break;
			}
			
			case 15: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				bool result = oneChildNodes(root);
				if(result == false)
					cout << "No node with one child found!" << endl;
				
				getch();
				system("cls");
				break;
			}
			
			case 16: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				int item;
				cout << "Enter the node value to find its position: "; cin >> item;
				nodePosition(root, item);
				getch();
				system("cls");
				break;
			}
			
			case 17: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				levelOrderTraversal(root);
				getch();
				system("cls");
				break;
			}
			
			case 18: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				int numberOfNodesResult = numberOfNodes(root);
				cout << "There is a total of " << numberOfNodesResult << " node(s) present in the current BST." << endl;
				getch();
				system("cls");
				break;
			}
			
			case 19: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				int evenValuedNodesResult =  evenValuedNodes(root, 0);
				cout << "There is a total of " << evenValuedNodesResult << " even-valued node(s) present in the current BST." << endl;
				getch();
				system("cls");
				break;
			}
			
			case 20: {
				
				if(root == NULL) {
					cout << "Tree is empty!" << endl;
					getch();
					system("cls");
					break;
				}
				
				int item, nodeLevelResult;
				cout << "Enter the node value to find its level: "; cin >> item;
				nodeLevelResult = nodeLevel(root, item, 0);
				if(nodeLevelResult != -1)
					cout << "Your node value " << item << " is found at level " << nodeLevelResult << "." << endl;
				else
					cout << "Your node value " << item << " doesn't exist in the tree." << endl;
				getch();
				system("cls");
				break;
			}
			
			case 21:
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

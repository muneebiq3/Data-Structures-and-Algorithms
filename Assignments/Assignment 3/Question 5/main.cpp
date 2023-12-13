#include "header.h"
#include <conio.h>
#include <iostream>

using namespace std;

int main() {
	
	int choice;
	control list;
	
	while(1) {
		
		cout << "\nHuffman Tree\n";
		cout << "\n1. Insert";
		cout << "\n2. Display";
		cout << "\n3. Build Tree";
		cout << "\n4. Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) {
			
			case 1: {
				
				int item;
    			cout << "Enter the value to be inserted: ";
    			cin >> item;
    			
    			struct queue *temp = new struct queue;

				temp->root = new struct tree;
			
			    temp->root->info = item;
			    temp->link = NULL;
				
				list.populateQueue(temp->root);
				list.swap();
				
				getch();
				system("cls");
				break;
				
			} case 2: {
				
				list.display();
				
				getch();
				system("cls");
				break;
				
			} case 3: {
				
				if (list.front == NULL){
			    	cout << "Tree is empty!" << endl;
			    	getch();
					system("cls");
					break;
		    	
				} if(list.front->link == NULL) {
					cout << "Tree is already built!" << endl;
					getch();
					system("cls");
					break;
				}

				int traversal = 1;
				cout << endl;
				while (list.front != NULL && list.front->link != NULL) {
					
					cout << "Huffman Tree structure after " << traversal << " traversal: " << endl;
					list.buildTree();
					traversal++;
				}
				
				getch();
				system("cls");
				break;
				
			} case 4:
				exit(0);
				
			default: {
				cout << "Wrong Choice!";
				getch();
				system("cls");
			}
		}
	}
}


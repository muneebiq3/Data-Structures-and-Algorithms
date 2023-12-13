#include "header.h"
#include <conio.h>
#include <iostream>

using namespace std;

int main() {
	
	control list;
	int choice;
	
	while(1) {
		
		cout << "\nBinary Search Tree\n";
		cout << "\n1. Insert";
		cout << "\n2. Search";
		cout << "\n3. Delete";
		cout << "\n4. Display";
		cout << "\n5. Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) {
			
			case 1: {
				
				int item;
				string name;
    
    			cout << "Enter the Food item to be added: "; cin >> name;
    			cout << "Assign same item an ID: "; cin >> item;
    			
				list.insert(item, name);
				
				getch();
				system("cls");
				break;
			}
			
			case 2: {
				
				if(list.root == NULL) {
					
					cout << "Tree is empty!" << endl;
					
					getch();
					system("cls");
					break;
				}
				
				int item;
                cout << "Enter the ID to be searched: ";
                cin >> item;
                
                list.search(list.root,item);
                
				getch();
				system("cls");
				break;
			}
			
			case 3: {
				
				if(list.root == NULL) {
					
					cout << "Tree is empty!" << endl;
					
					getch();
					system("cls");
					break;
				}
				
				int item;
    			cout << "Enter the ID of the menu item to be deleted: "; cin >> item;
    			
				list.del(item);
				
				getch();
				system("cls");
				break;
			}
			
			case 4: {
				
				if(list.root == NULL) {
					
					cout << "Tree is empty!" << endl;
					
					getch();
					system("cls");
					break;
				}
    			
				list.display(list.root);
				
				getch();
				system("cls");
				break;
			}

			case 5:
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

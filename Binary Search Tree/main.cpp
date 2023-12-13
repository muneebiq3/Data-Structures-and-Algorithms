#include "header.h"
#include <conio.h>
#include <iostream>

using namespace std;

int main() {
	
	control list;
	int choice;
	
	while(1) {
		
		cout << "\n1. Insert";
		cout << "\n2. Delete";
		cout << "\n3. Preorder Traversal";
		cout << "\n4. Inorder Traversal";
		cout << "\n5. Postorder Traversal";
		cout << "\n6. Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) {
			
			case 1:{
				list.insert();
				getch();
				system("cls");
				break;
			}
			
			case 2:{
				list.del();
				getch();
				system("cls");
				break;
			}
						
			case 3:{
				list.preorder(list.root);
				getch();
				system("cls");
				break;
			}
			
			case 4:{
				list.inorder(list.root);
				getch();
				system("cls");
				break;
			}

			case 5:{
				list.postorder(list.root);
				getch();
				system("cls");
				break;
			}
			
			case 6:
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

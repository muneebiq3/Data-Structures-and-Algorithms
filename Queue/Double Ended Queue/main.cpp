#include <iostream>
#include <conio.h>
#include "header.h"

using namespace std;

int main() {
	
	control list;
	int choice;
	while (1) {
		
		cout << "\n1. Insert Right\n2. Insert Left\n3. Delete Left\n4. Delete Right\n5. Display";
		cout <<"\n\nEnter your choice: "; cin >> choice;
		
		switch (choice) {
			case 1:
				list.insertRight();
				getch();
				system("cls");
				break;
			
			case 2:
				list.insertLeft();
				getch();
				system("cls");
				break;
			
			case 3:
				list.deleteLeft();
				getch();
				system("cls");
				break;
				
			case 4:
				list.deleteRight();
				getch();
				system("cls");
				break;
			
			case 5:
				list.display();
				getch();
				system("cls");
				break;
			
			default:
				cout << "Invalid Choice!";
				getch();
				system("cls");
		}
	}
	
	return 0;
	
}

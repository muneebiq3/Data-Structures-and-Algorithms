#include <iostream>
#include <conio.h>
#include "header.h"

using namespace std;

int main() {
	
	int choice;
	control list;
	char source;
		
	list.insert_node('0');
	list.insert_node('1');
	list.insert_node('2');
	list.insert_node('3');
	list.insert_node('4');
	list.insert_node('5');
	list.insert_node('6');
	list.insert_node('7');
	list.insert_node('8');

	list.insert_edge('0', '1', 4);
	list.insert_edge('0', '7', 8);
	list.insert_edge('1', '2', 8);
	list.insert_edge('1', '7', 11);
	list.insert_edge('2', '3', 7);
	list.insert_edge('2', '5', 4);
	list.insert_edge('2', '8', 2);
	list.insert_edge('3', '4', 9);
	list.insert_edge('3', '5', 14);
	list.insert_edge('4', '5', 10);
	list.insert_edge('5', '6', 2);
	list.insert_edge('6', '8', 6);
	list.insert_edge('6', '7', 1);
	list.insert_edge('7', '8', 7);
	
	while(1) {
		
		cout << "\nPrims Algorithm\n";
		cout << "\n1. Display Adjacency List";
		cout << "\n2. Prims Algorithm";
		cout << "\n3. Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) {
			
			case 1: {
		
				list.display();
				getch();
				system("cls");
				break;
				
			} case 2: {
				
				list.find_path('0');
				
				list.traverse_path('0', '1');
				list.traverse_path('0', '2');
				list.traverse_path('0', '3');
				list.traverse_path('0', '4');
				list.traverse_path('0', '5');
				list.traverse_path('0', '6');
				list.traverse_path('0', '7');
				list.traverse_path('0', '8');
				
				list.displayQ();
				
				getch();
				system("cls");
				break;
			
			} case 3:
				exit(0);
				
			default: {
				cout << "Wrong Choice!";
				getch();
				system("cls");
			}
		}
	}
}
